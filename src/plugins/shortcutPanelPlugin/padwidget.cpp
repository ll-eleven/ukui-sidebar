#include "padwidget.h"

padWidget::padWidget()
{
    initMemberVariables();
    initLayout();
//    this->setStyleSheet("QWidget{border: 1px solid rgba(255,255,0,1);}");
}

void padWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_PAD_NORMAL_PATH << KYLIN_PAD_HOVER_PATH << KYLIN_PAD_PRESS_PATH;
    m_IconNameList << KYLIN_PAD_NORMAL_NAME << KYLIN_PAD_HOVER_NAME << KYLIN_PAD_PRESS_NAME;
    m_pPadButton = new PushButton(m_IconPathList, m_IconNameList);
    m_pPadButton->setFixedSize(62, 62);
    m_pPadButton->setIconSize(QSize(32, 32));

    m_pPadLabel = new QLabel(QObject::tr("平板模式"));
//    m_pPadLabel->setFixedSize(80, 16);
    m_pPadLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void padWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_pPadButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_pPadLabel);
    this->setLayout(m_pVboxLayout);
    return;
}
