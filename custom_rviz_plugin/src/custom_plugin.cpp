#include <rviz_common/display.hpp>
#include <rviz_common/properties/property.hpp>

class CustomPlugin : public rviz_common::Display
{
public:
    CustomPlugin() = default;
    ~CustomPlugin() override = default;

    void onInitialize() override {
        // Plugin initialization logic
    }
};

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(CustomPlugin, rviz_common::Display)
