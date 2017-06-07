#ifndef MOVES_H
#define MOVES_H

#include <QLabel>
#include <QGraphicsPolygonItem>
class Moves: public QGraphicsPolygonItem{
public:
    Moves(QGraphicsItem* parent=NULL);
    void setMoves();
    int getMoves();
private:
    int moves=25;
    QGraphicsTextItem* text;
};

#endif // MOVES_H
