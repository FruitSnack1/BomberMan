#ifndef MAP_H
#define MAP_H
#include <QGraphicsItem>


class Map : public QGraphicsItem
{
public:
    enum { Type = UserType + 4 };
    int type() const
    {
       // Enable the use of qgraphicsitem_cast with this item.
       return Type;
    }
    Map();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MAP_H
