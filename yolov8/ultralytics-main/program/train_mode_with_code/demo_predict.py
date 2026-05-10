from ultralytics import YOLO  #从ultralytics中导入YOLO这个类

yolo = YOLO("./yolov8n.pt", task="detect")  #实例化YOLO这个对象, 这里面我们需要指定两个参数, 第一个是指定我们需要加载哪个模型, 第二个参数task, 如果要让它做检测任务的话, 就可以为"detect". 这个task也不是必须写的, 只要有前面的"./yolov8n.pt", 它就会自动去推理要去做哪个任务

result = yolo(source=r"D:\Tech\Code\Program\yolov8\ultralytics-main\ultralytics\assets\bus.jpg", save=True)  #接下来, 调用这个yolo, 指定这个source就可以进行检测了, 如果说我们需要往下保存模型的话, 就要把 save 参数指定上, save=True, 这样它就会将结果存在 runs 下面

# result = yolo(source="screen")  #对屏幕进行检测

# result = yolo(source=0)

# result = yolo(r"D:\Tech\Code\Program\yolov8\ultralytics-main\ultralytics\assets\bus.jpg", save=True, conf=0.5)  #只保留置信度>=0.5的框, 可见runs目录下先前所得到的predict4中bus.jpg的置信度为0.26的框, 并没有在本行代码运行后的predict5的bus.jpg中出现

# result = yolo(r"D:\Tech\Code\Program\yolov8\ultralytics-main\ultralytics\assets\bus.jpg", save=True, iou=0.7)  #非极大值抑制(NMS, Non-Maximum Suppression):去除同一目标上的多个重叠框, 是目标检测中常用的后处理步骤, 它的核心思想是, 保留局部置信度最高的框作为"基准框", 计算该基准框与剩余每个框的IoU(交并比), 若某个剩余框与基准框的IoU大于预设阈值(如0.5), 则认为它们检测的是同一个物体, 则该剩余框移除(抑制), 这里将iou设置为0.7