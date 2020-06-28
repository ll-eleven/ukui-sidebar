/*
* Copyright (C) 2020 Tianjin KYLIN Information Technology Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/
#include "broadsidewidget.h"

static broadSideWidget* global_broadSide_Widgets_instance;
broadSideWidget::broadSideWidget(QWidget *parent) : QWidget(parent)
{
    init();
}

/* 返回全局的Widget指针 */
broadSideWidget* broadSideWidget::getInstanceBroadSideWidgets()
{
    if (global_broadSide_Widgets_instance == nullptr) {
        global_broadSide_Widgets_instance = new broadSideWidget();
    }
    return global_broadSide_Widgets_instance;
}

/* 初始化sidebarPluginsWidgets类 */
void broadSideWidget::initBroadSideWidgets()
{
    getInstanceBroadSideWidgets();
    return;
}

/* 初始化成员变量 */
void broadSideWidget::init()
{
    m_pVLayoutSideWidget = new QVBoxLayout();
    m_pVLayoutSideWidget->setContentsMargins(0, 0, 0, 0);
    m_pVLayoutSideWidget->setSpacing(0);
    return;
}

void broadSideWidget::setLayoutSideWidget()
{
    this->setLayout(m_pVLayoutSideWidget);
    return;
}

//重新绘制背景色
void broadSideWidget::paintEvent(QPaintEvent *)
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
