#ifndef MY_RVIZ_PLUGIN_HPP
#define MY_RVIZ_PLUGIN_HPP

#include <rviz_common/panel.hpp>
#include <QPushButton>

namespace my_rviz_plugin {

class MyRvizPlugin : public rviz_common::Panel {
    Q_OBJECT

public:
    explicit MyRvizPlugin(QWidget* parent = nullptr);

private:
    QPushButton* my_button_;
};

}  // namespace my_rviz_plugin

#endif  // MY_RVIZ_PLUGIN_HPP
