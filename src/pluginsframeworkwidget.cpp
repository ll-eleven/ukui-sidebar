#include "pluginsframeworkwidget.h"

static PluginsFrameworkWidget* global_Framework_Widget_instance;
PluginsFrameworkWidget::PluginsFrameworkWidget(QWidget *parent) : QWidget(parent)
{
    init();
}

void PluginsFrameworkWidget::init()
{
    m_pVBoxLayoutFramework = new QVBoxLayout();
    m_pVBoxLayoutFramework->setContentsMargins(0, 0, 0, 0);
    return;
}

PluginsFrameworkWidget* PluginsFrameworkWidget::getInstancePLuginsFrameworkWidgets()
{
    if (global_Framework_Widget_instance == nullptr) {
        global_Framework_Widget_instance = new PluginsFrameworkWidget();
    }
    return global_Framework_Widget_instance;
}

void PluginsFrameworkWidget::initPLuginsFrameworkWidgets()
{
    getInstancePLuginsFrameworkWidgets();
    return;
}

void PluginsFrameworkWidget::setLayoutPLuginsFrameworkWidget()
{
    m_pVBoxLayoutFramework->setSpacing(0);
    this->setLayout(m_pVBoxLayoutFramework);
    return;
}
