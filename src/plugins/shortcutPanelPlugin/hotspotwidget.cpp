#include "hotspotwidget.h"

hotspotWidget::hotspotWidget()
{
    initMemberVariables();
    initLayout();
//    this->setStyleSheet("QWidget{border: 1px solid rgba(255,255,0,1);}");
}

void hotspotWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_HOTSPOT_NORMAL_PATH << KYLIN_HOTSPOT_HOVER_PATH << KYLIN_HOTSPOT_PRESS_PATH;
    m_IconNameList << KYLIN_HOTSPOT_NORMAL_NAME << KYLIN_HOTSPOT_HOVER_NAME << KYLIN_HOTSPOT_PRESS_NAME;
    m_photspotButton = new PushButton(m_IconPathList, m_IconNameList);
    m_photspotButton->setFixedSize(62, 62);
    m_photspotButton->setIconSize(QSize(32, 32));

    m_photspotLabel = new QLabel(QObject::tr("热点"));
//    m_photspotLabel->setFixedSize(80, 16);
    m_photspotLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void hotspotWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_photspotButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_photspotLabel);
    this->setLayout(m_pVboxLayout);
    return;
}
