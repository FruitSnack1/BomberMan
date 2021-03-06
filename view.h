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
#include "explosion.h"
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
    void DeleteBlocks(int x, int y);
    void BlocksAnimation();
    void ExplosionAnimation();
    void CreateExplosion(int x, int y);
    QList<BlockDe *> animation;
    QList<QList<int> > anim;
    QList<QList<int> > inBlockList;
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
    Explosion *explosion;
    int timeBomb =0;
    QPointF bombPos;
    int bombTimer=0;

};


#endif // VIEW_H
