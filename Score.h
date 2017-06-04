#ifndef SCORE_H
#define SCORE_H
#include <QLabel>
#include <QGraphicsPolygonItem>
class Score: public QGraphicsPolygonItem{
public:
    Score(QGraphicsItem* parent=NULL);
    void setScore(int sc);
    void getScore();
private:
    int score=102010;
    QGraphicsTextItem* text;
    QGraphicsTextItem* title;
};

#endif // SCORE_H
