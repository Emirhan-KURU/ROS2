#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp" 

class numberCounterNode : public rclcpp::Node 
{
public:
    numberCounterNode() : Node("number_counter")
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>("number",10,
                    std::bind(&numberCounterNode::numberCallNumberPublisher, this, std::placeholders::_1));
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count",10);
        
        service_ = this->create_service<example_interfaces::srv::SetBool>("reset_counter",
                    std::bind(&numberCounterNode::resetCounterService, this, std::placeholders::_1, std::placeholders::_2));
        RCLCPP_INFO(this->get_logger(),"number_counter has been started ");

    }

private:
    void numberCallNumberPublisher(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        /*this->counter_ += msg->data;
        auto new_msg = std::make_unique<example_interfaces::msg::Int64>();
        new_msg->data = this->counter_;
        publisher_->publish(std::move(new_msg));*/
    }
    void resetCounterService(const std::shared_ptr<example_interfaces::srv::SetBool::Request> request,
        std::shared_ptr<example_interfaces::srv::SetBool::Response> response)
    {
        if (request->data) {
            //this->counter_ =  0; //reset did not occur because the code did not work
            response->success = true;
            response->message = "Counter has been reset";
        } else {
            response->success = false;
            response->message = "Counter has not been reset";
        }
    }
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr service_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<numberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
