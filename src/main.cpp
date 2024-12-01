#include <rclcpp/rclcpp.hpp>
#include "GameEnvironment.h"

int main(int argc, char** argv) {
    // Initialize ROS2
    rclcpp::init(argc, argv);

    // Create a ROS2 node
    auto node = rclcpp::Node::make_shared("environment_builder_test");

    // Instantiate the GameEnvironment
    auto game_environment = std::make_shared<GameEnvironment>(node);

    // Build the environment
    RCLCPP_INFO(node->get_logger(), "Building the environment...");
    game_environment->drawGame();

    // Keep the node alive to observe the changes in TurtleSim
    rclcpp::spin(node);

    // Shutdown ROS2
    rclcpp::shutdown();
    return 0;
}
