#ifndef BLUETOOTHWIDGET_H
#define BLUETOOTHWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "pushbutton.h"

#define KYLIN_BLUETOOTH_NORMAL_NAME     "kylin-bluetooth-normal"
#define KYLIN_BLUETOOTH_HOVER_NAME      "kylin-bluetooth-hover"
#define KYLIN_BLUETOOTH_PRESS_NAME      "kylin-bluetooth-pressed"

#define KYLIN_BLUETOOTH_NORMAL_PATH     ":/image/bluetooth-normal.svg"
#define KYLIN_BLUETOOTH_HOVER_PATH      ":/image/bluetooth-hover.svg"
#define KYLIN_BLUETOOTH_PRESS_PATH      ":/image/bluetooth-pressed.svg"

class bluetoothWidget : public QWidget
{
public:
    bluetoothWidget();
    void initMemberVariables();
    void initLayout();

private:
    PushButton   *m_pbluetoothButton;
    QLabel       *m_pbluetoothLabel;
    QVBoxLayout  *m_pVboxLayout;

    QStringList  m_IconPathList;
    QStringList  m_IconNameList;
};

#endif // BLUETOOTHWIDGET_H
