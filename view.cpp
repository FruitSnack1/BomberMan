#include "view.h"
#include <QDebug>


View::View()
{

}

 View::View(QGraphicsScene *scene){
     setScene(scene);//musi byt pred pouzitim this->scene()
    int width = 800;
    int height = 600;


     this->scene()->addRect(0,0,width,height,
         QPen(Qt::black),QBrush(QColor(230,230,230)));
    CreatePlayer();
    idTimer=startTimer(10);
 }

 void View::CreatePlayer()
 {
     player = new Player();
     this->scene()->addItem(player);
     player->setPos(0,0);

 }
 void View::timerEvent(QTimerEvent *event)
 {
     MovePlayer();
 }

 void View::keyPressEvent(QKeyEvent *event)
 {
     switch (event->key()) {
     case Qt::Key_Left:
         qDebug() << "left";
         movePlayer = -10;
         break;
     case Qt::Key_Right:
         qDebug() << "right";
         movePlayer = 10;
         player->setCurrentIndex(2);
         //pohyb pomoci currentTime
         break;

     default:
         break;
     } ;
 }

 void View::keyReleaseEvent(QKeyEvent *event)
 {switch (event->key()) {
     case Qt::Key_Left:
         qDebug() << "left";
         movePlayer = 0;


         break;
     case Qt::Key_Right:
         qDebug() << "right";
         movePlayer = 0;
         break;

     default:
         break;
     } ;

 }
 void View::MovePlayer()
 {
     //movePlayer
     QPointF smer(movePlayer,0);
     if(movePlayer!=0) {
         if(movePlayer < 0 && player->pos().x() + movePlayer > 0 ) {
             player->setPos(player->pos() + smer);
         } else if(movePlayer > 0 && player->pos().x() + movePlayer<
                   width() - player->boundingRect().width()) {
             player->setPos(player->pos() + smer);
         }

     }
 }
