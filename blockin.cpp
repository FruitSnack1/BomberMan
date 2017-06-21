#include "blockin.h"
#include <QPainter>

BlockIn::BlockIn()
{

}

QRectF BlockIn::boundingRect() const
{
    return QRectF(0,0,36,36);
}

QPainterPath BlockIn::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(0,0,36,36));
    return path;
}

void BlockIn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("../BomberMan-master/img/CaseIndestructible.jpg");
    painter->drawImage(QPoint(0,0),image);
}
