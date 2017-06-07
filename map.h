#ifndef MAP_H
#define MAP_H
#include <QGraphicsItem>


class Map : public QGraphicsItem
{
public:
    Map();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MAP_H
