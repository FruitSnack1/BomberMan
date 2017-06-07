#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>

class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);
};

#endif // VIEW_H
