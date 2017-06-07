#include "view.h"

View::View()
{

}

 View::View(QGraphicsScene *scene){
    setScene(scene);
    map = new Map();
    this->scene()->addItem(map);
 }

