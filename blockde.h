#ifndef BLOCKDE_H
#define BLOCKDE_H
#include <QGraphicsItem>

class BlockDe : public QGraphicsItem
{
public:
    BlockDe();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void SetCurrentIndex(int index);
private:
    int currentIndex;
};

#endif // BLOCKDE_H
