#include "Moves.h"

Moves::Moves(QGraphicsItem *parent){
    QVector<QPointF> movePoints;
    movePoints << QPointF(0,0) << QPointF(0,0.5) << QPointF(1,0.5) << QPointF(1,0);

    //uvecavamo kvadrat
    int SCALE_BY = 100;
    for (size_t i=0, n=movePoints.size(); i<n; i++){
        movePoints[i] *= SCALE_BY;
    }

     QPolygonF Moves(movePoints);
     text = new QGraphicsTextItem(QString::number(moves), this);
     int xPos = 50 - text->boundingRect().width()/2;
     int yPos = 25 - text->boundingRect().height()/2;
     text->setPos(xPos,yPos);


 setPolygon(Moves);
}

void Moves::setMoves(){
    moves=moves-1;
}

int Moves::getMoves(){
    return moves;
}
