#include "player.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>


Player::Player()
{
   // this->ItemIsMovable(true);
    currentIndex=0;
}

QRectF Player::boundingRect() const
{   //sirka obrazka 57*80
    return QRectF(0,0,32,50);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(QRectF(0,18,32,32));
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(QBrush(Qt::red));
//    painter->drawRect(boundingRect());

    QRect rect(45*currentIndex, 0, 45, 57);
    QImage original("../BomberMan-master/img/BomberManCyan.png");
    QImage cropped = original.copy(rect);
    painter->drawImage(QPoint(0,0),cropped.scaled(32,50));


}

void Player::setCurrentIndex(int index)
{
    currentIndex=index;
}
