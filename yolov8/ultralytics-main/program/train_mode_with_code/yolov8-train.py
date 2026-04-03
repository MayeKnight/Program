# -*- coding: utf-8 -*-
# 下面给出以写代码的方式启动模型训练
from ultralytics import YOLO   # 从ultralytics里导入YOLO

# Windows 缺乏 fork机制(见yolov8_basic_code),  当Python尝试启动多个子进程来加速数据加载(workers参数)时, 必须在主模块入口处进行特殊保护
if __name__ == '__main__':
    # Load a model 加载模型, 实例化YOLO类, 即创建一个YOLO模型对象, 并加载预训练权重文件yolov8n.pt
    model = YOLO('yolov8n.pt')

    # train the model 调用train方法, 其中的参数data 要改为预先配置好的数据集描述文件'yolo-fighting_game.yaml',  workers=1 数据加载的工作线程数, 他影响数据预处理和载入模型的速度. 这个必须设置, 如果是windows系统的话, 在使用GPU训练时, 要将其设置为1或0来避免多进程报错(设置成1即可), 这是windows下一种常见的规避方法,  epochs=50 训练多少轮, 这里训练50轮,  batch=16 即batch_size批处理大小, 值模型一次性处理多少张图片来更新一次参数, 16是常见值, 应根据gpu显存大小来调整, 显存越大. 可设置的 batch值越大, 有助于训练更稳定
    model.train(data='yolo-fighting_game.yaml', workers=1, epochs=50, batch=16)

    
