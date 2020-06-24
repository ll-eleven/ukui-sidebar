#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QStringList>
#include <QIcon>
#include <QSize>
class PushButton : public QPushButton
{
public:
    PushButton(QStringList path, QStringList iconNameList);
protected:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QStringList IconPath;
    QStringList IconNameList;
};

#endif // PUSHBUTTON_H
