#ifndef SCREENSHOTWIDGET_H
#define SCREENSHOTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "pushbutton.h"

#define KYLIN_SCREENSHOT_NORMAL_NAME    "kylin-screenshot-normal"
#define KYLIN_SCREENSHOT_HOVER_NAME     "kylin-screenshot-hover"
#define KYLIN_SCREENSHOT_PRESS_NAME     "kylin-screenshot-pressed"


#define KYLIN_SCREENSHOT_NORMAL_PATH    ":/image/screenshot-normal.svg"
#define KYLIN_SCREENSHOT_HOVER_PATH     ":/image/screenshot-hover.svg"
#define KYLIN_SCREENSHOT_PRESS_PATH     ":/image/screenshot-pressed.svg"

class screenshotWidget : public QWidget
{
public:
    screenshotWidget();
    void initMemberVariables();
    void initLayout();

private:
    PushButton   *m_pscreenshotButton;
    QLabel       *m_pscreenshotlabel;
    QVBoxLayout  *m_pVboxLayout;

    QStringList   m_IconPathList;
    QStringList   m_IconNameList;
};

#endif // SCREENSHOTWIDGET_H
