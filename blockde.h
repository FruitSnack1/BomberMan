#ifndef BLOCKDE_H
#define BLOCKDE_H
#include <QGraphicsItem>

class BlockDe : public QGraphicsItem
{
public:
    enum { Type = UserType + 1 };
    int type() const
    {
       // Enable the use of qgraphicsitem_cast with this item.
       return Type;
    }
    BlockDe();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void SetCurrentIndex(int index);
    int timer=0;
private:
    int currentIndex;
};

#endif // BLOCKDE_H
