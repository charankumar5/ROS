#include <rviz_common/panel.hpp>

class MyPlugin : public rviz_common::Panel
{
public:
    MyPlugin(QWidget *parent = nullptr) : rviz_common::Panel(parent) {
        // Initialize UI and logic
    }

    void load(const rviz_common::Config &config) override {
        rviz_common::Panel::load(config);
    }

    void save(rviz_common::Config config) const override {
        rviz_common::Panel::save(config);
    }
};
