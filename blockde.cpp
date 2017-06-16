#include "blockde.h"
#include <QPainter>

BlockDe::BlockDe()
{
    currentIndex = 0;
}

QRectF BlockDe::boundingRect() const
{
    return QRectF(0,0,36,36);
}

QPainterPath BlockDe::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void BlockDe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect(36*currentIndex, 0, 36, 36);
    QImage original("../BomberMan-master/img/CaseDestructible.png");
    QImage cropped = original.copy(rect);
    painter->drawImage(QPoint(0,0),cropped);
}

void BlockDe::SetCurrentIndex(int index)
{
    currentIndex = index;
}
