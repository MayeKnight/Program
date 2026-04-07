import cv2
import numpy as np
import math
import heapq
import pandas as pd   # 若你的 result.csv 是 pandas 格式
from ultralytics import YOLO   # 如果你直接用 YOLO 模型预测

# ---------- A* 算法 ----------
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def get_neighbors(node, grid_shape):
    neighbors = []
    x, y = node
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

# ---------- 细胞世界（基于真实图像和YOLO检测结果）----------
class RealCellWorld:
    def __init__(self, image_path, cells_info, safe_margin=5):
        """
        image_path: 显微镜图像路径
        cells_info: 列表，每个元素为 (x_center, y_center, radius) 像素坐标和半径
        safe_margin: 安全间隙（像素）
        """
        self.img_original = cv2.imread(image_path)
        if self.img_original is None:
            raise ValueError(f"无法读取图像: {image_path}")
        self.height, self.width = self.img_original.shape[:2]
        self.safe_margin = safe_margin

        # 解析细胞信息
        self.obstacles = []      # 障碍物细胞 (x, y, radius)
        self.target = None       # 目标细胞 (x, y, radius)
        self.target_radius = None

        # 暂时将所有细胞作为障碍物，后面再指定目标
        for (x, y, r) in cells_info:
            self.obstacles.append((x, y, r))

        # 栅格参数：栅格边长设为最小细胞半径的1/3（保证精度）
        min_r = min([r for (_,_,r) in cells_info]) if cells_info else 10
        self.grid_cell_size = max(1, int(min_r // 3))
        self.grid_width = self.width // self.grid_cell_size
        self.grid_height = self.height // self.grid_cell_size

        self.dragging = False
        self.path = []          # 路径点（像素坐标列表）
        self.path_index = 0

        # 用于显示的图像（会绘制细胞和路径）
        self.display_img = self.img_original.copy()

    def set_target(self, idx):
        """将第 idx 个障碍物设为目标细胞（从障碍物列表中移除，单独存放）"""
        if idx < 0 or idx >= len(self.obstacles):
            return False
        self.target = self.obstacles.pop(idx)
        self.target_radius = self.target[2]
        return True

    def pixel_to_grid(self, px, py):
        gx = int(px // self.grid_cell_size)
        gy = int(py // self.grid_cell_size)
        return (gy, gx)

    def grid_to_pixel(self, grid_pos):
        row, col = grid_pos
        x = col * self.grid_cell_size + self.grid_cell_size // 2
        y = row * self.grid_cell_size + self.grid_cell_size // 2
        return (x, y)

    def get_obstacle_grids(self):
        """膨胀半径 = 障碍物半径 + 目标细胞半径 + 安全间隙"""
        if self.target is None:
            return set()
        expand_radius = self.target_radius + self.safe_margin
        # 注意：每个障碍物有自己的半径，这里简化用目标半径+安全间隙，更严格
        radius_grid = int(math.ceil(expand_radius / self.grid_cell_size))
        obstacle_grids = set()
        for (ox, oy, r_obs) in self.obstacles:
            # 实际膨胀应考虑 r_obs + target_radius + safe_margin
            total_expand = r_obs + self.target_radius + self.safe_margin
            rad_grid = int(math.ceil(total_expand / self.grid_cell_size))
            center_grid = self.pixel_to_grid(ox, oy)
            for dr in range(-rad_grid, rad_grid+1):
                for dc in range(-rad_grid, rad_grid+1):
                    nr = center_grid[0] + dr
                    nc = center_grid[1] + dc
                    if 0 <= nr < self.grid_height and 0 <= nc < self.grid_width:
                        px, py = self.grid_to_pixel((nr, nc))
                        if math.hypot(px - ox, py - oy) <= total_expand:
                            obstacle_grids.add((nr, nc))
        return obstacle_grids

    def plan_path(self, start_px, goal_px):
        if self.target is None:
            return []
        start_grid = self.pixel_to_grid(*start_px)
        goal_grid = self.pixel_to_grid(*goal_px)

        obstacle_grids = self.get_obstacle_grids()
        if start_grid in obstacle_grids:
            obstacle_grids.discard(start_grid)
        if goal_grid in obstacle_grids:
            return []

        path_grid = astar(start_grid, goal_grid, obstacle_grids, (self.grid_height, self.grid_width))
        if path_grid is None:
            return []
        path_px = [self.grid_to_pixel(p) for p in path_grid]
        return path_px

    def check_collision(self, target_center_px):
        """检查目标细胞中心位于某点时是否与任何障碍物相交"""
        tx, ty = target_center_px
        for (ox, oy, r_obs) in self.obstacles:
            dist = math.hypot(tx - ox, ty - oy)
            if dist < self.target_radius + r_obs:
                return True
        return False

    def start_drag(self, x, y):
        """鼠标按下：检查是否点中目标细胞"""
        if self.target is None:
            return False
        tx, ty, tr = self.target
        if math.hypot(x - tx, y - ty) <= tr:
            self.dragging = True
            # 立即规划从当前目标位置到鼠标位置的路径
            self.path = self.plan_path((tx, ty), (x, y))
            self.path_index = 0
            return True
        return False

    def drag_move(self, x, y):
        if not self.dragging or self.target is None:
            return
        # 重新规划路径
        self.path = self.plan_path(self.target[:2], (x, y))
        self.path_index = 0

    def end_drag(self, x, y):
        if self.dragging and self.target is not None:
            self.dragging = False
            self.path = self.plan_path(self.target[:2], (x, y))
            self.path_index = 0

    def update(self):
        """沿路径移动目标细胞一步"""
        if self.path and self.path_index < len(self.path):
            next_pos = self.path[self.path_index]
            if not self.check_collision(next_pos):
                # 更新目标细胞位置
                self.target = (next_pos[0], next_pos[1], self.target[2])
                self.path_index += 1
                return True
            else:
                # 碰撞，清除路径
                self.path = []
                return False
        else:
            self.path = []
            return False

    def draw(self, img):
        """在图像上绘制所有细胞和路径"""
        # 绘制障碍物（灰色）
        for (ox, oy, r) in self.obstacles:
            cv2.circle(img, (int(ox), int(oy)), int(r), (128, 128, 128), -1)
            cv2.circle(img, (int(ox), int(oy)), int(r), (0, 0, 0), 2)
        # 绘制目标细胞（绿色）
        if self.target is not None:
            tx, ty, tr = self.target
            cv2.circle(img, (int(tx), int(ty)), int(tr), (0, 255, 0), -1)
            cv2.circle(img, (int(tx), int(ty)), int(tr), (0, 0, 0), 2)
        # 绘制路径（蓝色）
        if self.path:
            for (px, py) in self.path:
                cv2.circle(img, (int(px), int(py)), 3, (255, 0, 0), -1)
            for i in range(len(self.path)-1):
                cv2.line(img, self.path[i], self.path[i+1], (255, 0, 0), 2)
        cv2.putText(img, "Click on GREEN cell and drag to move (avoiding gray cells)", 
                    (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255,255,255), 2)

# ---------- 辅助函数：从YOLO结果构建 cells_info ----------
def load_cells_from_yolo_results(model, image_path, conf_threshold=0.5):
    """
    使用YOLOv8模型预测图像，返回 cells_info 列表: [(x_center, y_center, radius), ...]
    """
    model = YOLO(model)  # 如果传入的是模型路径
    results = model(image_path, conf=conf_threshold)[0]
    cells = []
    for box in results.boxes:
        x1, y1, x2, y2 = box.xyxy[0].tolist()
        x_center = (x1 + x2) / 2
        y_center = (y1 + y2) / 2
        width = x2 - x1
        height = y2 - y1
        radius = max(width, height) / 2   # 近似半径
        cells.append((x_center, y_center, radius))
    return cells

def load_cells_from_csv(csv_path, image_width, image_height):
    """
    从 result.csv 读取细胞信息。
    假设CSV列: x_center, y_center, width, height (像素坐标或归一化坐标)
    如果是归一化坐标，需提供 image_width, image_height 转换。
    """
    df = pd.read_csv(csv_path)
    cells = []
    for _, row in df.iterrows():
        # 根据实际列名修改
        x = row['x_center']
        y = row['y_center']
        w = row['width']
        h = row['height']
        # 如果是归一化（0~1），则转换
        if max(x, y, w, h) <= 1.0:
            x *= image_width
            y *= image_height
            w *= image_width
            h *= image_height
        radius = max(w, h) / 2
        cells.append((x, y, radius))
    return cells

# ---------- 主程序示例 ----------
def main():
    # ====== 用户需要提供的参数 ======
    image_path = r"D:\Tech\Code\Program\yolov8\ultralytics-main\datasets\pbc\images\test\EO_208094_jpg.rf.4470faf82eeb12a7ac8c752fc69c96c1.jpg"      # 显微镜图像路径
    # 方式1：直接使用YOLO模型预测
    model_path = r"D:\Tech\Code\Program\runs\detect\train12\weights\best.pt"                        # 你训练好的模型
    # 方式2：使用已有的 result.csv
    csv_path = "result.csv"
    use_csv = False   # 设为 True 则使用 CSV

    # ====== 加载细胞信息 ======
    if use_csv:
        # 需要先获取图像尺寸
        temp_img = cv2.imread(image_path)
        h, w = temp_img.shape[:2]
        cells_info = load_cells_from_csv(csv_path, w, h)
    else:
        # 使用 YOLO 模型实时预测
        model = YOLO(model_path)
        results = model(image_path)[0]
        cells_info = []
        for box in results.boxes:
            x1, y1, x2, y2 = box.xyxy[0].tolist()
            xc = (x1 + x2) / 2
            yc = (y1 + y2) / 2
            radius = max(x2-x1, y2-y1) / 2
            cells_info.append((xc, yc, radius))

    if len(cells_info) == 0:
        print("未检测到任何细胞，请检查模型或图像。")
        return

    # ====== 创建世界 ======
    world = RealCellWorld(image_path, cells_info, safe_margin=5)

    # 用户选择要分离的目标细胞（这里简单选择第一个细胞作为目标）
    # 实际中可以通过鼠标点击选择，但为了演示，先默认选择索引0
    target_index = 0   # 你可以改为其他索引，或通过GUI选择
    if not world.set_target(target_index):
        print("无法设置目标细胞")
        return

    # ====== OpenCV 交互窗口 ======
    cv2.namedWindow("Cell Separation with Optical Tweezers")
    def mouse_callback(event, x, y, flags, param):
        if event == cv2.EVENT_LBUTTONDOWN:
            world.start_drag(x, y)
        elif event == cv2.EVENT_MOUSEMOVE:
            if world.dragging:
                world.drag_move(x, y)
        elif event == cv2.EVENT_LBUTTONUP:
            world.end_drag(x, y)
    cv2.setMouseCallback("Cell Separation with Optical Tweezers", mouse_callback)

    while True:
        # 更新移动
        world.update()
        # 绘制
        display = world.img_original.copy()
        world.draw(display)
        cv2.imshow("Cell Separation with Optical Tweezers", display)
        key = cv2.waitKey(30) & 0xFF
        if key == 27:  # ESC
            break
        elif key == ord('r'):
            # 重置目标细胞到原始位置
            # 需要重新加载原始细胞信息，这里简单重新初始化
            world = RealCellWorld(image_path, cells_info, safe_margin=5)
            world.set_target(target_index)

    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()