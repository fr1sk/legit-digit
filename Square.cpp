#include "Square.h"
//#include "SquareBoard.h"
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QtGui>
#include "SquaresList.h"
#include "Game.h"
#include <algorithm>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

extern Game *game;
//QPropertyAnimation *animation;
//QGraphicsOpacityEffect *mEffect;
//QPropertyAnimation* anim;

Square::Square(QGraphicsItem *parent)//, SquareBoard *squareB)
{
    //crtramo tacke (0,0) (1,0) (1,1) (0,1)
    QVector<QPointF> squarePoints;
    squarePoints << QPointF(0,0) << QPointF(0,1) << QPointF(1,1) << QPointF(1,0);

    //this->sb = squareB;

    //uvecavamo kvadrat
    int SCALE_BY = 100;
    for (size_t i=0, n=squarePoints.size(); i<n; i++){
        squarePoints[i] *= SCALE_BY;
    }

    //pravimo poligon
    QPolygonF square(squarePoints);
    //crtamo poligon

    int MAX_VALUE=6;
        //QDateTime cd = QDateTime::currentDateTime();
        //cd.toTime_t();
        value = qrand() % MAX_VALUE;
        if (value==0)//green
                this->setGreenColor();
        else if (value==1)//red
                this->setRedColor();
        else if (value==2)//blue
                this->setBlueColor();
        else if (value==3)//yellow
                this->setYellowColor();
        else if (value==4)//magenta
                this->setMagentaColor();
        else//cyan
                this->setCyanColor();
        //dodato
        // draw the text
        text = new QGraphicsTextItem(QString::number(value), this);
        int xPos = 50 - text->boundingRect().width()/2;
        int yPos = 50 - text->boundingRect().height()/2;
        text->setPos(xPos,yPos);

//        mEffect = new QGraphicsOpacityEffect();
//        mEffect->setOpacity(1.0);
//        this->setGraphicsEffect(mEffect);



    setPolygon(square);

//    this->setGraphicsEffect(mEffect);
//    animation = new QPropertyAnimation(mEffect,"opacity");

    //center pos for curr obj

}

//Square operator+(const Square& other)
//{
//    Square s = new Square();
//    s.setValue(other.getValue());
//    s.setPosInList(other.getPosInList());
//    return *s;
//}

void Square::hideThisWidget(){
    qInfo() << "hidden";


}


void mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Custom item clicked.";

//    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
//    this->setGraphicsEffect(eff);
//    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
//    a->setDuration(350);
//    a->setStartValue(1);
//    a->setEndValue(0);
//    a->setEasingCurve(QEasingCurve::OutBack);
//    a->start(QPropertyAnimation::DeleteWhenStopped);
//    connect(a,SIGNAL(finished()),this,SLOT(hideThisWidget()));

//    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;

//    animation->setDuration(500);
//    animation->setStartValue(1.0);
//    animation->setEndValue(0.0);
//    //animation->stat(QAbstractAnimation::DeleteWhenStopped);
//    animation->start();

}
/*
void Square::setValue(int val)
{
    int MAX_VALUE=6;
    value = qrand() % MAX_VALUE;
    if (value==0)//green
            this->setGreenColor();
    else if (value==1)//red
            this->setRedColor();
    else if (value==2)//blue
            this->setBlueColor();
    else if (value==3)//yellow
            this->setYellowColor();
    else if (value==4)//magenta
            this->setMagentaColor();
    else//cyan
            this->setCyanColor();
}
*/
int Square::getValue(){
    return value;
}

void Square::setValue(int val){
    this->value = val;
    if (this->value==0)//green
        this->setGreenColor();
    else if (this->value==1)//red
        this->setRedColor();
     else if (this->value==2)//blue
        this->setBlueColor();
     else if (this->value==3)//yellow
        this->setYellowColor();
    else if (this->value==4)//magenta
        this->setMagentaColor();
    else//cyan
        this->setCyanColor();
        //dodato
}

int Square::getPosInList(){
    return posInList;
}

