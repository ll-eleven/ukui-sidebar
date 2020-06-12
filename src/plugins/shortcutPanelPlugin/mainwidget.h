#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QStyleOption>
#include <QPainter>
class MainWidget : public QWidget
{
public:
    MainWidget();

protected:
    void paintEvent(QPaintEvent *e);
};

#endif // MAINWIDGET_H
