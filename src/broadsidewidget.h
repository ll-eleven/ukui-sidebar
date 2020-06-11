#ifndef BROADSIDEWIDGET_H
#define BROADSIDEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
class broadSideWidget : public QWidget
{
public:
    broadSideWidget(QWidget *parent = nullptr);
    static broadSideWidget* getInstanceBroadSideWidgets();
    static void initBroadSideWidgets();

    void init();
    void setLayoutSideWidget();
    QVBoxLayout *m_pVLayoutSideWidget;
protected:
    void paintEvent(QPaintEvent *);
};

#endif // BROADSIDEWIDGET_H
