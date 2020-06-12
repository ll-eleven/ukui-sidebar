#include "pluginsframeworkwidget.h"

static PluginsFrameworkWidget* global_Framework_Widget_instance;
PluginsFrameworkWidget::PluginsFrameworkWidget(QWidget *parent) : QWidget(parent)
{
    init();
}

void PluginsFrameworkWidget::init()
{
    m_pVBoxLayoutFramework = new QVBoxLayout();
    m_pVBoxLayoutFramework->setContentsMargins(16, 0, 16, 0);
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

//重新绘制背景色
void PluginsFrameworkWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    /* 获取当前剪贴板中字体的颜色，作为背景色；
     * 白字体 --> 黑背景
     * 黑字体 --> 白字体
    */
//    p.setBrush(opt.palette.color(QPalette::Base));
    p.setBrush(QBrush(QColor("#131314")));
    p.setOpacity(0.45);
    p.setPen(Qt::NoPen);

    p.setRenderHint(QPainter::Antialiasing);                        //反锯齿
    p.drawRoundedRect(opt.rect,0,0);
    p.drawRect(opt.rect);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
