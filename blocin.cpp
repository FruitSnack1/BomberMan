#include "blocin.h"

BlocIn::BlocIn()
{

}

QRectF BlocIn::boundingRect() const
{
    return QRectF(0,0,36,36);
}

QPainterPath BlocIn::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void BlocIn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("../BomberMan-master/img/CaseIndestructible.jpg");
    painter->drawImage(QPoint(0,0),image);
}
