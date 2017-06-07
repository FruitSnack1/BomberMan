#ifndef BLOCKIN_H
#define BLOCKIN_H
#include <QGraphicsItem>


class BlockIn : public QGraphicsItem
{
public:
    BlockIn();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BLOCKIN_H
