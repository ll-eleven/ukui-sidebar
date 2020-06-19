#include "calculatorwidget.h"

calculatorWidget::calculatorWidget()
{
    initMemberVariables();
    initLayout();
//    this->setStyleSheet("QWidget{border: 1px solid rgba(255,255,0,1);}");
}

void calculatorWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_CALCULATOR_NORMAL_PATH << KYLIN_CALCULATOR_HOVER_PATH << KYLIN_CALCULATOR_PRESS_PATH;
    m_IconNameList << KYLIN_CALCULATOR_NORMAL_NAME << KYLIN_CALCULATOR_HOVER_NAME << KYLIN_CALCULATOR_PRESS_NAME;
    m_pcalculatorButton = new PushButton(m_IconPathList, m_IconNameList);
    m_pcalculatorButton->setFixedSize(62, 62);
    m_pcalculatorButton->setIconSize(QSize(32, 32));

    m_pcalculatorLabel = new QLabel(QObject::tr("计算机"));
//    m_pcalculatorLabel->setFixedSize(80, 16);
    m_pcalculatorLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void calculatorWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_pcalculatorButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_pcalculatorLabel);
    this->setLayout(m_pVboxLayout);
    return;
}
