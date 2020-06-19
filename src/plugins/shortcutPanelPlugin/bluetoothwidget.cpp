#include "bluetoothwidget.h"

bluetoothWidget::bluetoothWidget()
{
    initMemberVariables();
    initLayout();
//    this->setStyleSheet("QWidget{border: 1px solid rgba(255,255,0,1);}");
}

void bluetoothWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_BLUETOOTH_NORMAL_PATH << KYLIN_BLUETOOTH_HOVER_PATH << KYLIN_BLUETOOTH_PRESS_PATH;
    m_IconNameList << KYLIN_BLUETOOTH_NORMAL_NAME << KYLIN_BLUETOOTH_HOVER_NAME << KYLIN_BLUETOOTH_PRESS_NAME;

    m_pbluetoothButton = new PushButton(m_IconPathList, m_IconNameList);
    m_pbluetoothButton->setFixedSize(62, 62);
    m_pbluetoothButton->setIconSize(QSize(32, 32));

    m_pbluetoothLabel = new QLabel(QObject::tr("蓝牙"));
//    m_pbluetoothLabel->setFixedSize(80, 16);
    m_pbluetoothLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void bluetoothWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_pbluetoothButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_pbluetoothLabel);
    this->setLayout(m_pVboxLayout);
    return;
}
