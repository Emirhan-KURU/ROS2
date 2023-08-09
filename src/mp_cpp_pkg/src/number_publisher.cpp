#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class numberPublisherNode : public rclcpp::Node 
{
public:
    numberPublisherNode() : Node("number_publisher"), counter_(0)
    {
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number",10);
        RCLCPP_INFO(this->get_logger(),"number_publisher has been started ");
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&numberPublisherNode::PublishNews, this));

    }

private:
    void PublishNews()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = static_cast<int64_t>(counter_);
        publisher_->publish(msg);
        //RCLCPP_INFO(this->get_logger(), "Publishing: %ld", msg.data);
        counter_+=2;
    }
    int counter_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<numberPublisherNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
