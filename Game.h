#ifndef GAME_H
#define GAME_H
#include "SquareBoard.h"
#include<QGraphicsScene>
#include<QGraphicsView>

class Game: public QGraphicsView{
public:
    //konstruktori
    Game(QWidget *parent = NULL);

    //javni atributi, lakse za getovanje i setovanje
    SquareBoard *squareBoard;
    QGraphicsScene *scene;
    //QString whosTurn;

    //javne metode
    void start();
};

#endif // GAME_H
