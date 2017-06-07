#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"

class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);

private:
    Map *map;
};

#endif // VIEW_H
