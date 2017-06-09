#ifndef BOMB_H
#define BOMB_H
#include <QGraphicsItem>


class Bomb : public QGraphicsItem
{
public:
    Bomb();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void SetCurrentIndex(int index);
private:
    int currentIndex;
};



#endif // BOMB_H
