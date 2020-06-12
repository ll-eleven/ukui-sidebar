#include "shortcutpanelplugin.h"

shortcutPanelPlugin::shortcutPanelPlugin(QObject *parent)
{
    Q_UNUSED(parent);
    /* 初始化插件成员变量 */
    initMemberVariables();
    initStringList();
    setButtonIcon();
    setWidget();
}

/* 初始化插件成员变量 */
void shortcutPanelPlugin::initMemberVariables()
{
    m_pMainVLayout = new QVBoxLayout;
    m_pMainVLayout->setContentsMargins(0, 0, 0, 0);
    m_pMainVLayout->setSpacing(0);

    m_pButtonHLaout = new QHBoxLayout;
    m_pButtonHLaout->setContentsMargins(0, 0, 0, 0);
    m_pMainVLayout->setSpacing(0);

    m_pViewVLayout  = new QVBoxLayout;
    m_pViewVLayout->setContentsMargins(0, 0, 0, 0);
    m_pViewVLayout->setSpacing(0);

    m_pMainWidget  = new MainWidget;
    m_pMainWidget->setContentsMargins(0, 0, 0, 0);

    m_pButtonWidget = new QWidget;
    m_pButtonWidget->setContentsMargins(0, 0, 0, 0);
    m_pButtonWidget->setFixedHeight(15);

    m_pViewWidget   = new QWidget;
    m_pViewWidget->setContentsMargins(0, 0, 0, 0);

    m_pListView = new listView(m_pMainWidget);
    m_pListView->setContentsMargins(0, 0, 0, 0);
    m_pListView->viewport()->setContentsMargins(0, 0, 0, 0);

    m_pListView->setStyleSheet("background:transparent");
    QPalette palette = m_pListView->viewport()->palette();
    palette.setBrush(QPalette::Base, QBrush(QColor("#161617")));
    m_pListView->viewport()->setPalette(palette);


    m_SpreadButtonIconList << SPREAD_BUTTON_NORMAL << SPREAD_BUTTON_HOVER << SPREAD_BUTTON_PRESS;
    m_FoldButtonIconList   << FOLD_BUTTON_NORMAL   << FOLD_BUTTON_HOVER   << FOLD_BUTTON_PRESS;

    m_pSpreadButton  = new PushButton(m_SpreadButtonIconList);
    connect(m_pSpreadButton, &QPushButton::clicked, this, &shortcutPanelPlugin::spreadClikedSlots);
    m_pSpreadButton->setFixedSize(45, 15);

    m_pfoldButton = new PushButton(m_FoldButtonIconList);
    connect(m_pfoldButton, &QPushButton::clicked, this, &shortcutPanelPlugin::foldClikedSlots);
    m_pfoldButton->setFixedSize(45, 15);
    return;
}

/* 初始化ListView中数据 */
void shortcutPanelPlugin::initStringList()
{
    m_desktopfile << "/usr/share/applications/feedback.desktop" << "/usr/share/applications/ukui_notebook.desktop"
                   << "/usr/share/applications/ukui-power-preferences.desktop" << "/usr/share/applications/ukui-control-center.desktop"
                   << "/usr/share/applications/update-manager.desktop" << "/usr/share/applications/ukui-volume-control.desktop";
    for(int i = 0; i < 6; i++) {
        data[i].desktopfp = m_desktopfile[i];
        if (i%2 == 1) {
            data[i].status    = true;
        } else {
            data[i].status    = false;
        }
        ListData.append(data[i]);
    }
    m_pListView->addData(ListData);
    return;
}

/* 设置按钮图标 */
void shortcutPanelPlugin::setButtonIcon()
{
    /* 设置展开按钮悬浮和点击状态按钮图片 */
    m_pSpreadButton->setIcon(QIcon(":/image/open-normal.svg"));

    /* 设置折叠按钮悬浮和点击状态按钮图片 */
    m_pfoldButton->setIcon(QIcon(":/image/fold-normal.svg"));
    return;
}

/* 将切换按钮和ListView界面set进插件主界面 */
void shortcutPanelPlugin::setWidget()
{
    m_pButtonHLaout->addItem(new QSpacerItem(20, 173));
    m_pButtonHLaout->addWidget(m_pSpreadButton);
    m_pButtonHLaout->addWidget(m_pfoldButton);
    m_pButtonWidget->setLayout(m_pButtonHLaout);
    m_pSpreadButton->setVisible(false);

    m_pViewVLayout->addWidget(m_pListView);
    m_pViewWidget->setLayout(m_pViewVLayout);

    m_pMainVLayout->addWidget(m_pButtonWidget);
    m_pMainVLayout->addWidget(m_pViewWidget);
    m_pMainWidget->setLayout(m_pMainVLayout);
    return;
}

/* 获取快捷操作面板界面 */
QWidget* shortcutPanelPlugin::getShortCutPanelWidget()
{
    if (m_pMainWidget == nullptr) {
        return nullptr;
    }
    return m_pMainWidget;
}

/* 展开按钮槽函数 */
void shortcutPanelPlugin::spreadClikedSlots()
{
    m_pSpreadButton->setVisible(false);
    m_pfoldButton->setVisible(true);
    int height = m_pMainWidget->height();
    int width  = m_pMainWidget->width();
    m_pMainWidget->setFixedSize(width, height*2);
    return;
}

/* 折叠按钮槽函数 */
void shortcutPanelPlugin::foldClikedSlots()
{
    m_pSpreadButton->setVisible(true);
    m_pfoldButton->setVisible(false);
    int height = m_pMainWidget->height();
    int width  = m_pMainWidget->width();
    m_pMainWidget->setFixedSize(width, height/2);
    return;
}
