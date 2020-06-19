#include "nodisturbwidget.h"

nodisturbWidget::nodisturbWidget()
{
    initMemberVariables();
    initLayout();
//    this->setStyleSheet("QWidget{border: 1px solid rgba(255,255,0,1);}");
}

void nodisturbWidget::initMemberVariables()
{
    m_IconNameList << KYLIN_NODISTURB_NORMAL_NAME << KYLIN_NODISTURB_HOVER_NAME << KYLIN_NODISTURB_PRESS_NAME;
    m_IconPathList << KYLIN_NODISTURB_NORMAL_PATH << KYLIN_NODISTURB_HOVER_PATH << KYLIN_NODISTURB_PRESS_PATH;
    m_pnodisturbButton = new PushButton(m_IconPathList, m_IconNameList);
    m_pnodisturbButton->setFixedSize(62, 62);
    m_pnodisturbButton->setIconSize(QSize(32, 32));

    m_pnodisturbLabel = new QLabel(QObject::tr("免打扰"));
//    m_pnodisturbLabel->setFixedSize(80, 16);
    m_pnodisturbLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void nodisturbWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_pnodisturbButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_pnodisturbLabel);
    this->setLayout(m_pVboxLayout);
    return;
}
