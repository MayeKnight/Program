from ultralytics import YOLO
model = YOLO(r"D:\Tech\Code\Program\runs\detect\train12\weights\best.pt")
print(len(model.model.model))  # 输出层数