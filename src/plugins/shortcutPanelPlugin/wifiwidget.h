#ifndef WIFIWIDGET_H
#define WIFIWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDBusInterface>
#include <QDBusReply>
#include <QDebug>
#include <QGSettings>
#include "pushbutton.h"

#define CONTROL_CENTER_WIFI "org.ukui.control-center.wifi.switch"

#define KYLIN_WIFI_NORMAL_NAME          "kylin-wifi-normal"
#define KYLIN_WIFI_HOVER_NAME           "kylin-wifi-normal"
#define KYLIN_WIFI_PRESS_NAME           "kylin-wifi-normal"

#define KYLIN_WIFI_NORMAL_PATH          ":/image/wifi-normal.svg"
#define KYLIN_WIFI_HOVER_PATH           ":/image/wifi-hover.svg"
#define KYLIN_WIFI_PRESS_PATH           ":/image/wifi-pressed.svg"

class WifiWidget : public QWidget
{
public:
    WifiWidget();
    void initMemberVariables();
    void initLayout();

    bool getInitStatus();

    void initComponent();
    bool getSwitchStatus(QString key);
private:
    PushButton *m_pWifiButton;
    QLabel      *m_pWifiLabel;
    QVBoxLayout *m_pVboxLayout;

    QGSettings *m_gsettings = nullptr;

    QStringList   m_IconPathList;
    QStringList   m_IconNameList;

    bool          m_bWifiIsEnable;
};

#endif // WIFIWIDGET_H
