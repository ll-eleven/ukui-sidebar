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
