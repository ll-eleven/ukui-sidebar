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
#ifndef SMALLPLUGINSWIDGET_H
#define SMALLPLUGINSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <glib.h>
#include <QProcess>
#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include "customstyle.h"
class smallPluginsWidget : public QWidget
{
    Q_OBJECT
public:
    smallPluginsWidget(QWidget *parent = nullptr);
    void init();

    void    parsingDesktopFile();                                 //解析desktop文件
    void    addDesktopFileName();                                 //将小插件desktop文件名称放入到desktopfpList中
    QString getAppIcon(QString desktopfp);                        //解析desktop文件，获取插件图标
    QString getAppName(QString desktopfp);                        //获取插件名称
    QString getAppExec(QString desktopfp);                        //获取应用可执行文件路径

private:
    QStringList m_desktopfpList;                                  //保存当前小插件desktop文件名称
    QVBoxLayout *m_pVBoxLayout;                                   //对widget中的button进行布局

};

#endif // SMALLPLUGINSWIDGET_H
