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
#include <QStyle>
#include "switchbutton.h"
#include "swichButtonOpenStatus.h"
#include "customstyle_switchNormalStatus.h"

#define CONTROL_CENTER_WIFI "org.ukui.control-center.wifi.switch"

#define KYLIN_WIFI_NORMAL_NAME          "kylin-wifi-normal"
#define KYLIN_WIFI_HOVER_NAME           "kylin-wifi-normal"
#define KYLIN_WIFI_PRESS_NAME           "kylin-wifi-normal"

#define KYLIN_WIFI_NORMAL_PATH          ":/image/wifi-normal.svg"
#define KYLIN_WIFI_HOVER_PATH           ":/image/wifi-hover.svg"
#define KYLIN_WIFI_PRESS_PATH           ":/image/wifi-pressed.svg"

class WifiWidget : public QWidget
{
    Q_OBJECT
public:
    WifiWidget();
    void initMemberVariables();
    void initLayout();
    void initStatus();
    void OpenStatus();
    void NormalStatus();

    bool getInitStatus();
    bool getwifiisEnable();

    void initComponent();
    bool getSwitchStatus(QString key);

    void setwifiSwitch(bool signal);

private:
    QWidget      *m_pWidgetButton;
    switchButton *m_pWifiButton;
    QLabel       *m_pWifiLabel;

    QStyle       *m_pStyleOpen;
    QStyle       *m_pStyleNormal;

    QVBoxLayout  *m_pVboxButtonLayout;
    QVBoxLayout  *m_pVboxLayout;

    QGSettings   *m_gsettings = nullptr;

    QStringList   m_IconPathList;
    QStringList   m_IconNameList;

    bool          m_bWifiIsEnable;
private slots:

    void          WifiButtonClickSlot();
};

#endif // WIFIWIDGET_H
