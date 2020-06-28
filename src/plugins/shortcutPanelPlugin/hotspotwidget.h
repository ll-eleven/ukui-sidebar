#ifndef HOTSPOTWIDGET_H
#define HOTSPOTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "switchbutton.h"

#define KYLIN_HOTSPOT_NORMAL_NAME      "kylin-hotspot-normal"
#define KYLIN_HOTSPOT_HOVER_NAME       "kylin-hotspot-hover"
#define KYLIN_HOTSPOT_PRESS_NAME       "kylin-hotspot-pressed"

#define KYLIN_HOTSPOT_NORMAL_PATH      ":/image/hotspot-normal.svg"
#define KYLIN_HOTSPOT_HOVER_PATH       ":/image/hotspot-hover.svg"
#define KYLIN_HOTSPOT_PRESS_PATH       ":/image/hotspot-pressed.svg"

class hotspotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit hotspotWidget(QWidget *parent = nullptr);
    ~hotspotWidget();
    void initMemberVariables();
    void initLayout();
private:
    QWidget       *m_pWidgetButton;
    switchButton  *m_photspotButton;
    QLabel        *m_photspotLabel;

    QVBoxLayout   *m_pVboxButtonLayout;
    QVBoxLayout   *m_pVboxLayout;

    QStringList  m_IconPathList;
    QStringList  m_IconNameList;
};

#endif // HOTSPOTWIDGET_H
