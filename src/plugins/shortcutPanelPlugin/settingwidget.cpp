#include "settingwidget.h"

settingWidget::settingWidget()
{
    initMemberVariables();
    initLayout();
//    this->setStyleSheet("QWidget{border: 1px solid rgba(255,255,0,1);}");
}

void settingWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_SETTING_NORMAL_PATH << KYLIN_SETTING_HOVER_PATH << KYLIN_SETTING_PRESS_PATH;
    m_IconNameList << KYLIN_SETTING_NORMAL_NAME << KYLIN_SETTING_HOVER_NAME << KYLIN_SETTING_PRESS_NAME;
    m_psettingButton = new PushButton(m_IconPathList, m_IconNameList);
    m_psettingButton->setFixedSize(62, 62);
    m_psettingButton->setIconSize(QSize(32, 32));
    connect(m_psettingButton, &PushButton::clicked, this, &settingWidget::settingButtonClick);

    m_psettingLabel = new QLabel(QObject::tr("设置"));
    m_psettingLabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void settingWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_psettingButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_psettingLabel);
    this->setLayout(m_pVboxLayout);
    return;
}

void settingWidget::settingButtonClick()
{
    QProcess p(0);
    p.startDetached("ukui-control-center");
    p.waitForStarted();
    return;
}
