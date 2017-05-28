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
}

void Square::printValue(int x, int y){
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setScale(2.0);
    io->setPos(x,y);
    QString stringVal = QString::number(value);
    io->setPlainText(stringVal);
    game->scene->addItem(io);
}

void Square::setColor(){

}
