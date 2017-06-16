#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "map.h"
#include "blockin.h"
#include "blockde.h"
#include "player.h"
#include "bomb.h"
#include <QPainter>


class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);
    QList<QList<QGraphicsItem *> > getBlockList() const;
    void setBlockList(const QList<QList<QGraphicsItem *> > &value);

protected:
    void timerEvent(QTimerEvent * event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    void CreatePlayer();
    void CreateBomb();
    void UpdateBomb();
    void MovePlayer();
    void DeleteBomb(int x, int y);
    Player *player;
    double movePlayerX;
    double movePlayerY;
    int idTimer;
    void SetBlockIn();
    void SetBlockDe();
    Map *map;
    QList<QList<BlockDe *> > blockList;
    int time;
    Bomb *bomb;
    int timeBomb =0;
    QPointF bombPos;
    bool bombtrue=false;
    int bombTimer=0;

};


#endif // VIEW_H
