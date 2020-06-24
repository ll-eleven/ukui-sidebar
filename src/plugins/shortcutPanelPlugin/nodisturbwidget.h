#ifndef NODISTURBWIDGET_H
#define NODISTURBWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "switchbutton.h".h"

#define KYLIN_NODISTURB_NORMAL_NAME     "kylin-nodisturb-normal"
#define KYLIN_NODISTURB_HOVER_NAME     "kylin-nodisturb-hover"
#define KYLIN_NODISTURB_PRESS_NAME     "kylin-nodisturb-pressed"


#define KYLIN_NODISTURB_NORMAL_PATH     ":/image/nodisturb-normal.svg"
#define KYLIN_NODISTURB_HOVER_PATH     ":/image/nodisturb-hover.svg"
#define KYLIN_NODISTURB_PRESS_PATH     ":/image/nodisturb-pressed.svg"

class nodisturbWidget : public QWidget
{
public:
    nodisturbWidget();
    void initMemberVariables();
    void initLayout();
private:
    QWidget       *m_pWidgetButton;
    switchButton  *m_pnodisturbButton;
    QLabel        *m_pnodisturbLabel;

    QVBoxLayout   *m_pVboxButtonLayout;
    QVBoxLayout   *m_pVboxLayout;

    QStringList  m_IconPathList;
    QStringList  m_IconNameList;
};

#endif // NODISTURBWIDGET_H
