#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "map.h"
#include "blockin.h"
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
    double movePlayerX;
    double movePlayerY;
    int idTimer;
    void SetBlockIn();
    Map *map;
    QList<BlockIn *> blockInList;

};

#endif // VIEW_H
