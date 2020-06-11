#ifndef PLUGINSFRAMEWORKWIDGET_H
#define PLUGINSFRAMEWORKWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

class PluginsFrameworkWidget: public QWidget
{
public:
    PluginsFrameworkWidget(QWidget *parent = nullptr);

    void init();
    static PluginsFrameworkWidget* getInstancePLuginsFrameworkWidgets();
    static void initPLuginsFrameworkWidgets();
    void setLayoutPLuginsFrameworkWidget();

    QVBoxLayout* m_pVBoxLayoutFramework;
};

#endif // PLUGINSFRAMEWORKWIDGET_H
