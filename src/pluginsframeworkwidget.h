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
#ifndef PLUGINSFRAMEWORKWIDGET_H
#define PLUGINSFRAMEWORKWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
class PluginsFrameworkWidget: public QWidget
{
public:
    PluginsFrameworkWidget(QWidget *parent = nullptr);

    void init();
    static PluginsFrameworkWidget* getInstancePLuginsFrameworkWidgets();
    static void initPLuginsFrameworkWidgets();
    void setLayoutPLuginsFrameworkWidget();

    QVBoxLayout* m_pVBoxLayoutFramework;
protected:
    void paintEvent(QPaintEvent *e);
};

#endif // PLUGINSFRAMEWORKWIDGET_H
