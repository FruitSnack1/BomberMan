#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <QGraphicsItem>

class Explosion : public QGraphicsItem
{
public:
    Explosion(QList<QList<int> > &inBlockList);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int timer = 0;
    QPoint pos;
    void SetCurrentIndex(int index);
private:
    int currentIndex;
    QList<QList<int> > list;
};

#endif // EXPLOSION_H
