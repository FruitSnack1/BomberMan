#include "view.h"
#include <QDebug>
#include <QTime>
#include <QList>

View::View()
{

}

View::View(QGraphicsScene *scene){
    setScene(scene);//musi byt pred pouzitim this->scene()
    //map = new Map();
    //this->scene()->addItem(map);

    for (int i = 0; i <= 20; ++i) {
        QList<BlockDe *> a;
        for (int j = 0; j <= 20; ++j) {
            BlockDe *b = NULL;
            a.append(b);
        }
        blockList.append(a);
    }

    SetBlockIn();
    SetBlockDe();

    CreatePlayer();
    idTimer=startTimer(17);

    for (int i = 0; i <= 20; ++i) {
        QList<int> a;
        for (int j = 0; j <= 20; ++j) {
            int b = -1;
            a.append(b);
        }
        anim.append(a);
    }
    qDebug() << anim;

}

void View::CreatePlayer()
{
    player = new Player();
    this->scene()->addItem(player);
    player->setPos(38,38);

}

void View::CreateBomb()
{

    bomb = new Bomb();

    bombPos.setX(((int)(player->pos().x()+player->boundingRect().width()/2)/36)*36);
    bombPos.setY(((int)((player->pos().y()+player->boundingRect().height()/2)+18)/36)*36);
    qDebug()<<bombPos;
    bomb->setPos(bombPos);
    this->scene()->addItem(bomb);


}

void View::UpdateBomb()
{
    if (bomb) {
        bomb->update();
        timeBomb++;
        if (timeBomb>40&&timeBomb<80) {
            bomb->SetCurrentIndex(1);
        }
        if (timeBomb>80&&timeBomb<120) {
            bomb->SetCurrentIndex(2);
            //qDebug() << blockList;
        }
        if (timeBomb>120) {
            bomb->SetCurrentIndex(0);
            DeleteBlocks(bomb->pos().x()/36, bomb->pos().y()/36);
            timeBomb=0;
            this->scene()->removeItem(bomb);
            bomb=NULL;

        }

    }

}
void View::timerEvent(QTimerEvent *event)
{
    MovePlayer();
    UpdateBomb();
    BlocksAnimation();

    time++;

    player->update();
}

void View::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        //qDebug() << "left";

        movePlayerX = -2;
        if ((time/5)%2==0) {
            player->setCurrentIndex(11);

        }else{
            player->setCurrentIndex(10);
        }
        break;
    case Qt::Key_Down:
        //() << "left";
        movePlayerY = 2;
        if ((time/5)%2==0) {
            player->setCurrentIndex(2);


        }else{
            player->setCurrentIndex(1);
        }
        break;
    case Qt::Key_Up:
        //qDebug() << "left";
        movePlayerY = -2;
        if ((time/5)%2==0) {
            player->setCurrentIndex(4);

        }else{
            player->setCurrentIndex(5);
        }
        break;
    case Qt::Key_Right:
        //qDebug() << "right";
        movePlayerX = 2;
        if ((time/5)%2==0) {
            player->setCurrentIndex(7);

        }else{
            player->setCurrentIndex(8);
        }
        //player->setCurrentIndex(2);
        //pohyb pomoci currentTime
        break;
    case Qt::Key_Space:
    {

        if (timeBomb==0) {
            qDebug()<<"bomb";
        CreateBomb();

        }


        break;

    }
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
    if (player->Kolize()) {
        player->setPos(player->pos() - smer);
        //player->setPos(player->pos() - smer);
    }
    player->Kolize();
    //player->setPos(player->pos() + smer);

}

void View::DeleteBlocks(int x, int y)
{
    if (blockList[x][y+1]!=NULL){
        anim[0][0] = x;
        anim[0][1] = y+1;
    };
    if (blockList[x][y-1]!=NULL){
        anim[1][0] = x;
        anim[1][1] = y-1;
    };
    if (blockList[x+1][y]!=NULL){
        anim[2][0] = x+1;
        anim[2][1] = y;
    };
    if (blockList[x-1][y]!=NULL){
        anim[3][0] = x-1;
        anim[3][1] = y;
    };
}

void View::BlocksAnimation()
{
    for (int i = 0; i < anim.length(); ++i) {
        if(anim[i][0] != -1){
            int x = anim[i][0];
            int y = anim[i][1];
            blockList[x][y]->timer++;
            if(blockList[x][y]->timer > 16){
                this->scene()->removeItem(blockList[x][y]);
                blockList[x][y] = NULL;
                anim[i][0] = -1;
                anim[i][1] = -1;
            }else if(blockList[x][y]->timer%2){
                blockList[x][y]->SetCurrentIndex(blockList[x][y]->timer/2+1);
                blockList[x][y]->update();
            }
        }
    }
}
void View::SetBlockIn(){
    for (int i = 0; i <= 20; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if((i == 0 || j == 0) || (i == 20 || j == 20)){
                BlockIn *blockIn = new BlockIn();
                //blockList[i][j] = blockIn;
                blockIn->setPos(i*36,j*36);
                this->scene()->addItem(blockIn);
            }else if(i%2 ==0 && j%2 == 0){
                BlockIn *blockIn = new BlockIn();
               // blockList[i][j] = blockIn;
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
                    blockList[i][j] = blockDe;
                    blockDe->setPos(i*36,j*36);
                    this->scene()->addItem(blockDe);
                }
            }
        }
    }
}

QList<QList<QGraphicsItem *> > View::getBlockList() const
{
    //return blockList;
}

void View::setBlockList(const QList<QList<QGraphicsItem *> > &value)
{
    //blockList = value;
}
