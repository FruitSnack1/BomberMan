#ifndef BOMB_H
#define BOMB_H
#include <QGraphicsItem>


class Bomb : public QGraphicsItem
{
public:
    enum { Type = UserType + 3 };
    int type() const
    {
       // Enable the use of qgraphicsitem_cast with this item.
       return Type;
    }
    Bomb();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void SetCurrentIndex(int index);
private:
    int currentIndex;

};



#endif // BOMB_H
