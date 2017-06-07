#include "map.h"
#include <QPainter>

Map::Map()
{

}

QRectF Map::boundingRect() const
{
    return QRectF(0,0,756,756);
}

QPainterPath Map::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(17, 122, 49));
    painter->drawRect(boundingRect());
}
