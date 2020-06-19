#include "wifiwidget.h"

WifiWidget::WifiWidget()
{
    initMemberVariables();
    initLayout();
}

void WifiWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_WIFI_NORMAL_PATH << KYLIN_WIFI_HOVER_PATH << KYLIN_WIFI_PRESS_PATH;
    m_IconNameList << KYLIN_WIFI_NORMAL_NAME << KYLIN_WIFI_HOVER_NAME << KYLIN_WIFI_PRESS_NAME;
    m_pWifiButton = new PushButton(m_IconPathList, m_IconNameList);
    m_pWifiButton->setFixedSize(62, 62);
    m_pWifiButton->setIconSize(QSize(32, 32));

    m_pWifiLabel = new QLabel(QObject::tr("Wifi"));
    m_pWifiLabel->setAlignment(Qt::AlignHCenter);
    m_pWifiLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

/* 初始化布局 */
void WifiWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_pWifiButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_pWifiLabel, 0, Qt::AlignCenter);
    this->setLayout(m_pVboxLayout);
    return;
}

/* 获取当前的wifi状态，打开或关闭 */
bool WifiWidget::getInitStatus()
{
    QDBusInterface interface( "org.freedesktop.NetworkManager",
                              "/org/freedesktop/NetworkManager",
                              "org.freedesktop.DBus.Properties",
                              QDBusConnection::systemBus());
    //获取当前wifi是否连接
    QDBusReply<QVariant> m_result = interface.call("Get", "org.freedesktop.NetworkManager", "WirelessEnabled");

    if (m_result.isValid()) {
        bool status = m_result.value().toBool();
        return status;
    } else {
        qDebug()<<"org.freedesktop.NetworkManager get invalid"<<endl;
        return false;
    }
    return false;
}

/* 初始化gsetting值 */
void WifiWidget::initComponent()
{
    const QByteArray id(CONTROL_CENTER_WIFI);
    if (QGSettings::isSchemaInstalled(id)) {
        m_gsettings = new QGSettings(id);
        //  监听key的value是否发生了变化
        qDebug() << "初始化的switch开关" << m_bWifiIsEnable;
        connect(m_gsettings, &QGSettings::changed, this, [=] (const QString &key) {
            qDebug()<<"status changed ------------>"<< key << endl;
            if (key == "switchor") {
                bool judge = getSwitchStatus(key);    // 网络工具助手修改的gsetting值
                qDebug() << "当前Key值----->value === " << judge;
                m_bWifiIsEnable = judge;
            }
        });
    }
    return;
}

/* 获取当前网络工具助手修改gsetting值后的状态 */
bool WifiWidget::getSwitchStatus(QString key)
{
    if (!m_gsettings) {
        return true;
    }
    const QStringList list = m_gsettings->keys();
    if (!list.contains(key)) {
        return false;
    }
    bool res = m_gsettings->get(key).toBool();
    return res;
}
