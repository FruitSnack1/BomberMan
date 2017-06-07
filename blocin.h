#ifndef BLOCIN_H
#define BLOCIN_H
#include <QGraphicsItem>

class BlocIn : public QGraphicsItem
{
public:
    BlocIn();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BLOCIN_H
