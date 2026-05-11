from ultralytics.models.yolo.detect import DetectionTrainer
from ultralytics.data import build_yolo_dataset
from balanced_dataset import BalancedYOLODataset

def de_parallel(model):
    """将模型从 DataParallel/DistributedDataParallel 中解包"""
    return model.module if hasattr(model, 'module') else model

class CustomTrainer(DetectionTrainer):  # 自定义训练器 CustomTrainer
    def build_dataset(self, img_path, mode="train", batch=None):
        # 计算模型步长 (stride)
        model = de_parallel(self.model)
        stride = max(int(model.stride.max()), 32) if hasattr(model, 'stride') else 32
        
        if mode == "train":
            # 训练模式：直接创建带下采样的数据集，避免重复构建 base_dataset
            dataset = BalancedYOLODataset(
                data=self.data,                  # 关键修复：传入数据集配置
                task="detect",                   # 明确任务类型
                img_path=img_path,               # 图片路径
                imgsz=self.args.imgsz,           # 目标尺寸
                augment=True,                    # 训练时启用数据增强
                hyp=self.args,                   # 超参数
                rect=False,                      # 矩形训练，通常训练时关闭
                batch_size=batch,                # 批次大小
                stride=stride,                   # 模型步长
                pad=0.0,                         # 填充
                prefix="train: ",
                red_cell_class_id=8,             # 红细胞类别ID（第9类，索引为8）
                max_red_cells_per_image=12      # 每张图最多保留3个红细胞
            )
        else:
            # 验证模式：直接使用官方方法构建数据集，不做下采样
            dataset = build_yolo_dataset(
                self.args, img_path, batch, self.data,
                mode=mode, rect=(mode == "val"), stride=stride
            )
        
        return dataset