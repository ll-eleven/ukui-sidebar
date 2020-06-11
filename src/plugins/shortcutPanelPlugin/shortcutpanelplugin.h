#ifndef SHORTCUTPANELPLUGIN_H
#define SHORTCUTPANELPLUGIN_H
#include "shortCutPanelInterface.h"
#include <QObject>
#include <QVBoxLayout>
class shortcutPanelPlugin : public QObject, public shortCutPanelInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.ukui.sidebar-qt.plugin-iface.shortCutPanelInterface" FILE "shortcutPanelPlugin.json")
    Q_INTERFACES(shortCutPanelInterface)
public:
    explicit shortcutPanelPlugin(QObject *parent = nullptr);

    QWidget *getShortCutPanelWidget() override;

    //插件自带的函数
    void initMemberVariables();
private:
    QVBoxLayout *m_pMainVLayout = nullptr;
    QWidget     *m_pMainWidget  = nullptr;
};

#endif // SHORTCUTPANELPLUGIN_H
