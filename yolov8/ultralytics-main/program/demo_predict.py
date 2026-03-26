from ultralytics import YOLO  #从ultralytics中导入YOLO这个类

yolo = YOLO("./yolov8n.pt", task="detect")  #实例化YOLO这个对象, 这里面我们需要指定两个参数, 第一个是指定我们需要加载哪个模型, 第二个参数task, 如果要让它做检测任务的话, 就可以为"detect". 这个task也不是必须写的, 只要有前面的"./yolov8n.pt", 它就会自动去推理要去做哪个任务

result = yolo(source=r"D:\Tech\Code\Program\yolov8\ultralytics-main\ultralytics\assets\bus.jpg")  #接下来, 调用这个yolo, 指定这个source就可以进行检测了


