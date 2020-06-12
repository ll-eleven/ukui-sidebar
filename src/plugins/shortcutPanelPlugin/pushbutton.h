#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QStringList>
class PushButton : public QPushButton
{
public:
    PushButton(QStringList path);
protected:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private:
    QStringList IconPath;
};

#endif // PUSHBUTTON_H
