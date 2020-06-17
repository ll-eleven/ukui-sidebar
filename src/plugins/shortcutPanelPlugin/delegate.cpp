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
        rect.setHeight(option.rect.width());
//        qDebug() << rect.width();
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
            rect.setX(option.rect.x() + 8);
            rect.setY(option.rect.y() + 6);
            rect.setWidth(option.rect.width() - 18);
            rect.setHeight(option.rect.height() - 18);
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
//            qDebug() << "点击太";
            if (option.state & QStyle::State_MouseOver) {
                QColor color;
                color.setNamedColor(QString::fromLocal8Bit(AppBtnSelectHover));
                painter->setBrush(QBrush(color));
                painter->setOpacity(1);
                painter->drawPath(path);
            }
        } else if (option.state & QStyle::State_MouseOver) {
            QRectF rect;
            rect.setX(option.rect.x() + 8);
            rect.setY(option.rect.y() + 6);
            rect.setWidth(option.rect.width() -18);
            rect.setHeight(option.rect.height() - 18);
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
            painter->setOpacity(0.25);
            painter->drawPath(path);
//            qDebug() << "悬呼太";
        } else {
            QRectF rect;
            rect.setX(option.rect.x() + 8);
            rect.setY(option.rect.y() + 6);
            rect.setWidth(option.rect.width() - 18);
            rect.setHeight(option.rect.height() - 18);
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
//            qDebug() << "普通太";
        }
        painter->setOpacity(1);
        MyClass data    = index.data(Qt::DisplayRole).value<MyClass>();
        QString IcoName = data.IconName;
        QIcon icon = QIcon::fromTheme(IcoName);

        QString appname = data.programName;
        QRect iconRect;
        QRect textRect;
        iconRect = QRect(rect.x() + 18,
                       rect.y() + 17,
                       32,
                       32);
        icon.paint(painter, iconRect);

        textRect = QRect(rect.x()+5,
                       iconRect.bottom() + 10,
                       rect.width()-10,
                       rect.height()-iconRect.height());

        QFileInfo fileInfo(data.desktopfp);
        QString desktopfn = fileInfo.fileName();
        QFontMetrics fm = painter->fontMetrics();
        QString appnameElidedText = fm.elidedText(appname, Qt::ElideRight, rect.width() - 1, Qt::TextShowMnemonic);
        QFont font;
        font.setPointSize(11);
        painter->setFont(font);
        painter->setPen(QPen(Qt::white));
        painter->drawText(textRect,Qt::AlignHCenter|Qt::AlignTop, appnameElidedText);
        painter->restore();
    }
}

QSize FullItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(70, 70);
}
