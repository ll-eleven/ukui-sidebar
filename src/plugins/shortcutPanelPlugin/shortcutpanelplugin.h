#ifndef SHORTCUTPANELPLUGIN_H
#define SHORTCUTPANELPLUGIN_H
#include "shortCutPanelInterface.h"
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>
#include "mainwidget.h"
#include "pushbutton.h"
#include "listview.h"
#include "data.h"
#define SPREAD_BUTTON_NORMAL       ":/image/open-normal.svg"
#define SPREAD_BUTTON_HOVER        ":/image/open-hover.svg"
#define SPREAD_BUTTON_PRESS        ":/image/open-pressed.svg"
#define FOLD_BUTTON_NORMAL         ":/image/fold-normal.svg"
#define FOLD_BUTTON_HOVER          ":/image/fold-hover.svg"
#define FOLD_BUTTON_PRESS          ":/image/fold-pressed.svg"

#define KYLIN_PAD_NORMAL           "kylin-pad-normal"
#define KYLIN_WIFI_NORMAL          "kylin-wifi-normal"
#define KYLIN_NODISTURB_NORMAL     "kylin-nodisturb-normal"
#define KYLIN_SETTING_NORMAL       "kylin-setting-normal"
#define KYLIN_BLUETOOTH_NORMAL     "kylin-bluetooth-normal"
#define KYLIN_HOTSPOT_NORMAL       "kylin-hotspot-normal"
#define KYLIN_CALCULATOR_NORMAL    "kylin-calculator-normal"
#define KYLIN_SCREENSHOT_NORMAL    "kylin-screenshot-normal"

#define PAD_NAME                   "平板模式"
#define WIFI_NAME                  "Wifi"
#define NODISTURB_NAME             "免打扰"
#define SETTING_NAME               "所有设置"
#define BLUETOOTH_NAME             "蓝牙"
#define HOTSPOT_NAME               "热点"
#define CALCULATOR_NAME            "计算机"
#define SCREENSHOT_NAME            "截图"

class shortcutPanelPlugin : public QObject, public shortCutPanelInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.ukui.sidebar-qt.plugin-iface.shortCutPanelInterface" FILE "shortcutPanelPlugin.json")
    Q_INTERFACES(shortCutPanelInterface)
public:
    explicit shortcutPanelPlugin(QObject *parent = nullptr);

    //插件接口
    QWidget *getShortCutPanelWidget() override;

    //插件函数
    void initMemberVariables();
    void initDataList();
    void initHashData();
    void setButtonIcon();
    void setWidget();

    /* 成员变量字符串链表的 初 增 删 */
    void initBaseStringList();
    void addBaseStringList();
    void removeStringList();

    /* Hash表  查、删、增 */
    InterfaceEnum getInterfaceMark(QString key);
    void removeInterfaceMark(QString key);
    void insertInterfaceMark(QString key, InterfaceEnum value);

public slots:
    void spreadClikedSlots();
    void foldClikedSlots();
private:
    QVBoxLayout *m_pMainVLayout   = nullptr;
    QHBoxLayout *m_pButtonHLaout  = nullptr;
    QVBoxLayout *m_pViewVLayout   = nullptr;
    MainWidget  *m_pMainWidget    = nullptr;
    QWidget     *m_pButtonWidget  = nullptr;
    QWidget     *m_pViewWidget    = nullptr;
    QPushButton *m_pSpreadButton  = nullptr;
    QPushButton *m_pfoldButton    = nullptr;

    listView    *m_pListView      = nullptr;
    QStringList  m_desktopfile;
    QStringList  m_programName;
    QStringList  m_IconName;
    QStringList  m_SpreadButtonIconList;
    QStringList  m_FoldButtonIconList;
    QStringList  m_switchNameList;
    QStringList  m_statusNameList;
    MyClass data[8];
    QList<MyClass> ListData;
    QHash<QString, InterfaceEnum> m_InterfaceHash;
};

#endif // SHORTCUTPANELPLUGIN_H
