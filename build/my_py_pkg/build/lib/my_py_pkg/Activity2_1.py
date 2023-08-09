#!/usr/bin/python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

class Activity2_1Node(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("number_publisher") # MODIFY NAME
        self.publisher_ = self.create_publisher(String, "number_publisher", 10)
        self.get_logger().info("first publisher has been started! ")

    def callback_number_counter(self, msg):
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = Activity2_1Node() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()