#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"


class numberCounterNode : public rclcpp::Node 
{
public:
    numberCounterNode() : Node("number_counter") 
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>("number",10,
                    std::bind(&numberCounterNode::numberCallNumberPublisher, this, std::placeholders::_1));
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count",10);
        RCLCPP_INFO(this->get_logger(),"number_counter has been started ");
    }

private:
    void numberCallNumberPublisher(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        //RCLCPP_INFO(this->get_logger(), "Received: %ld", msg->data);

    }
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<numberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
