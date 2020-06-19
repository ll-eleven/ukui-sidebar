#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "pushbutton.h"

#define KYLIN_CALCULATOR_NORMAL_PATH    ":/image/calculator-normal.svg"
#define KYLIN_CALCULATOR_HOVER_PATH     ":/image/calculator-hover.svg"
#define KYLIN_CALCULATOR_PRESS_PATH     ":/image/calculator-pressed.svg"

#define KYLIN_CALCULATOR_NORMAL_NAME    "kylin-calculator-normal"
#define KYLIN_CALCULATOR_HOVER_NAME     "kylin-calculator-hover"
#define KYLIN_CALCULATOR_PRESS_NAME     "kylin-calculator-pressed"

class calculatorWidget : public QWidget
{
public:
    calculatorWidget();
    void initMemberVariables();
    void initLayout();
private:
    PushButton  *m_pcalculatorButton;
    QLabel       *m_pcalculatorLabel;
    QVBoxLayout  *m_pVboxLayout;

    QStringList  m_IconPathList;
    QStringList  m_IconNameList;
};

#endif // CALCULATORWIDGET_H
