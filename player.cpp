#include "player.h"
#include "blockde.h"
#include "bomb.h"
#include "blockin.h"
#include "map.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QImage>
#include <QDebug>


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
    path.addRect(QRectF(0,18,28,28));
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

bool Player::Kolize()
{
    QList<QGraphicsItem *> list =  this->collidingItems(Qt::IntersectsItemShape);

    foreach(QGraphicsItem * i , list)
    {
//        Player * item= qgraphicsitem_cast<Player *>(i);
//        // qDebug()<<"pos";
//        if (item)
//        {
//            qDebug() << item->type();
//            qDebug()<<"player";
//            //return true;
//        }
        BlockDe * itemBlockDe= qgraphicsitem_cast<BlockDe *>(i);
        // qDebug()<<"pos";
        if (itemBlockDe)
        {
             qDebug() << itemBlockDe->type();
            //qDebug()<<item;
            qDebug()<<"Blockde";
            return true;
        }
        BlockIn * itemBlockIn= qgraphicsitem_cast<BlockIn *>(i);
        // qDebug()<<"pos";
        if (itemBlockIn)
        {
             qDebug() << itemBlockIn->type();
            //qDebug()<<item;
            qDebug()<<"Blockde";
            return true;
        }
//        Bomb * bomb= qgraphicsitem_cast<Bomb *>(i);
//        // qDebug()<<"pos";
//        if (itemBlockDe)
//        {
//             qDebug() << itemBlockDe->type();
//            //qDebug()<<item;
//            qDebug()<<"Blockde";
//            return true;
//        }
//        BlockDe * map= qgraphicsitem_cast<BlockDe *>(i);
//        // qDebug()<<"pos";
//        if (itemBlockDe)
//        {
//             qDebug() << itemBlockDe->type();
//            //qDebug()<<item;
//            qDebug()<<"Blockde";
//            return true;
//        }
    }
    return false;
}
