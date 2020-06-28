#ifndef SCREENSHOTWIDGET_H
#define SCREENSHOTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QProcess>
#include "switchbutton.h"

#define KYLIN_SCREENSHOT_NORMAL_NAME    "kylin-screenshot-normal"
#define KYLIN_SCREENSHOT_HOVER_NAME     "kylin-screenshot-hover"
#define KYLIN_SCREENSHOT_PRESS_NAME     "kylin-screenshot-pressed"


#define KYLIN_SCREENSHOT_NORMAL_PATH    ":/image/screenshot-normal.svg"
#define KYLIN_SCREENSHOT_HOVER_PATH     ":/image/screenshot-hover.svg"
#define KYLIN_SCREENSHOT_PRESS_PATH     ":/image/screenshot-pressed.svg"

class screenshotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit screenshotWidget(QWidget *parent = nullptr);
    ~screenshotWidget();
    void initMemberVariables();
    void initLayout();

private:
    QWidget      *m_pWidgetButton;
    switchButton   *m_pscreenshotButton;
    QLabel       *m_pscreenshotlabel;

    QVBoxLayout  *m_pVboxButtonLayout;
    QVBoxLayout  *m_pVboxLayout;

    QStringList   m_IconPathList;
    QStringList   m_IconNameList;
private slots:
    void         sreenShotButtonClickedSlots();
};

#endif // SCREENSHOTWIDGET_H
