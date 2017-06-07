#include "view.h"

View::View()
{

}

 View::View(QGraphicsScene *scene){
    setScene(scene);
    map = new Map();
    this->scene()->addItem(map);
    SetBlockIn();
 }

 void View::SetBlockIn()
 {
     for (int i = 0; i <= 20; ++i) {
         for (int j = 0; j <= 20; ++j) {
             if((i == 0 || j == 0) || (i == 20 || j == 20)){
                 BlockIn *blockIn = new BlockIn();
                 blockInList.append(blockIn);
                 blockIn->setPos(i*36,j*36);
                 this->scene()->addItem(blockIn);
             }else if(i%2 ==0 && j%2 == 0){
                 BlockIn *blockIn = new BlockIn();
                 blockInList.append(blockIn);
                 blockIn->setPos(i*36,j*36);
                 this->scene()->addItem(blockIn);
             }
         }
     }
 }

