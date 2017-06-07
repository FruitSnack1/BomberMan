#include "view.h"
#include <QDebug>


View::View()
{

}

View::View(QGraphicsScene *scene){
    setScene(scene);//musi byt pred pouzitim this->scene()
    map = new Map();
    this->scene()->addItem(map);
    SetBlockIn();
    CreatePlayer();
    idTimer=startTimer(17);
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
    viewport()->update();
    time++;
}

void View::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        //qDebug() << "left";
        movePlayerX = -5;
        if ((time/5)%2==0) {
            player->setCurrentIndex(11);

        }else{
        player->setCurrentIndex(10);
        }
        break;
    case Qt::Key_Down:
        //() << "left";
        movePlayerY = 5;
        if ((time/5)%2==0) {
            player->setCurrentIndex(2);

        }else{
        player->setCurrentIndex(1);
        }
        break;
    case Qt::Key_Up:
        //qDebug() << "left";
        movePlayerY = -5;
        if ((time/5)%2==0) {
            player->setCurrentIndex(4);

        }else{
        player->setCurrentIndex(5);
        }
        break;
    case Qt::Key_Right:
        //qDebug() << "right";
        movePlayerX = 5;
        if ((time/5)%2==0) {
            player->setCurrentIndex(7);

        }else{
        player->setCurrentIndex(8);
        }
        //player->setCurrentIndex(2);
        //pohyb pomoci currentTime
        break;

    default:
        break;
    } ;
}

void View::keyReleaseEvent(QKeyEvent *event)
{switch (event->key()) {
    case Qt::Key_Left:
        //qDebug() << "left";
        movePlayerX = 0;
        player->setCurrentIndex(9);
        break;
    case Qt::Key_Up:
        //qDebug() << "left";
        movePlayerY = 0;
        player->setCurrentIndex(3);
        break;
    case Qt::Key_Down:
        //qDebug() << "left";
        movePlayerY = 0;
        player->setCurrentIndex(0);
        break;
    case Qt::Key_Right:
        //qDebug() << "right";
        movePlayerX = 0;
        player->setCurrentIndex(6);
        break;

    default:
        break;
    } ;

}
void View::MovePlayer()
{
    //movePlayerX
    QPointF smer(movePlayerX,movePlayerY);
    player->setPos(player->pos() + smer);

}
void View::SetBlockIn(){

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
