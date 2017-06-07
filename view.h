#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"
#include "blockin.h"

class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);

private:
    void SetBlockIn();
    Map *map;
    QList<BlockIn *> blockInList;

};

#endif // VIEW_H
