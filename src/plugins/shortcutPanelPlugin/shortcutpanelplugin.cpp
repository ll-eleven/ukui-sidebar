#include "shortcutpanelplugin.h"

shortcutPanelPlugin::shortcutPanelPlugin(QObject *parent)
{
    Q_UNUSED(parent);
    initMemberVariables();      // 初始化插件成员变量
    initBaseStringList();       // 初始化基础数据链表
    initHashData();             // 初始化hash表中值
    initDataList();             // 初始化ListView中数据
    setButtonIcon();            // 设置按钮图标
    setWidget();                // 将切换按钮和ListView界面set进插件主界面
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
void shortcutPanelPlugin::initDataList()
{
    for (int i = 0; i < m_desktopfile.count(); i++) {
        data[i].desktopfp   = "/usr/share/applications/" + m_desktopfile[i];
        data[i].programName = m_programName[i];
        data[i].IconName    = m_IconName[i];
        data[i].Interface   = getInterfaceMark(data[i].programName);
        qDebug() << data[i].IconName;
        if (m_switchNameList.contains(data[i].programName)) {
            data[i].status = false;
        } else if (m_statusNameList.contains(data[i].programName)) {
            data[i].status = true;
        } else {
            data[i].status = false;
        }
        ListData.append(data[i]);
    }

    m_pListView->addData(ListData);
    return;
}

/* 初始化hash表中的数据 */
void shortcutPanelPlugin::initHashData()
{
    m_InterfaceHash.insert(PAD_NAME, InterfaceEnum::PAD);
    m_InterfaceHash.insert(WIFI_NAME, InterfaceEnum::WIFI);
    m_InterfaceHash.insert(NODISTURB_NAME, InterfaceEnum::NODISTURB);
    m_InterfaceHash.insert(SETTING_NAME, InterfaceEnum::SETTING);
    m_InterfaceHash.insert(BLUETOOTH_NAME, InterfaceEnum::BLUETOOTH);
    m_InterfaceHash.insert(HOTSPOT_NAME, InterfaceEnum::HOTSPOT);
    m_InterfaceHash.insert(CALCULATOR_NAME, InterfaceEnum::CALCULATOR);
    m_InterfaceHash.insert(SCREENSHOT_NAME, InterfaceEnum::SCREENSHOT);
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

void shortcutPanelPlugin::initBaseStringList()
{
    m_desktopfile << "/usr/share/applications/feedback.desktop" << "/usr/share/applications/ukui_notebook.desktop"
                   << "/usr/share/applications/ukui-power-preferences.desktop" << "/usr/share/applications/ukui-control-center.desktop"
                   << "/usr/share/applications/update-manager.desktop" << "/usr/share/applications/ukui-volume-control.desktop"
                   << "/usr/share/applications/update-manager.desktop" << "/usr/share/applications/ukui-volume-control.desktop";

    m_IconName    << KYLIN_PAD_NORMAL << KYLIN_WIFI_NORMAL << KYLIN_NODISTURB_NORMAL << KYLIN_SETTING_NORMAL
                  << KYLIN_BLUETOOTH_NORMAL << KYLIN_HOTSPOT_NORMAL << KYLIN_CALCULATOR_NORMAL << KYLIN_SCREENSHOT_NORMAL;

    m_programName << PAD_NAME << WIFI_NAME << NODISTURB_NAME << SETTING_NAME
                  << BLUETOOTH_NAME << HOTSPOT_NAME << CALCULATOR_NAME << SCREENSHOT_NAME;

    m_switchNameList << SETTING_NAME << CALCULATOR_NAME << SCREENSHOT_NAME;

    m_statusNameList << PAD_NAME << WIFI_NAME << NODISTURB_NAME << BLUETOOTH_NAME << HOTSPOT_NAME;
}



/* 获取快捷操作面板界面 */
QWidget* shortcutPanelPlugin::getShortCutPanelWidget()
{
    if (m_pMainWidget == nullptr) {
        return nullptr;
    }
    return m_pMainWidget;
}

/* 获取接口代号 */
InterfaceEnum shortcutPanelPlugin::getInterfaceMark(QString key)
{

    if ("" == key) {
        qDebug() << "获取接口代号失败， 传入参数有误";
        return InterfaceEnum::Else;
    }
    if (m_InterfaceHash.contains(key)) {
        return m_InterfaceHash.value(key);
    }
    else
        return InterfaceEnum::Else;
}

/* 移除Hash中接口 */
void shortcutPanelPlugin::removeInterfaceMark(QString key)
{
    if ("" == key) {
        qDebug() << "移除Hash中接口失败， 传入参数有误";
        return;
    }
    if (m_InterfaceHash.contains(key))
        m_InterfaceHash.remove(key);
    return;
}

/* 插入接口和代号往Hash表中 */
void shortcutPanelPlugin::insertInterfaceMark(QString key, InterfaceEnum value)
{
    if ("" == key || value < 0) {
        qDebug() << "插入数据失败， 传入参数有误";
        return;
    }
    if (m_InterfaceHash.contains(key)) {
        qDebug() << "此Key值已存在";
        return;
    }
    m_InterfaceHash.insert(key, value);
    return;
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
