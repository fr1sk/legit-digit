#ifndef SCORE_H
#define SCORE_H
#include <QLabel>
#include <QGraphicsPolygonItem>
class Score: public QGraphicsPolygonItem{
public:
    Score(QGraphicsItem* parent=NULL);
    void setScore(int sc);
    int getScore();
    int score = 0;
    QGraphicsTextItem* text;
private:


    QGraphicsTextItem* title;
};

#endif // SCORE_H
