import random
import torch
from ultralytics.data import YOLODataset

class BalancedYOLODataset(YOLODataset):  # 用于平衡处理数据集
    def __init__(self, *args, red_cell_class_id=8, max_red_cells_per_image=12, **kwargs):
        super().__init__(*args, **kwargs)
        self.red_cell_class_id = red_cell_class_id
        self.max_red_cells = max_red_cells_per_image

    def __getitem__(self, index):
        data = super().__getitem__(index)
        labels = data['cls']          # shape (N,)
        bboxes = data['bboxes']       # shape (N, 4)
        
        # 找出红细胞和其他类别的索引
        red_mask = (labels == self.red_cell_class_id)
        other_mask = ~red_mask
        
        red_indices = torch.where(red_mask)[0].tolist()
        other_indices = torch.where(other_mask)[0].tolist()
        
        # 对红细胞进行下采样
        if len(red_indices) > self.max_red_cells:
            red_indices = random.sample(red_indices, self.max_red_cells)
        
        keep_indices = other_indices + red_indices
        
        # 1. 过滤 cls 和 bboxes
        data['cls'] = labels[keep_indices]
        data['bboxes'] = bboxes[keep_indices]
        
        # 2. 过滤其他与目标数量相关的字段（长度必须等于原始N）
        for key in ['batch_idx', 'segments', 'keypoints']:
            if key in data and data[key] is not None:
                # 检查该字段的长度是否与原始 labels 一致
                if len(data[key]) == len(labels):
                    data[key] = data[key][keep_indices]
                else:
                    # 以防万一，打印警告（通常不会发生）
                    print(f"Warning: {key} length {len(data[key])} != labels length {len(labels)}")
        
        return data