#ifndef MOVES_H
#define MOVES_H

#include <QLabel>
#include <QGraphicsPolygonItem>
class Moves: public QGraphicsPolygonItem{
public:
    Moves(QGraphicsItem* parent=NULL);
    void setMoves();
    int getMoves();
    QGraphicsTextItem* text;
private:
    int moves=25;

};

#endif // MOVES_H
