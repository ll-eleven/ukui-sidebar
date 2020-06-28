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
#include "smallpluginswidget.h"

smallPluginsWidget::smallPluginsWidget(QWidget *parent) : QWidget(parent)
{
    init();                 // 初始化界面
    addDesktopFileName();   // 将desktop文件加入到链表中
    parsingDesktopFile();   // 解析desktop文件，将按钮加入到widget界面中
    this->setLayout(m_pVBoxLayout);
}

void smallPluginsWidget::init()
{
    m_pVBoxLayout = new QVBoxLayout();
    m_pVBoxLayout->setContentsMargins(0, 0, 0, 0);
    this->setContentsMargins(0, 0, 0, 0);
}

/* 解析链表中保存desktop文件，并同时保存到widget中 */
void smallPluginsWidget::parsingDesktopFile()
{
    int tmp = m_desktopfpList.size();
    m_pVBoxLayout->addItem(new QSpacerItem(14, 14));
    for (int i = 0; i < tmp; i++) {
        QString desktopfp = "/usr/share/applications/" + m_desktopfpList.at(i);
        QString icon = getAppIcon(desktopfp);
        QString Exec = getAppExec(desktopfp);
        qDebug() << "小插件的图标名称---->" << icon;
        QPushButton *SmallPushButton = new QPushButton();
        SmallPushButton->setIcon(QIcon::fromTheme(icon));
        SmallPushButton->setIconSize(QSize(32, 32));
        SmallPushButton->setFixedSize(32, 32);
        SmallPushButton->setStyle(new CustomStyle("ukui-default"));
        connect(SmallPushButton, &QPushButton::clicked, this, [=]() {
            QProcess p(0);
            p.startDetached(Exec);
            p.waitForStarted();
            return;
        });
        m_pVBoxLayout->addWidget(SmallPushButton);
        m_pVBoxLayout->addItem(new QSpacerItem(18, 20));
    }
    m_pVBoxLayout->addStretch();
    m_pVBoxLayout->setDirection(QBoxLayout::BottomToTop);
    m_pVBoxLayout->setSpacing(0);
    return;
}

/* 将小插件desktop文件名称放入到desktopfpList中 */
void smallPluginsWidget::addDesktopFileName()
{
    m_desktopfpList << "clock.desktop" << "ukui_notebook.desktop" << "feedback.desktop";
    return;
}

/* 获取应用名称 */
QString smallPluginsWidget::getAppName(QString desktopfp)
{
    GError** error=nullptr;
    GKeyFileFlags flags=G_KEY_FILE_NONE;
    GKeyFile* keyfile=g_key_file_new ();

    QByteArray fpbyte=desktopfp.toLocal8Bit();
    char* filepath=fpbyte.data();
    g_key_file_load_from_file(keyfile,filepath,flags,error);

    char* name=g_key_file_get_locale_string(keyfile,"Desktop Entry","Name", nullptr, nullptr);
    QString namestr=QString::fromLocal8Bit(name);
    g_key_file_free(keyfile);
    return namestr;
}

/* 解析Desktop文件，获取应用的图标 */
QString smallPluginsWidget::getAppIcon(QString desktopfp)
{
    GError** error=nullptr;
    GKeyFileFlags flags=G_KEY_FILE_NONE;
    GKeyFile* keyfile=g_key_file_new ();

    QByteArray fpbyte=desktopfp.toLocal8Bit();
    char* filepath=fpbyte.data();
    g_key_file_load_from_file(keyfile,filepath,flags,error);
    char* icon=g_key_file_get_locale_string(keyfile,"Desktop Entry","Icon", nullptr, nullptr);
    g_key_file_free(keyfile);
    return QString::fromLocal8Bit(icon);
}

//获取应用命令
QString smallPluginsWidget::getAppExec(QString desktopfp)
{
    GError** error=nullptr;
    GKeyFileFlags flags=G_KEY_FILE_NONE;
    GKeyFile* keyfile=g_key_file_new ();

    QByteArray fpbyte=desktopfp.toLocal8Bit();
    char* filepath=fpbyte.data();
    g_key_file_load_from_file(keyfile,filepath,flags,error);
    char* exec=g_key_file_get_locale_string(keyfile,"Desktop Entry","Exec", nullptr, nullptr);
    g_key_file_free(keyfile);
    return QString::fromLocal8Bit(exec);
}
