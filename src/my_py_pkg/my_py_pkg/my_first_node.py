#!/usr/bin/python3

import rclpy
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        super().__init__("py_test")
        self.counter_ = 0
        self.get_logger().info("Hello ROS2!")
        self.create_timer(0.5, self.timer_callback)


    def timer_callback(self):
        self.counter_ +=1
        self.get_logger().info("Hello"+ str(self.counter_))

def main(args=None):
    rclpy.init(args=args)
    node = MyNode()  # MyNode sınıfını burada oluşturun
    rclpy.spin(node)  # Oluşturduğunuz MyNode nesnesini spin işlevine verin
    rclpy.shutdown()

if __name__ == "__main__":
    main() 