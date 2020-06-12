#include "mainwidget.h"

MainWidget::MainWidget()
{

}

//重新绘制背景色
void MainWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    /* 获取当前剪贴板中字体的颜色，作为背景色；
     * 白字体 --> 黑背景
     * 黑字体 --> 白字体
    */
//    p.setBrush(opt.palette.color(QPalette::Base));
    p.setBrush(QBrush(QColor("#FFFFFF")));
    p.setOpacity(0.02);
    p.setPen(Qt::NoPen);

    p.setRenderHint(QPainter::Antialiasing);                        //反锯齿
    p.drawRoundedRect(opt.rect, 6, 6);
    p.drawRect(opt.rect);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
