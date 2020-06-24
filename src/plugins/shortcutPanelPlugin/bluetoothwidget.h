#ifndef BLUETOOTHWIDGET_H
#define BLUETOOTHWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QtDBus>
#include "switchbutton.h".h"
#include "swichButtonOpenStatus.h"
#include "customstyle_switchNormalStatus.h"

#define KYLIN_BLUETOOTH_NORMAL_NAME     "kylin-bluetooth-normal"
#define KYLIN_BLUETOOTH_HOVER_NAME      "kylin-bluetooth-hover"
#define KYLIN_BLUETOOTH_PRESS_NAME      "kylin-bluetooth-pressed"

#define KYLIN_BLUETOOTH_NORMAL_PATH     ":/image/bluetooth-normal.svg"
#define KYLIN_BLUETOOTH_HOVER_PATH      ":/image/bluetooth-hover.svg"
#define KYLIN_BLUETOOTH_PRESS_PATH      ":/image/bluetooth-pressed.svg"

#define KYLIN_BLUETOOTH_SERVER_NAME      "org.blueman.Applet"
#define KYLIN_BLUETOOTH_SERVER_PATH      "/org/blueman/applet"
#define KYLIN_BLUETOOTH_SERVER_INTERFACE "org.blueman.Applet"

class bluetoothWidget : public QWidget
{
public:
    bluetoothWidget();
    void initMemberVariables();
    void initLayout();

    bool initBluetoothDbus();
    void initBluetoothStatus();

    void setBluetoothStatus();

private:
    QWidget         *m_pWidgetButton;
    switchButton    *m_pbluetoothButton;
    QLabel          *m_pbluetoothLabel;

    QVBoxLayout     *m_pVboxButtonLayout;
    QVBoxLayout     *m_pVboxLayout;

    QStyle          *m_pStyleOpen;
    QStyle          *m_pStyleNormal;

    QStringList      m_IconPathList;
    QStringList      m_IconNameList;
    QDBusInterface*  m_pServiceInterface;
    bool             m_bbluetoothStatus;
private slots:
    void BluetoothStatusChangedSlots(bool status);
    void bluetoothButtonClickSlots();
};

#endif // BLUETOOTHWIDGET_H
