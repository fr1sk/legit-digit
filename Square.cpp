#include "Square.h"
#include <QGraphicsTextItem>
#include "Game.h"

extern Game *game;

Square::Square(QGraphicsItem *parent)
{
    //crtramo tacke (0,0) (1,0) (1,1) (0,1)
    QVector<QPointF> squarePoints;
    squarePoints << QPointF(0,0) << QPointF(0,1) << QPointF(1,1) << QPointF(1,0);

    //uvecavamo kvadrat
    int SCALE_BY = 100;
    for (size_t i=0, n=squarePoints.size(); i<n; i++){
        squarePoints[i] *= SCALE_BY;
    }

    //pravimo poligon
    QPolygonF square(squarePoints);
    //crtamo poligon
    setPolygon(square);
}

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
int Square::getValue(){
    return value;
}

void Square::printValue(int x, int y){
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setScale(2.0);
    io->setPos(x,y);
    QString stringVal = QString::number(value);
    io->setPlainText(stringVal);
    io->setOpacity(1);
    game->scene->addItem(io);
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
