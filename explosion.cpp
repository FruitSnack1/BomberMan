#include "explosion.h"
#include <QPainter>

Explosion::Explosion(QList<QList<int> > &inBlockList)
{
    currentIndex = 0;
    list = inBlockList;

}

QRectF Explosion::boundingRect() const
{
    return QRectF(-36,-36,108,108);
}

QPainterPath Explosion::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect(36*currentIndex, 0, 36, 36);
    QImage center("../BomberMan-master/img/FlammesCentre.png");
    QImage up("../BomberMan-master/img/FlammesUp.png");
    QImage right("../BomberMan-master/img/FlammesRight.png");
    QImage down("../BomberMan-master/img/FlammesDown.png");
    QImage left("../BomberMan-master/img/FlammesLeft.png");

    center = center.copy(rect);
    up = up.copy(rect);
    right = right.copy(rect);
    down = down.copy(rect);
    left = left.copy(rect);

    painter->drawImage(QPoint(0,0),center);
    if(list[this->pos.x()/36][this->pos.y()/36-1]!=1)
        {painter->drawImage(QPoint(0,-36),up);}
    painter->drawImage(QPoint(36,0),right);
    painter->drawImage(QPoint(0,36),down);
    painter->drawImage(QPoint(-36,0),left);
}

void Explosion::SetCurrentIndex(int index)
{
    currentIndex=index;
}
