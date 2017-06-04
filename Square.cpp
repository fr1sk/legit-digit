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
        int inList = this->posInList;
        int xTmp = this->pos().x();
        int yTmp = this->pos().y();
        this->setPos(this->pos().x()+110, this->pos().y());
            SquaresList::squares[this->posInList+5]->setPos(xTmp, yTmp);
        // setSquareNumInList();

        SquaresList::squares[this->posInList+5]->posInList = inList;
        if(SquaresList::squares[this->posInList+5] != NULL)
        std::swap(SquaresList::squares[this->posInList+5],SquaresList::squares[this->posInList]);
        this->posInList = inList+5;




    } if(event->scenePos().x()<((this->pos().x()+50)-55)){
        qInfo() << "DRAG LEVO";
        int inList = this->posInList;
        int xTmp = this->pos().x();
        int yTmp = this->pos().y();
        this->setPos(this->pos().x()-110, this->pos().y());
        SquaresList::squares[this->posInList-5]->setPos(xTmp, yTmp);
        // setSquareNumInList();

        SquaresList::squares[this->posInList-5]->posInList = inList;
        std::swap(SquaresList::squares[this->posInList-5],SquaresList::squares[this->posInList]);
        this->posInList = inList-5;



    } if(event->scenePos().y()>((this->pos().y()+50)+55)){
        qInfo() << "DRAG DOLE";
        int xTmp = this->pos().x();
        int yTmp = this->pos().y();
        this->setPos(this->pos().x(), this->pos().y()+110);
        SquaresList::squares[this->posInList+1]->setPos(xTmp, yTmp);
        std::swap(SquaresList::squares[this->posInList+1],SquaresList::squares[this->posInList]);
        setSquareNumInList();

    } if(event->scenePos().y()<((this->pos().y()+50)-55)){
        qInfo() << "DRAG GORE";
        int xTmp = this->pos().x();
        int yTmp = this->pos().y();
        this->setPos(this->pos().x(), this->pos().y()-110);
        SquaresList::squares[this->posInList-1]->setPos(xTmp, yTmp);
        std::swap(SquaresList::squares[this->posInList-1],SquaresList::squares[this->posInList]);
        setSquareNumInList();
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
