#include "screenshotwidget.h"

screenshotWidget::screenshotWidget()
{
    initMemberVariables();
    initLayout();
//    this->setStyleSheet("QWidget{border: 1px solid rgba(255,255,0,1);}");
}

void screenshotWidget::initMemberVariables()
{
    m_IconPathList << KYLIN_SCREENSHOT_NORMAL_PATH << KYLIN_SCREENSHOT_HOVER_PATH << KYLIN_SCREENSHOT_PRESS_PATH;
    m_IconNameList << KYLIN_SCREENSHOT_NORMAL_NAME << KYLIN_SCREENSHOT_HOVER_NAME << KYLIN_SCREENSHOT_PRESS_NAME;
    m_pscreenshotButton = new PushButton(m_IconPathList, m_IconNameList);
    m_pscreenshotButton->setFixedSize(62, 62);
    m_pscreenshotButton->setIconSize(QSize(32, 32));

    m_pscreenshotlabel = new QLabel(QObject::tr("截图"));
//    m_pscreenshotlabel->setFixedSize(80, 16);
    m_pscreenshotlabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(80, 93);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void screenshotWidget::initLayout()
{
    m_pVboxLayout->addWidget(m_pscreenshotButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 10));
    m_pVboxLayout->addWidget(m_pscreenshotlabel);
    this->setLayout(m_pVboxLayout);
    return;
}
