#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>

class Player : public QGraphicsItem
{
public:
    enum { Type = UserType + 5 };
    int type() const
    {
       // Enable the use of qgraphicsitem_cast with this item.
       return Type;
    }
    Player();

    QRectF boundingRect() const;
    void setCurrentIndex(int index);
    bool Kolize();
protected:

    //znazornuje tvar objektu, sluzi na detekcii kolizii
    QPainterPath shape() const;
    //povinna metoda, tu se vykresluje objekt
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int currentIndex;
};

#endif // PLAYER_H
