#include "delegate.h"

#include "delegate.h"

FullItemDelegate::FullItemDelegate(QObject *parent)
{

}

FullItemDelegate::~FullItemDelegate()
{

}

void FullItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid())
    {
        QStyledItemDelegate::initStyleOption((QStyleOptionViewItem*)&option, index);
        painter->save();
        QStyleOptionViewItem viewOption(option);//用来在视图中画一个item
        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width());
        rect.setHeight(option.rect.height());
        //QPainterPath画圆角矩形
        const qreal radius = 6;
        QPainterPath path;
        path.moveTo(rect.topRight() - QPointF(radius, 0));
        path.lineTo(rect.topLeft() + QPointF(radius, 0));
        path.quadTo(rect.topLeft(), rect.topLeft() + QPointF(0, radius));
        path.lineTo(rect.bottomLeft() + QPointF(0, -radius));
        path.quadTo(rect.bottomLeft(), rect.bottomLeft() + QPointF(radius, 0));
        path.lineTo(rect.bottomRight() - QPointF(radius, 0));
        path.quadTo(rect.bottomRight(), rect.bottomRight() + QPointF(0, -radius));
        path.lineTo(rect.topRight() + QPointF(0, radius));
        path.quadTo(rect.topRight(), rect.topRight() + QPointF(-radius, -0));
        painter->setRenderHint(QPainter::Antialiasing);
        if (option.state & QStyle::State_Selected) {
            QRectF rect;
            rect.setX(option.rect.x() + 10);
            rect.setY(option.rect.y() + 10);
            rect.setWidth(option.rect.width() -15);
            rect.setHeight(option.rect.height() - 15);
            const qreal radius = 6;
            QPainterPath path;
            path.moveTo(rect.topRight() - QPointF(radius, 0));
            path.lineTo(rect.topLeft() + QPointF(radius, 0));
            path.quadTo(rect.topLeft(), rect.topLeft() + QPointF(0, radius));
            path.lineTo(rect.bottomLeft() + QPointF(0, -radius));
            path.quadTo(rect.bottomLeft(), rect.bottomLeft() + QPointF(radius, 0));
            path.lineTo(rect.bottomRight() - QPointF(radius, 0));
            path.quadTo(rect.bottomRight(), rect.bottomRight() + QPointF(0, -radius));
            path.lineTo(rect.topRight() + QPointF(0, radius));
            path.quadTo(rect.topRight(), rect.topRight() + QPointF(-radius, -0));
            painter->setPen(QPen(Qt::NoPen));
            QColor color;
            color.setNamedColor(QString::fromLocal8Bit(AppBtnSelect));
            painter->setBrush(QBrush(color));
            painter->setOpacity(1);
            painter->drawPath(path);
            qDebug() << "点击太";
        } else if (option.state & QStyle::State_MouseOver) {
            QRectF rect;
            rect.setX(option.rect.x() + 10);
            rect.setY(option.rect.y() + 10);
            rect.setWidth(option.rect.width() -15);
            rect.setHeight(option.rect.height() - 15);
            const qreal radius = 6;
            QPainterPath path;
            path.moveTo(rect.topRight() - QPointF(radius, 0));
            path.lineTo(rect.topLeft() + QPointF(radius, 0));
            path.quadTo(rect.topLeft(), rect.topLeft() + QPointF(0, radius));
            path.lineTo(rect.bottomLeft() + QPointF(0, -radius));
            path.quadTo(rect.bottomLeft(), rect.bottomLeft() + QPointF(radius, 0));
            path.lineTo(rect.bottomRight() - QPointF(radius, 0));
            path.quadTo(rect.bottomRight(), rect.bottomRight() + QPointF(0, -radius));
            path.lineTo(rect.topRight() + QPointF(0, radius));
            path.quadTo(rect.topRight(), rect.topRight() + QPointF(-radius, -0));
            painter->setPen(QPen(Qt::NoPen));
            QColor color;
            color.setNamedColor(QString::fromLocal8Bit(AppBtnHover));
            painter->setBrush(QBrush(color));
            painter->setOpacity(1);
            painter->drawPath(path);
            qDebug() << "悬呼太";
        } else {
            QRectF rect;
            rect.setX(option.rect.x() + 10);
            rect.setY(option.rect.y() + 10);
            rect.setWidth(option.rect.width() -15);
            rect.setHeight(option.rect.height() - 15);
            const qreal radius = 6;
            QPainterPath path;
            path.moveTo(rect.topRight() - QPointF(radius, 0));
            path.lineTo(rect.topLeft() + QPointF(radius, 0));
            path.quadTo(rect.topLeft(), rect.topLeft() + QPointF(0, radius));
            path.lineTo(rect.bottomLeft() + QPointF(0, -radius));
            path.quadTo(rect.bottomLeft(), rect.bottomLeft() + QPointF(radius, 0));
            path.lineTo(rect.bottomRight() - QPointF(radius, 0));
            path.quadTo(rect.bottomRight(), rect.bottomRight() + QPointF(0, -radius));
            path.lineTo(rect.topRight() + QPointF(0, radius));
            path.quadTo(rect.topRight(), rect.topRight() + QPointF(-radius, -0));
            painter->setPen(QPen(Qt::NoPen));
            QColor color;
            color.setNamedColor(QString::fromLocal8Bit(AppBtnNormal));
            painter->setBrush(QBrush(color));
            painter->setOpacity(0.15);
            painter->drawPath(path);
            qDebug() << "普通太";
        }
        painter->setOpacity(1);
        MyClass desktopfp=index.data(Qt::DisplayRole).value<MyClass>();
        QIcon icon = QIcon::fromTheme("notebook");

        QString appname="Wifi";
        QRect iconRect;
        QRect textRect;
        iconRect=QRect(rect.x() + 16,
                       rect.y() + 15,
                       32,
                       32);
        icon.paint(painter, iconRect);

        textRect=QRect(rect.x()+5,
                       iconRect.bottom() + 10,
                       rect.width()-10,
                       rect.height()-iconRect.height());

        QFileInfo fileInfo(desktopfp.desktopfp);
        QString desktopfn=fileInfo.fileName();
        QFontMetrics fm=painter->fontMetrics();
        QString appnameElidedText=fm.elidedText(appname,Qt::ElideRight,rect.width()-10,Qt::TextShowMnemonic);
        painter->setPen(QPen(Qt::black));
        painter->drawText(textRect,Qt::AlignHCenter |Qt::AlignTop,appnameElidedText);
        painter->restore();
    }
}

QSize FullItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(60, 60);
}
