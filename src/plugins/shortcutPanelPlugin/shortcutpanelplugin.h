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
#define SPREAD_BUTTON_NORMAL ":/image/open-normal.svg"
#define SPREAD_BUTTON_HOVER  ":/image/open-hover.svg"
#define SPREAD_BUTTON_PRESS  ":/image/open-pressed.svg"
#define FOLD_BUTTON_NORMAL   ":/image/fold-normal.svg"
#define FOLD_BUTTON_HOVER    ":/image/fold-hover.svg"
#define FOLD_BUTTON_PRESS    ":/image/fold-pressed.svg"

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
    void initStringList();
    void setButtonIcon();
    void setWidget();
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
    QStringList  m_SpreadButtonIconList;
    QStringList  m_FoldButtonIconList;
    MyClass data[6];
    QList<MyClass> ListData;
};

#endif // SHORTCUTPANELPLUGIN_H
