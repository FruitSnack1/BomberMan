#ifndef BLOCKIN_H
#define BLOCKIN_H
#include <QGraphicsItem>


class BlockIn : public QGraphicsItem
{
public:
    enum { Type = UserType + 2 };
    int type() const
    {
       // Enable the use of qgraphicsitem_cast with this item.
       return Type;
    }
    BlockIn();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BLOCKIN_H
