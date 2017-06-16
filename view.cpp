#include "view.h"
#include <QDebug>
#include <QTime>


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

            blockList[bombPos.x()/36][bombPos.y()/36]->SetCurrentIndex(2);
            timeBomb=0;
        this->scene()->removeItem(bomb);
            bomb=NULL;

            //this->scene()->addLine(bombPos.x()+18,bombPos.y()-18,bombPos.x()+18,bombPos.y()+18+36);
            DeleteBomb(bombPos.x()/36,bombPos.y()/36);

            bombtrue=true;


        }

    }

}
void View::timerEvent(QTimerEvent *event)
{
    MovePlayer();
    UpdateBomb();
    if (bombtrue) {

    }
    //DeleteBomb(bombPos.x()/36,bombPos.y()/36);
    //viewport()->update();
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

void View::DeleteBomb(int x, int y)
{
//    bombTimer++;
//    if (bombTimer==20) {
//        qDebug()<<"pes";
//        qDebug()<<bombTimer;
//    }

    if (blockList[x][y+1]!=NULL) {
        scene()->removeItem(blockList[x][y+1]);

        blockList[x][y+1]=NULL;
        bombtrue=false;
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
