# ros2_turtle

cd ros2_turtle
colcon build --packages-select turtle_circle

source /opt/ros/jazzy/setup.bash  
source ~/ros2_turtle/install/setup.bash

ros2 run turtlesim turtlesim_node

ros2 run turtle_circle turtle_circle_node