void Square::setPosInList(int pos){
    posInList = pos;
}

void Square::setGreenColor(){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
    setAcceptHoverEvents(false);
}

void Square::setRedColor(){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    setAcceptHoverEvents(false);
}
void Square::setBlueColor(){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
    setAcceptHoverEvents(false);
}
void Square::setYellowColor(){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
    setAcceptHoverEvents(false);
}
void Square::setMagentaColor(){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::magenta);
    setBrush(brush);
    setAcceptHoverEvents(false);
}
void Square::setCyanColor(){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
    setAcceptHoverEvents(false);
}


void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qInfo() << "Value clicked bre: " << this->getValue() << " pos: " << this->pos().x()+50 << this->pos().y()+50;
    qInfo() << "pos in list: " << this->posInList << "pos in Qlist: ";
//    anim = new QPropertyAnimation(mEffect, "opacity");
//    anim->setDuration(2000);
//    anim->setStartValue(1.0);
//    anim->setEndValue(0.0);
    //anim->setEasingCurve(QEasingCurve::OutCubic);
    //anim->start();
    //dragHandler = DragHandler::createDragHandler(event /* and other relevant stuff */);
}


void Square::moveAlgorithm(){
    if(game->moves->getMoves()>1){
        game->moves->setMoves();
        game->scene->removeItem(game->moves->text);
        game->moves->text = new QGraphicsTextItem(QString::number(game->moves->getMoves()), game->moves);
        int xPos = 50 - game->moves->text->boundingRect().width()/2;
        int yPos = 25 - game->moves->text->boundingRect().height()/2;
        game->moves->text->setPos(xPos,yPos);
    } else {
        game->scene->clear();
        qInfo() << "KRAJ BURAZ";
    }
}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    //qInfo() << "X: " << event->scenePos().x() << " Y:" << event->scenePos().y();
    //dragHandler->onMouseMove(event);
    if(event->scenePos().x()>((this->pos().x()+50)+55)){
        qInfo() << "DRAG DESNO";
        if(this->posInList+5 < SquaresList::squares.length()){
            moveAlgorithm();
            int inList = this->posInList;
            int xTmp = this->pos().x();
            int yTmp = this->pos().y();
            this->setPos(this->pos().x()+110, this->pos().y());
            SquaresList::squares[this->posInList+5]->setPos(xTmp, yTmp);
            // setSquareNumInList();

            SquaresList::squares[this->posInList+5]->posInList = inList;
            std::swap(SquaresList::squares[this->posInList+5],SquaresList::squares[this->posInList]);
            this->posInList = inList+5;
            algCheck();
        }



    } if(event->scenePos().x()<((this->pos().x()+50)-55)){
        qInfo() << "DRAG LEVO";
        if(this->posInList-5 >= 0){
            moveAlgorithm();

            int inList = this->posInList;
            int xTmp = this->pos().x();
            int yTmp = this->pos().y();
            this->setPos(this->pos().x()-110, this->pos().y());
            SquaresList::squares[this->posInList-5]->setPos(xTmp, yTmp);
            // setSquareNumInList();

            SquaresList::squares[this->posInList-5]->posInList = inList;
            std::swap(SquaresList::squares[this->posInList-5],SquaresList::squares[this->posInList]);
            this->posInList = inList-5;
            algCheck();
        }




    } if(event->scenePos().y()>((this->pos().y()+50)+55)){
        qInfo() << "DRAG DOLE";
        if((this->posInList+1)%5!=0){
            moveAlgorithm();
            int xTmp = this->pos().x();
            int yTmp = this->pos().y();
            this->setPos(this->pos().x(), this->pos().y()+110);
            SquaresList::squares[this->posInList+1]->setPos(xTmp, yTmp);
            std::swap(SquaresList::squares[this->posInList+1],SquaresList::squares[this->posInList]);
            setSquareNumInList();
            algCheck();
        }


    } if(event->scenePos().y()<((this->pos().y()+50)-55)){
        qInfo() << "DRAG GORE";
        if(this->posInList%5!=0){
            moveAlgorithm();
            int xTmp = this->pos().x();
            int yTmp = this->pos().y();
            this->setPos(this->pos().x(), this->pos().y()-110);
            SquaresList::squares[this->posInList-1]->setPos(xTmp, yTmp);
            std::swap(SquaresList::squares[this->posInList-1],SquaresList::squares[this->posInList]);
            setSquareNumInList();
            algCheck();
        }

    }

    //qInfo() << "Y misa: " << event->scenePos().y() << " Y objekta " << this->pos().y();
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //qInfo() << "Value released: " << this->getValue();
    //dragHandler->onMouseRelease(event);
    //delete dragHandler;
}




