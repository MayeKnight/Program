import cv2
import numpy as np
import math
import heapq
import os
import csv
from datetime import datetime
from ultralytics import YOLO

# ---------- 1. A* 算法 ----------
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def get_neighbors(node, grid_shape):
    x, y = node
    neighbors = []
    for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < grid_shape[0] and 0 <= ny < grid_shape[1]:
            neighbors.append((nx, ny))
    return neighbors

def astar(start, goal, obstacle_set, grid_shape):
    open_set = []
    heapq.heappush(open_set, (0, start))
    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic(start, goal)}

    while open_set:
        _, current = heapq.heappop(open_set)
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path
        for neighbor in get_neighbors(current, grid_shape):
            if neighbor in obstacle_set:
                continue
            tentative_g = g_score[current] + 1
            if neighbor not in g_score or tentative_g < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f_score[neighbor] = tentative_g + heuristic(neighbor, goal)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))
    return None


# ---------- 2. 细胞世界管理类（允许重叠1/4，带路径保存）----------
class CellWorld:
    def __init__(self, image_path, model_path, conf_threshold=0.5, 
                 allowed_overlap_ratio=0.75, grid_cell_size_ratio=0.3):
        self.img = cv2.imread(image_path)
        if self.img is None:
            raise FileNotFoundError(f"无法读取图像: {image_path}")
        self.height, self.width = self.img.shape[:2]
        self.allowed_overlap_ratio = allowed_overlap_ratio

        # 使用 YOLO 检测所有细胞
        model = YOLO(model_path)
        results = model(image_path, conf=conf_threshold)[0]

        # 细胞列表: 每个元素 [x_center, y_center, radius]
        self.cells = []
        for box in results.boxes:
            x1, y1, x2, y2 = box.xyxy[0].tolist()
            cx = (x1 + x2) / 2
            cy = (y1 + y2) / 2
            w = x2 - x1
            h = y2 - y1
            radius = max(w, h) / 2
            self.cells.append([cx, cy, radius])

        if len(self.cells) == 0:
            raise ValueError("模型未检测到任何细胞，请检查图像或模型")

        self.active_idx = None          # 当前选中的细胞索引
        self.target_path = []           # 待移动的路径点（像素坐标）
        self.path_index = 0
        self.dragging = False

        # 栅格地图参数
        min_radius = min(c[2] for c in self.cells)
        self.grid_cell_size = max(1, int(min_radius * grid_cell_size_ratio))
        self.grid_width = self.width // self.grid_cell_size
        self.grid_height = self.height // self.grid_cell_size
        print(f"栅格地图大小: {self.grid_width} x {self.grid_height}, 栅格边长={self.grid_cell_size}px")

        # ---------- 路径保存相关 ----------
        self.save_dir = "planned_paths"
        os.makedirs(self.save_dir, exist_ok=True)
        self.move_counter = 0           # 全局移动顺序计数器（所有细胞合计）

    def plan_path_for_cell(self, cell_idx, target_px):
        """为第 cell_idx 个细胞规划到 target_px 的无碰撞路径"""
        if cell_idx is None:
            return []
        cx, cy, r = self.cells[cell_idx]
        start_px = (cx, cy)
        goal_px = target_px

        start_grid = self.pixel_to_grid(*start_px)
        goal_grid = self.pixel_to_grid(*goal_px)

        obstacle_grids = set()
        for i, (ox, oy, or_) in enumerate(self.cells):
            if i == cell_idx:
                continue
            # 允许重叠半径之和的 allowed_overlap_ratio
            expand_radius = (r + or_) * self.allowed_overlap_ratio
            rad_grid = int(math.ceil(expand_radius / self.grid_cell_size))
            center_grid = self.pixel_to_grid(ox, oy)
            for dr in range(-rad_grid, rad_grid+1):
                for dc in range(-rad_grid, rad_grid+1):
                    nr = center_grid[0] + dr
                    nc = center_grid[1] + dc
                    if 0 <= nr < self.grid_height and 0 <= nc < self.grid_width:
                        px, py = self.grid_to_pixel((nr, nc))
                        if math.hypot(px - ox, py - oy) <= expand_radius:
                            obstacle_grids.add((nr, nc))

        obstacle_grids.discard(start_grid)
        obstacle_grids.discard(goal_grid)

        path_grid = astar(start_grid, goal_grid, obstacle_grids, (self.grid_height, self.grid_width))
        if not path_grid:
            return []
        return [self.grid_to_pixel(p) for p in path_grid]

    def check_collision_with_others(self, cell_idx, new_center_px):
        """检查移动到新圆心时是否与其他细胞发生不允许的重叠"""
        _, _, r = self.cells[cell_idx]
        for i, (ox, oy, or_) in enumerate(self.cells):
            if i == cell_idx:
                continue
            dist = math.hypot(new_center_px[0] - ox, new_center_px[1] - oy)
            if dist < (r + or_) * self.allowed_overlap_ratio:
                return True
        return False

    def move_cell_along_path(self):
        if self.active_idx is None or not self.target_path:
            return False
        if self.path_index >= len(self.target_path):
            self.target_path = []
            return False
        next_pos = self.target_path[self.path_index]
        if not self.check_collision_with_others(self.active_idx, next_pos):
            self.cells[self.active_idx][0] = next_pos[0]
            self.cells[self.active_idx][1] = next_pos[1]
            self.path_index += 1
            return True
        else:
            self.target_path = []
            return False

    def pixel_to_grid(self, px, py):
        gx = int(px // self.grid_cell_size)
        gy = int(py // self.grid_cell_size)
        return (gy, gx)

    def grid_to_pixel(self, grid_pos):
        row, col = grid_pos
        x = col * self.grid_cell_size + self.grid_cell_size // 2
        y = row * self.grid_cell_size + self.grid_cell_size // 2
        return (x, y)

    def set_active_cell(self, idx):
        self.active_idx = idx
        self.target_path = []
        self.path_index = 0
        self.dragging = False

    def start_drag(self, x, y):
        if self.active_idx is None:
            return False
        cx, cy, r = self.cells[self.active_idx]
        if math.hypot(x - cx, y - cy) <= r:
            self.dragging = True
            return True
        return False

    def drag_to(self, x, y):
        if not self.dragging or self.active_idx is None:
            return
        self.target_path = self.plan_path_for_cell(self.active_idx, (x, y))
        self.path_index = 0

    def end_drag(self, x, y):
        if not self.dragging or self.active_idx is None:
            return
        self.dragging = False
        path = self.plan_path_for_cell(self.active_idx, (x, y))
        self.target_path = path
        self.path_index = 0

        # ---------- 保存路径（如果有有效路径） ----------
        if path and len(path) > 1:   # 至少包含起点和终点
            self.save_path_to_csv(path, self.active_idx)

    def save_path_to_csv(self, path_px, cell_idx):
        """将像素路径保存到 CSV 文件，文件名含移动序号、细胞索引、时间戳"""
        self.move_counter += 1
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = f"move_{self.move_counter:03d}_cell_{cell_idx}_{timestamp}.csv"
        filepath = os.path.join(self.save_dir, filename)

        with open(filepath, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['step', 'x_pixel', 'y_pixel'])
            for step, (px, py) in enumerate(path_px):
                writer.writerow([step, int(px), int(py)])
        print(f"[保存路径] {filepath} (细胞 {cell_idx}, 移动顺序 #{self.move_counter})")

    def draw(self, img_draw):
        # 绘制非活动细胞（灰色）
        for i, (cx, cy, r) in enumerate(self.cells):
            if i == self.active_idx:
                continue
            cv2.circle(img_draw, (int(cx), int(cy)), int(r), (128, 128, 128), -1)
            cv2.circle(img_draw, (int(cx), int(cy)), int(r), (0, 0, 0), 2)
        # 绘制活动细胞（绿色）
        if self.active_idx is not None:
            cx, cy, r = self.cells[self.active_idx]
            cv2.circle(img_draw, (int(cx), int(cy)), int(r), (0, 255, 0), -1)
            cv2.circle(img_draw, (int(cx), int(cy)), int(r), (0, 0, 0), 2)
        # 绘制路径（蓝色）
        if self.target_path:
            for (px, py) in self.target_path:
                cv2.circle(img_draw, (int(px), int(py)), 2, (255, 0, 0), -1)
            for i in range(len(self.target_path)-1):
                cv2.line(img_draw, self.target_path[i], self.target_path[i+1], (255, 0, 0), 2)

        cv2.putText(img_draw, "Click cell -> Drag to move (A* with 1/4 overlap allowed)", 
                    (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255,255,255), 1)
        cv2.putText(img_draw, "Paths auto-saved in 'planned_paths/' | Press 'r' reset, 'c' clear, ESC exit", 
                    (10, 55), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255,255,255), 1)


# ---------- 3. 主程序 ----------
def main():
    # ==== 用户修改 ====
    image_path = r"D:\Tech\Code\Program\yolov8\ultralytics-main\program\labelimg_base\pbc_improve\images\test\BA_116477_jpg.rf.e6e8ccad20914d9164dbba1ffdf7732d.jpg"   # 替换
    model_path = r"D:\Tech\Code\Program\runs\detect\train13\weights\best.pt"              # 替换

    try:
        world = CellWorld(image_path, model_path, 
                         conf_threshold=0.5, 
                         allowed_overlap_ratio=0.75,
                         grid_cell_size_ratio=0.3)
    except Exception as e:
        print(f"初始化失败: {e}")
        return

    world.active_idx = None
    select_mode = True

    cv2.namedWindow("Cell Separation with Path Saving")

    def mouse_callback(event, x, y, flags, param):
        nonlocal select_mode
        if event == cv2.EVENT_LBUTTONDOWN:
            if select_mode:
                for i, (cx, cy, r) in enumerate(world.cells):
                    if math.hypot(x - cx, y - cy) <= r:
                        world.set_active_cell(i)
                        select_mode = False
                        print(f"已选中细胞 {i}")
                        break
                else:
                    print("未点中任何细胞")
            else:
                if not world.start_drag(x, y):
                    # 未点中活动细胞 -> 取消选中
                    world.active_idx = None
                    select_mode = True
                    world.target_path = []
                    print("取消选中")
                else:
                    print("开始拖拽移动")
        elif event == cv2.EVENT_MOUSEMOVE:
            if not select_mode and world.dragging:
                world.drag_to(x, y)
        elif event == cv2.EVENT_LBUTTONUP:
            if not select_mode and world.dragging:
                world.end_drag(x, y)
                print("路径规划完成并已保存（如有有效路径）")

    cv2.setMouseCallback("Cell Separation with Path Saving", mouse_callback)

    while True:
        if not select_mode and world.active_idx is not None:
            world.move_cell_along_path()

        display = world.img.copy()
        world.draw(display)
        cv2.imshow("Cell Separation with Path Saving", display)

        key = cv2.waitKey(30) & 0xFF
        if key == 27:          # ESC
            break
        elif key == ord('r'):
            # 重置所有细胞到初始位置（需要重新加载）
            world = CellWorld(image_path, model_path, conf_threshold=0.5, 
                              allowed_overlap_ratio=0.75, grid_cell_size_ratio=0.3)
            select_mode = True
            print("重置完成")
        elif key == ord('c'):
            world.active_idx = None
            select_mode = True
            world.target_path = []
            print("清除选中")

    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()