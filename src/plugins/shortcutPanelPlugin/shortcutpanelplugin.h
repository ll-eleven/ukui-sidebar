#ifndef SHORTCUTPANELPLUGIN_H
#define SHORTCUTPANELPLUGIN_H
#include "shortCutPanelInterface.h"
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>
#include <QDBusInterface>
#include <QDBusReply>
#include <QDebug>
#include <QGridLayout>
#include "mainwidget.h"
#include "pushbutton.h"
#include "data.h"
#include "bluetoothwidget.h"
#include "calculatorwidget.h"
#include "hotspotwidget.h"
#include "nodisturbwidget.h"
#include "padwidget.h"
#include "screenshotwidget.h"
#include "settingwidget.h"
#include "wifiwidget.h"

#define SPREAD_BUTTON_NORMAL       ":/image/open-normal.svg"
#define SPREAD_BUTTON_HOVER        ":/image/open-hover.svg"
#define SPREAD_BUTTON_PRESS        ":/image/open-pressed.svg"
#define FOLD_BUTTON_NORMAL         ":/image/fold-normal.svg"
#define FOLD_BUTTON_HOVER          ":/image/fold-hover.svg"
#define FOLD_BUTTON_PRESS          ":/image/fold-pressed.svg"

#define FOLD_BUTTON_NORMAL_NAME    "kylin-fold-normal"
#define FOLD_BUTTON_HOVER_NAME     "kylin-fold-hover"
#define FOLD_BUTTON_PRESS_NAME     "kylin-fold-pressed"

#define SPREAD_BUTTON_NORMAL_NAME  "kylin-open-normal"
#define SPREAD_BUTTON_HOVER_NAME   "kylin-open-hover"
#define SPREAD_BUTTON_PRESS_NAME   "kylin-open-pressed"

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
    void initShortButtonWidget();
    void initsetShortWidget();
    void resetShortWidget();
    void setButtonIcon();

    void setWidget();

    bool getwifiisEnable();

    /* Hash表  查、删、增 */
    InterfaceEnum getInterfaceMark(QString key);
    void removeInterfaceMark(QString key);
    void insertInterfaceMark(QString key, InterfaceEnum value);

public slots:
    void spreadClikedSlots();
    void foldClikedSlots();
private:
    QVBoxLayout  *m_pMainVLayout    = nullptr;
    QHBoxLayout  *m_pButtonHLaout   = nullptr;
    QGridLayout  *m_pShortGLayout   = nullptr;
    MainWidget   *m_pMainWidget     = nullptr;
    QWidget      *m_pButtonWidget   = nullptr;
    QWidget      *m_pShortWidget    = nullptr;
    PushButton   *m_pSpreadButton   = nullptr;
    PushButton   *m_pfoldButton     = nullptr;

    QStringList   m_SpreadButtonIconList;
    QStringList   m_FoldButtonIconList;
    QStringList   m_SpreadButtonIconNameList;
    QStringList   m_FoldButtonIconNameList;

    MyClass data[8];
    QList<QWidget*> ShortButtonWidgetList;
    QHash<QString, InterfaceEnum> m_InterfaceHash;

    /* 8个按钮 快捷界面 */
    bluetoothWidget      *m_pbluetoothWidget;
    calculatorWidget     *m_pcalculatorWidget;
    hotspotWidget        *m_photspotWidget;
    nodisturbWidget      *m_pnodisturbWidget;
    padWidget            *m_ppadWidget;
    screenshotWidget     *m_pscreenshotWidget;
    settingWidget        *m_psettingWidget;
    WifiWidget           *m_pWifiWidget;
};

#endif // SHORTCUTPANELPLUGIN_H
