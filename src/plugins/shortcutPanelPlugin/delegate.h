#ifndef DELEGATE_H
#define DELEGATE_H


#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QFile>
#include <QFileInfo>
#include <QIcon>
#include <QDir>
#include <QStringList>
#include <qglobal.h>
#include <QDebug>
#include "data.h"
#define AppBtnHover  "#6B8EEB" //按钮悬浮
#define AppBtnSelect "#3D6BE5" //按钮选中
#define AppBtnNormal "#FFFFFF" //正常
class FullItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    FullItemDelegate(QObject* parent);
    ~FullItemDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    int AppListItemSizeWidth=168;
    int AppListGridSizeWidth=204;
};

#endif // DELEGATE_H
