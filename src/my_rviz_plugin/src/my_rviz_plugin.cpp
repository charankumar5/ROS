#include "my_rviz_plugin/my_rviz_plugin.hpp"
#include <rclcpp/rclcpp.hpp>  // Add this include for RCLCPP_INFO
#include <QVBoxLayout>

namespace my_rviz_plugin {

MyRvizPlugin::MyRvizPlugin(QWidget* parent)
    : rviz_common::Panel(parent) {
    auto* layout = new QVBoxLayout;
    my_button_ = new QPushButton("Click Me");
    layout->addWidget(my_button_);
    setLayout(layout);

    connect(my_button_, &QPushButton::clicked, []() {
        RCLCPP_INFO(rclcpp::get_logger("MyRvizPlugin"), "Button clicked!");
    });
}

}  // namespace my_rviz_plugin

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(my_rviz_plugin::MyRvizPlugin, rviz_common::Panel)
