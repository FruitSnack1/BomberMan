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
    QImage image("../BomberMan-master/img/CaseIndestructible.jpg");
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if((i == 0 || j == 0) || (i == 20 || j == 20)){
                painter->drawImage(QPoint(36*i,36*j),image);
            }else if(i%2 ==0 && j%2 == 0){
                painter->drawImage(QPoint(36*i,36*j),image);
            }
        }
    }
}
