#include "listview.h"
#include "delegate.h"


listView::listView(QWidget *parent) : QListView(parent)
{
    Q_UNUSED(parent);
    init();
    setViewStyle();
    connect(this, &listView::clicked, this, &listView::onClicked);
    startTime = new QTimer;
    connect(startTime, &QTimer::timeout, this, &listView::handleTimeout);
}

listView::~listView()
{

}

/* 往delegate中添加数据 */
void listView::addData(QList<MyClass> ListData)
{
    listmodel=new QStandardItemModel(this);
    this->setModel(listmodel);
    Q_FOREACH(MyClass desktopfp,ListData)
    {
        QStandardItem* item=new QStandardItem;
        item->setData(QVariant::fromValue<MyClass>(desktopfp),Qt::DisplayRole);
        listmodel->appendRow(item);
    }
    m_delegate = new FullItemDelegate(this);
    this->setItemDelegate(m_delegate);
}

/* 初始化ListView属性 */
void listView::init()
{
    this->setFixedSize(320,180);
    this->setSelectionMode(QAbstractItemView::MultiSelection);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setViewMode(QListView::IconMode);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    this->setResizeMode(QListView::Adjust);
    this->setTextElideMode(Qt::ElideRight);
    this->setMouseTracking(true);
    this->setFocusPolicy(Qt::NoFocus);
    this->setMovement(QListView::Static);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setGridSize(QSize(75, 75));

//    this->grabGesture(Qt::TapAndHoldGesture);
}

/* 初始化ListView样式 */
void listView::setViewStyle()
{
    QPainter palette(this->viewport());
    palette.setPen(Qt::NoPen);
}

/* 点击信号槽函数*/
void listView::onClicked(QModelIndex index)
{
    QModelIndex index2 = this->currentIndex();
    if (!index2.isValid()) {
        qDebug() << "当前下表无效";
    }
    MyClass infomat = listmodel->data(index, Qt::DisplayRole).value<MyClass>();
    qDebug() << infomat.desktopfp << infomat.status;
    if (this->selectionModel()->isSelected(index)) {
        qDebug() << "选定";
    } else {
        qDebug() << "取消选定";
    }
}

void listView::handleTimeout()
{
    if (startTime->isActive()) {
       startTime->stop();
    }
    qDebug() << "超市处理";
}

/* 插入数据 */
void listView::insertData(QStringList data)
{

}

/* 重写鼠标释放事件 */
void listView::mouseReleaseEvent(QMouseEvent *e)
{
    QListView::mouseReleaseEvent(e);
}

/* 重写鼠标点击事件 */
void listView::mousePressEvent(QMouseEvent *e)
{
    if (this->indexAt(e->pos()).isValid()) {
        QModelIndex index = this->indexAt(e->pos());
        MyClass infomat = listmodel->data(index, Qt::DisplayRole).value<MyClass>();
        qDebug() << "手动获取的下标" << infomat.desktopfp << infomat.status;
        if (infomat.status) {
            QListView::mousePressEvent(e);
        }
    }
}

/* 忽略鼠标移动事件 */
void listView::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}
