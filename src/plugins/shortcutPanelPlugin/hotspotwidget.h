#ifndef HOTSPOTWIDGET_H
#define HOTSPOTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "pushbutton.h"

#define KYLIN_HOTSPOT_NORMAL_NAME      "kylin-hotspot-normal"
#define KYLIN_HOTSPOT_HOVER_NAME       "kylin-hotspot-hover"
#define KYLIN_HOTSPOT_PRESS_NAME       "kylin-hotspot-pressed"

#define KYLIN_HOTSPOT_NORMAL_PATH      ":/image/hotspot-normal.svg"
#define KYLIN_HOTSPOT_HOVER_PATH       ":/image/hotspot-hover.svg"
#define KYLIN_HOTSPOT_PRESS_PATH       ":/image/hotspot-pressed.svg"

class hotspotWidget : public QWidget
{
public:
    hotspotWidget();
    void initMemberVariables();
    void initLayout();
private:
    PushButton  *m_photspotButton;
    QLabel       *m_photspotLabel;
    QVBoxLayout  *m_pVboxLayout;

    QStringList  m_IconPathList;
    QStringList  m_IconNameList;
};

#endif // HOTSPOTWIDGET_H
