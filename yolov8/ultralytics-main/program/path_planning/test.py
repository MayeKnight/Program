import cv2
import numpy as np
import math
import heapq

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

# ---------- 模拟细胞世界 ----------
class CellWorld:
    def __init__(self, width=800, height=600, cell_radius=20, safe_margin=5):
        self.width = width
        self.height = height
        self.cell_radius = cell_radius          # 所有细胞半径相同（可扩展）
        self.safe_margin = safe_margin          # 额外安全间隙（像素）
        # 栅格边长设为细胞半径的 1/4，提高精度
        self.grid_cell_size = max(1, cell_radius // 4)
        self.grid_width = width // self.grid_cell_size
        self.grid_height = height // self.grid_cell_size

        self.obstacles = []          # 障碍物像素坐标列表
        self.target = (width // 2, height // 2)
        self.dragging = False
        self.path = []
        self.path_index = 0

    def add_obstacle(self, x, y):
        self.obstacles.append((x, y))

    def generate_random_obstacles(self, num=15):
        np.random.seed(42)
        for _ in range(num):
            while True:
                x = np.random.randint(self.cell_radius, self.width - self.cell_radius)
                y = np.random.randint(self.cell_radius, self.height - self.cell_radius)
                # 不与目标初始位置重叠
                if math.hypot(x - self.target[0], y - self.target[1]) > 2*self.cell_radius + self.safe_margin:
                    ok = True
                    for ox, oy in self.obstacles:
                        if math.hypot(x - ox, y - oy) < 2*self.cell_radius + self.safe_margin:
                            ok = False
                            break
                    if ok:
                        self.obstacles.append((x, y))
                        break

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
        expand_radius = self.cell_radius + self.cell_radius + self.safe_margin
        radius_grid = int(math.ceil(expand_radius / self.grid_cell_size))
        obstacle_grids = set()
        for (ox, oy) in self.obstacles:
            center_grid = self.pixel_to_grid(ox, oy)
            for dr in range(-radius_grid, radius_grid+1):
                for dc in range(-radius_grid, radius_grid+1):
                    nr = center_grid[0] + dr
                    nc = center_grid[1] + dc
                    if 0 <= nr < self.grid_height and 0 <= nc < self.grid_width:
                        px, py = self.grid_to_pixel((nr, nc))
                        if math.hypot(px - ox, py - oy) <= expand_radius:
                            obstacle_grids.add((nr, nc))
        return obstacle_grids

    def plan_path(self, start_px, goal_px):
        start_grid = self.pixel_to_grid(*start_px)
        goal_grid = self.pixel_to_grid(*goal_px)

        obstacle_grids = self.get_obstacle_grids()
        # 确保起点和终点不在障碍物中
        if start_grid in obstacle_grids:
            obstacle_grids.discard(start_grid)
        if goal_grid in obstacle_grids:
            return []   # 终点被障碍物覆盖，无法到达

        path_grid = astar(start_grid, goal_grid, obstacle_grids, (self.grid_height, self.grid_width))
        if path_grid is None:
            return []
        # 转换为像素坐标（栅格中心）
        path_px = [self.grid_to_pixel(p) for p in path_grid]
        return path_px

    def check_collision(self, pos_px):
        """检查目标细胞中心位于 pos_px 时是否与任何障碍物圆相交"""
        for (ox, oy) in self.obstacles:
            dist = math.hypot(pos_px[0] - ox, pos_px[1] - oy)
            if dist < self.cell_radius + self.cell_radius:  # 两圆相交即碰撞
                return True
        return False

    def start_drag(self, x, y):
        if math.hypot(x - self.target[0], y - self.target[1]) <= self.cell_radius:
            self.dragging = True
            self.path = self.plan_path(self.target, (x, y))
            self.path_index = 0
            return True
        return False

    def drag_move(self, x, y):
        if not self.dragging:
            return
        self.path = self.plan_path(self.target, (x, y))
        self.path_index = 0

    def end_drag(self, x, y):
        if self.dragging:
            self.dragging = False
            self.path = self.plan_path(self.target, (x, y))
            self.path_index = 0

    def update(self):
        """沿路径移动一小步，每次移动前检查碰撞"""
        if self.path and self.path_index < len(self.path):
            next_pos = self.path[self.path_index]
            # 检查下一步是否碰撞
            if not self.check_collision(next_pos):
                self.target = next_pos
                self.path_index += 1
                return True
            else:
                # 碰撞发生，清除路径，等待重新规划
                self.path = []
                return False
        else:
            self.path = []
            return False

    def draw(self, img):
        # 画障碍物（灰色）
        for (x, y) in self.obstacles:
            cv2.circle(img, (x, y), self.cell_radius, (128, 128, 128), -1)
            cv2.circle(img, (x, y), self.cell_radius, (0, 0, 0), 2)
        # 画目标细胞（绿色）
        cv2.circle(img, self.target, self.cell_radius, (0, 255, 0), -1)
        cv2.circle(img, self.target, self.cell_radius, (0, 0, 0), 2)
        # 画路径（蓝色）
        if self.path:
            for i, (px, py) in enumerate(self.path):
                cv2.circle(img, (px, py), 3, (255, 0, 0), -1)
            for i in range(len(self.path)-1):
                cv2.line(img, self.path[i], self.path[i+1], (255, 0, 0), 2)
        cv2.putText(img, "Drag GREEN cell (will NOT touch gray cells)", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255,255,255), 2)

# ---------- 主程序 ----------
def main():
    world = CellWorld(width=800, height=600, cell_radius=20, safe_margin=5)
    world.generate_random_obstacles(num=12)

    cv2.namedWindow("Optical Tweezers Simulation")
    def mouse_callback(event, x, y, flags, param):
        if event == cv2.EVENT_LBUTTONDOWN:
            world.start_drag(x, y)
        elif event == cv2.EVENT_MOUSEMOVE:
            if world.dragging:
                world.drag_move(x, y)
        elif event == cv2.EVENT_LBUTTONUP:
            world.end_drag(x, y)
    cv2.setMouseCallback("Optical Tweezers Simulation", mouse_callback)

    while True:
        world.update()
        img = np.zeros((world.height, world.width, 3), dtype=np.uint8)
        world.draw(img)
        cv2.imshow("Optical Tweezers Simulation", img)
        key = cv2.waitKey(30) & 0xFF
        if key == 27:
            break
        elif key == ord('r'):
            world.target = (world.width//2, world.height//2)
            world.path = []

    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()