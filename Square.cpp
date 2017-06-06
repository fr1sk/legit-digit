#include "Square.h"
//#include "SquareBoard.h"
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QtGui>
#include "SquaresList.h"
#include "Game.h"
#include <algorithm>

extern Game *game;

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

    setPolygon(square);


    //center pos for curr obj

}

//Square operator+(const Square& other)
//{
//    Square s = new Square();
//    s.setValue(other.getValue());
//    s.setPosInList(other.getPosInList());
//    return *s;
//}




void mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Custom item clicked.";
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
    //dragHandler = DragHandler::createDragHandler(event /* and other relevant stuff */);
}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    //qInfo() << "X: " << event->scenePos().x() << " Y:" << event->scenePos().y();
    //dragHandler->onMouseMove(event);
    if(event->scenePos().x()>((this->pos().x()+50)+55)){
        qInfo() << "DRAG DESNO";
        if(this->posInList+5 < SquaresList::squares.length()){
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
                    qInfo() << "PUCAJ" << array[z];
                }
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
                }
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
                }
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
                }
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
                }
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
                }
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
                }
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
                }
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
