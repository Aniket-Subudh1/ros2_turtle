#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>

using namespace std::chrono_literals;

class TurtleCircleNode : public rclcpp::Node
{
public:
    TurtleCircleNode() : Node("turtle_circle_node")
    {
        // Create publisher to send velocity commands to the turtle
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
        
        // Create timer to publish velocity commands periodically
        timer_ = this->create_wall_timer(
            100ms, std::bind(&TurtleCircleNode::timer_callback, this));
        
        RCLCPP_INFO(this->get_logger(), "Turtle Circle Motion Node has started!");
    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Twist();
        
        // Set linear velocity in x direction (forward)
        message.linear.x = 2.0;
        // Set angular velocity in z direction (rotation)
        message.angular.z = 1.0;
        
        // Publish the message
        publisher_->publish(message);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleCircleNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}