void Square::setSquareNumInList(){
    int i=0;
    qInfo() << "INIT POS: " << SquaresList::squares.size();
    for (auto j = SquaresList::squares.begin(); j != SquaresList::squares.end(); ++j)
    {
            (*j)->setPosInList(i);
            i++;
    }
}

void Square::algCheck(){
    qInfo() << "ALG CHECK CALLED";
    int j, k, l;
    int cnt = 0;
    int sum = game->score->getScore();
    int sumTmp = 0;
    int array[35];
//========================= horizontalno +1 ===============================
    for(int i=0; i<SquaresList::squares.length(); i++){
       //qInfo() << "vrednost na i: " << SquaresList::squares[i]->getValue() << " a i je: " << i;
        j = i + 5;
        k = i;
        l = i % 5;
        array[cnt++] = k;
        while(j<=SquaresList::squares.length()-5+1+l && SquaresList::squares[j]->getValue() - SquaresList::squares[k]->getValue() == 1){
            array[cnt++] = j;
            j = j + 5;
            k = k + 5;
        }
        if(j>SquaresList::squares.length()-5+1+l){
            if(cnt>=3){
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ NESTAJ" << array[z];
                    //====score========
                     sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();

                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);

                qInfo() << "score: " << game->score->getScore() << " sum: " <<sum;
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = - 1;
            } else {
                memset(array, -1, sizeof(array));
                cnt = 0;
            }
        } else {
            if(cnt>=3){
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ NESTAJ" << array[z];
                    //====score========
                    sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();
                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);
                qInfo() << "score: " << game->score->getScore() << " sum: " <<sum;
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = - 1;

            } else {
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = j-1;
            }
        }
    }




//========================= horizontalno -1 ===============================
        memset(array, -1, sizeof(array));
        cnt = 0;
    for(int i=0; i<SquaresList::squares.length(); i++){
        //qInfo() << "vrednost na i: " << SquaresList::squares[i]->getValue() << " a i je: " << i;
        j = i + 5;
        k = i;
        l = i % 5;
        array[cnt++] = k;
        while(j<=SquaresList::squares.length()-5+1+l && SquaresList::squares[j]->getValue() - SquaresList::squares[k]->getValue() == -1){
            array[cnt++] = j;
            j = j + 5;
            k = k + 5;
        }
        if(j>SquaresList::squares.length()-5+1+l){
            if(cnt>=3){
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ" << array[z];
                    //====score========
                     sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    //setScore(array);
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();


                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = - 1;
            } else {
               memset(array, -1, sizeof(array));
               cnt = 0;
            }
        } else {
            if(cnt>=3){
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ" << array[z];
                    //====score========
                     sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();

                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = - 1;

            } else {
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = j-1;
            }
        }
    }
