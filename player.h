#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>

class Player : public QGraphicsItem
{
public:
    Player();

    QRectF boundingRect() const;
    void setCurrentIndex(int index);
protected:

    //znazornuje tvar objektu, sluzi na detekcii kolizii
    QPainterPath shape() const;
    //povinna metoda, tu se vykresluje objekt
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int currentIndex;
};

#endif // PLAYER_H
