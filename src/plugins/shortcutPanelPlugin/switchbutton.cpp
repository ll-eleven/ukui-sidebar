#include "switchbutton.h"

switchButton::switchButton(QStringList path, QStringList iconNameList)
{
    IconPath = path;
    IconNameList = iconNameList;
    this->setIcon(QIcon::fromTheme(IconNameList.at(0), QIcon(IconPath.at(0))));

    QPalette palette = this->palette();
    palette.setColor(QPalette::Highlight, Qt::transparent); /* 取消按钮高亮 */
    this->setPalette(palette);
}

void switchButton::mousePressEvent(QMouseEvent *event)
{
    this->setFixedSize(52, 52);
    this->setIcon(QIcon::fromTheme(IconNameList.at(2), QIcon(IconPath.at(2))));
    QPushButton::mousePressEvent(event);
}

void switchButton::mouseReleaseEvent(QMouseEvent *e)
{
    this->setFixedSize(62, 62);
    this->setIcon(QIcon::fromTheme(IconNameList.at(0), QIcon(IconPath.at(0))));
    QPushButton::mouseReleaseEvent(e);
}

void switchButton::enterEvent(QEvent *event)
{
    this->setIcon(QIcon::fromTheme(IconNameList.at(1), QIcon(IconPath.at(1))));
    QPushButton::enterEvent(event);
}

void switchButton::leaveEvent(QEvent *event)
{
    this->setIcon(QIcon::fromTheme(IconNameList.at(0), QIcon(IconPath.at(0))));
    QPushButton::leaveEvent(event);
}

