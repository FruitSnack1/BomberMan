#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "player.h"

class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);
protected:
    void timerEvent(QTimerEvent * event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    void CreatePlayer();
     void MovePlayer();
    Player *player;
    double movePlayer;
    int idTimer;
};

#endif // VIEW_H
