#include "pushbutton.h"

PushButton::PushButton(QStringList path, QStringList iconNameList)
{
    IconPath = path;
    IconNameList = iconNameList;
    this->setIcon(QIcon::fromTheme(IconNameList.at(0), QIcon(IconPath.at(0))));

    QPalette palette = this->palette();
    palette.setColor(QPalette::Highlight, Qt::transparent); /* 取消按钮高亮 */
    this->setPalette(palette);
}

void PushButton::mousePressEvent(QMouseEvent *event)
{
    this->setIcon(QIcon::fromTheme(IconNameList.at(2), QIcon(IconPath.at(2))));
    QPushButton::mousePressEvent(event);
}

void PushButton::enterEvent(QEvent *event)
{
    this->setIcon(QIcon::fromTheme(IconNameList.at(1), QIcon(IconPath.at(1))));
    QPushButton::enterEvent(event);
}

void PushButton::leaveEvent(QEvent *event)
{
    this->setIcon(QIcon::fromTheme(IconNameList.at(0), QIcon(IconPath.at(0))));
    QPushButton::leaveEvent(event);
}
