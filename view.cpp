#include "view.h"
#include <QDebug>
#include <QTime>


View::View()
{

}

View::View(QGraphicsScene *scene){
    setScene(scene);//musi byt pred pouzitim this->scene()
    map = new Map();
    this->scene()->addItem(map);

    for (int i = 0; i <= 20; ++i) {
        QList<int> a;
        for (int j = 0; j <= 20; ++j) {
            int b = 0;
            a.append(b);
        }
        blockList.append(a);
    }

    SetBlockIn();
    SetBlockDe();

    CreatePlayer();
    idTimer=startTimer(17);

    qDebug() << blockList;
}

void View::CreatePlayer()
{
    player = new Player();
    this->scene()->addItem(player);
    player->setPos(32,32);

}
void View::timerEvent(QTimerEvent *event)
{
    MovePlayer();
    //viewport()->update();
    time++;
    player->update();
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
    case Qt::Key_Space:
    {
        Bomb *bomb = new Bomb();
        bomb->setPos(player->pos().x(), player->pos().y());
        this->scene()->addItem(bomb);
        break;
    }
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
                blockList[i][j] = 2;
                blockIn->setPos(i*36,j*36);
                this->scene()->addItem(blockIn);
            }else if(i%2 ==0 && j%2 == 0){
                BlockIn *blockIn = new BlockIn();
                blockList[i][j] = 2;
                blockIn->setPos(i*36,j*36);
                this->scene()->addItem(blockIn);
            }
        }
    }
}

void View::SetBlockDe()
{
    srand(QTime::currentTime().msec());
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if((i > 0 && i < 20) && (j > 0 && j < 20) && !(i > 0 && i < 3 && j > 0 && j < 3) && !(i > 17 && i < 20 && j > 17 && j < 20) && ((i%2 == 1) || (j%2 == 1))){
                int r = rand() % 10;
                if(r > 1){
                    BlockDe *blockDe = new BlockDe();
                    blockList[i][j] = 1;
                    blockDe->setPos(i*36,j*36);
                    this->scene()->addItem(blockDe);
                }
            }
        }
    }
}
