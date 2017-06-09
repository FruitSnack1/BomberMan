#include "bomb.h"

Bomb::Bomb()
{

    currentIndex = 0;

}

QRectF Bomb::boundingRect() const
{

}

QPainterPath Bomb::shape() const
{

}

void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRect rect(32*currentIndex, 0, 36, 36);
    QImage original("../BomberMan-master/img/BombeAnimation.png");
    QImage cropped = original.copy(rect);
    painter->drawImage(QPoint(0,0),cropped);

}

void Bomb::SetCurrentIndex(int index)
{

}
