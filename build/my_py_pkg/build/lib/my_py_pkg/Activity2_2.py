#!/usr/bin/python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

class Activity2_2Node(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("number_counter") # MODIFY NAME
        self.publisher_ = self.create_publisher(String, "number_counter", 10)
        self.get_logger().info("Second publisher has been started! ")


def main(args=None):
    rclpy.init(args=args)
    node = Activity2_2Node() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()