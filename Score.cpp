#include "Score.h"

Score::Score(QGraphicsItem *parent){
    QVector<QPointF> scorePoints;
    scorePoints << QPointF(0,0) << QPointF(0,0.5) << QPointF(1,0.5) << QPointF(1,0);

    //this->sb = squareB;

    //uvecavamo kvadrat
    int SCALE_BY = 100;
    for (size_t i=0, n=scorePoints.size(); i<n; i++){
        scorePoints[i] *= SCALE_BY;
    }

     QPolygonF Score(scorePoints);
     text = new QGraphicsTextItem(QString::number(score), this);
     int xPos = 50 - text->boundingRect().width()/2;
     int yPos = 35 - text->boundingRect().height()/2;
     text->setPos(xPos,yPos);

     title = new QGraphicsTextItem(QString("Score:"), this);
     int txPos = 50 - title->boundingRect().width()/2;
     int tyPos = 10 - title->boundingRect().height()/2;
     title->setPos(txPos,tyPos);

 setPolygon(Score);
}

void Score::setScore(int sc){
    score=sc;
}
