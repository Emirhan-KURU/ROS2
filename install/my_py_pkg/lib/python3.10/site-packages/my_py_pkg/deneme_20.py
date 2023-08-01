#!/usr/bin/python3

import rclpy 
from rclpy.node import Node

def main(args = None):
    rclpy.init(args=args)
    node = Node("Video_20_deneme")
    node.get_logger().info("Deneme_20_Basarili")
    rclpy.shutdown()

def say_to_10():
    for i in range(1, 11):
        print(i)

if __name__ == "__main__":
    main()
    say_to_10()

    

