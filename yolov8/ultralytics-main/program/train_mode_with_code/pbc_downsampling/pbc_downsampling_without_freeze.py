from ultralytics import YOLO
from custom_trainer import CustomTrainer

if __name__ == '__main__':
    model = YOLO(r"D:\Tech\Code\Program\runs\detect\train12\weights\best.pt")   # 你的8类预训练模型

    model.train(
    data=r"D:\Tech\Code\Program\yolov8\ultralytics-main\program\model_training_base\yolo-pbc_improve.yaml",   # 你的数据集配置文件
    epochs=50,
    trainer=CustomTrainer,
    lr0=0.001,                 # 降低学习率         
    batch=16,
    workers=8,
    mosaic=0.0
    )

