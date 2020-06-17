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
    listmodel = new QStandardItemModel(this);
    this->setModel(listmodel);
    Q_FOREACH (MyClass desktopfp,ListData) {
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
    this->setGridSize(QSize(75, 85));
    this->viewport()->setContentsMargins(0, 0, 0, 0);
    this->setSpacing(0);
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
    MyClass data = listmodel->data(index, Qt::DisplayRole).value<MyClass>();

    if (this->selectionModel()->isSelected(index)) {
        qDebug() << "选定";
        findInterface(data.Interface);
    } else {
        qDebug() << "取消选定";
        findInterface(data.Interface);
    }
    return;
}

void listView::handleTimeout()
{
    if (startTime->isActive()) {
       startTime->stop();
    }
    qDebug() << "超时处理";
}

/* 插入数据 */
void listView::insertData(QStringList data)
{

}

/* 根据下标名字查找接口方法 */
void listView::findInterface(InterfaceEnum programInterface)
{
//    if (programName == "") {
//        qDebug() << "根据名字查找接口，传入参数有误, 为空 ---->";
//        return;
//    }
//    InterfaceEnum Enum = getInterfaceMark(programName);
    switch (programInterface) {
    case InterfaceEnum::PAD:
        qDebug() << "平板模式";
        break;
    case InterfaceEnum::WIFI:
        qDebug() << "Wifi开关";
        break;
    case InterfaceEnum::NODISTURB:
        qDebug() << "免打扰";
        break;
    case InterfaceEnum::SETTING:
        startSettingWidget();
        qDebug() << "设置";
        break;
    case InterfaceEnum::BLUETOOTH:
        qDebug() << "蓝牙";
        break;
    case InterfaceEnum::HOTSPOT:
        qDebug() << "热点";
        break;
    case InterfaceEnum::CALCULATOR:
        qDebug() << "计算机";
        break;
    case InterfaceEnum::SCREENSHOT:
        qDebug() << "截图";
        break;
    case InterfaceEnum::Else:
        qDebug() << "不存在此接口";
        break;
    default:
        break;
    }
}

/* 调用设置程序 */
void listView::startSettingWidget()
{
    QProcess p(0);
    p.startDetached("ukui-control-center");
    p.waitForStarted();
    return;
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
        MyClass data = listmodel->data(index, Qt::DisplayRole).value<MyClass>();
        if (data.status) {
            QListView::mousePressEvent(e);
            return;
        }
        findInterface(data.Interface);
    }
}

/* 忽略鼠标移动事件 */
void listView::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}