//========================= vertikalno +1 ===============================
    memset(array, -1, sizeof(array));
    cnt = 0;
    for (int i=0;i<SquaresList::squares.length();i++){
        j=i+1;
        k=i;
        cnt = 0;
        array[cnt++]=k;
        while (j <= (i+5-(i%5)-1) && SquaresList::squares[j]->getValue() - SquaresList::squares[k]->getValue() == 1){
            array[cnt++]=j;
            j=j+1;
            k=k+1;
        }
        if (j > (i+5-(i%5)-1)){ //dosli smo do dole do kraja
            if (cnt >= 3){ //da li ima dovoljno za pucanje
                //pucaju svi indeksi iz niza
                //prazni se niz
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ" << array[z];
                    //====score========
                     sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();


                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = -1; krece iz pocekta, ili 0 ili -1, kada zaista puknu
            }
            else { //nema dovoljno u nizu a dosli do kraja, samo praznimo niz nista se ne desava
                memset(array, -1, sizeof(array));
                cnt = 0;
            }

        } else { //razlika izmedju dva vise nije 1
            if (cnt >= 3) {
                //pucaju svi iz niza
                //praznimo niz
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ" << array[z];
                    //====score========
                     sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();


                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = -1; kada zaista puknu
            } else {
                //praznimo niz
                memset(array, -1, sizeof(array));
                cnt = 0;
            }

        }
    }
//========================= vertikalno -1 ===============================
    memset(array, -1, sizeof(array));
    cnt = 0;
    for (int i=0;i<SquaresList::squares.length();i++){
        j=i+1;
        k=i;
        cnt = 0;
        array[cnt++]=k;
        while (j <= (i+5-(i%5)-1) && SquaresList::squares[j]->getValue() - SquaresList::squares[k]->getValue() == -1){
            array[cnt++]=j;
            j=j+1;
            k=k+1;
        }
        if (j > (i+5-(i%5)-1)){ //dosli smo do dole do kraja
            if (cnt >= 3){ //da li ima dovoljno za pucanje
                //pucaju svi indeksi iz niza
                //prazni se niz
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ" << array[z];
                    //====score========
                     sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();


                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = -1; krece iz pocekta, ili 0 ili -1, kada zaista puknu
            }
            else { //nema dovoljno u nizu a dosli do kraja, samo praznimo niz nista se ne desava
                memset(array, -1, sizeof(array));
                cnt = 0;
            }

        } else { //razlika izmedju dva vise nije 1
            if (cnt >= 3) {
                //pucaju svi iz niza
                //praznimo niz
                for(int z=0; z<cnt; z++){
                    qInfo() << "PUCAJ" << array[z];
                    //====score========
                     sumTmp += SquaresList::squares[array[z]]->getValue();

                    //====end score====
                    QGraphicsOpacityEffect *mEffect = new QGraphicsOpacityEffect();
                    mEffect->setOpacity(1.0);
                    SquaresList::squares[array[z]]->setGraphicsEffect(mEffect);
                    QPropertyAnimation *anim = new QPropertyAnimation(mEffect, "opacity");
                    anim->setDuration(2000);
                    anim->setStartValue(1.0);
                    anim->setEndValue(0.0);
                    anim->start();
                    //delete(this->text);
                    game->scene->removeItem(SquaresList::squares[array[z]]->text);
                    SquaresList::squares[array[z]]->setValue(qrand() % 6);

                    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(SquaresList::squares[array[z]]->getValue()), SquaresList::squares[array[z]]);
                    SquaresList::squares[array[z]]->text = text;
                    int xPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().width()/2;
                    int yPos = 50 - SquaresList::squares[array[z]]->text->boundingRect().height()/2;
                    text->setPos(xPos,yPos);

                    anim->setDuration(2000);
                    anim->setStartValue(0.0);
                    anim->setEndValue(1.0);
                    anim->start();


                }
                sum += cnt*sumTmp;
                sumTmp = 0;
                game->score->setScore(sum);
                game->scene->removeItem(game->score->text);
                game->score->text = new QGraphicsTextItem(QString::number(game->score->getScore()), game->score);
                int xPos = 50 - game->score->text->boundingRect().width()/2;
                int yPos = 35 - game->score->text->boundingRect().height()/2;
                game->score->text->setPos(xPos,yPos);
                qInfo() << "=================";
                memset(array, -1, sizeof(array));
                cnt = 0;
                //i = -1; kada zaista puknu
            } else {
                //praznimo niz
                memset(array, -1, sizeof(array));
                cnt = 0;
            }

        }
    }
}
