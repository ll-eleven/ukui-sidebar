#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QProcess>
#include "pushbutton.h"

#define KYLIN_SETTING_NORMAL_NAME       "kylin-setting-normal"
#define KYLIN_SETTING_HOVER_NAME        "kylin-setting-hover"
#define KYLIN_SETTING_PRESS_NAME        "kylin-setting-pressed"

#define KYLIN_SETTING_NORMAL_PATH       ":/image/setting-normal.svg"
#define KYLIN_SETTING_HOVER_PATH        ":/image/setting-hover.svg"
#define KYLIN_SETTING_PRESS_PATH        ":/image/setting-pressed.svg"

class settingWidget : public QWidget
{
public:
    settingWidget();
    void initMemberVariables();
    void initLayout();
private:
    PushButton   *m_psettingButton;
    QLabel       *m_psettingLabel;
    QVBoxLayout  *m_pVboxLayout;

    QStringList   m_IconPathList;
    QStringList   m_IconNameList;

private slots:
    void settingButtonClick();
};

#endif // SETTINGWIDGET_H
