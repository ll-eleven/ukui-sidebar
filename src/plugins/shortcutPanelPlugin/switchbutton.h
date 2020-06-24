#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPalette>

class switchButton : public QPushButton
{
    Q_OBJECT
public:
    switchButton(QStringList path, QStringList iconNameList);

protected:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void mouseReleaseEvent(QMouseEvent *e);
signals:
    void pressSignal();
    void releaseSignal();

private:
    QStringList IconPath;
    QStringList IconNameList;
};

#endif // SWITCHBUTTON_H
