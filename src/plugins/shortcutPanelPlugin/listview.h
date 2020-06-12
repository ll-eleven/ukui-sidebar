#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QObject>
#include <QListView>
#include <QWidget>
#include <QStandardItemModel>
#include <QTimer>
#include <QThread>
#include <QEvent>
#include <QMouseEvent>
#include <QPalette>
#include <QPainter>
#include "delegate.h"
class listView : public QListView
{
    Q_OBJECT
public:
    listView(QWidget *parent);
    ~listView();

    void init();
    void setViewStyle();
    void addData(QList<MyClass> ListData);
    void insertData(QStringList data);

    QTimer *startTime;
private:
    FullItemDelegate* m_delegate=nullptr;
    QStandardItemModel* listmodel=nullptr;

protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void onClicked(QModelIndex index);
    void handleTimeout();
};


#endif // LISTVIEW_H
