#include "Game.h"
#include "SquareBoard.h"
Game::Game(QWidget *parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024, 768);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1024, 768);
    setScene(scene);
}

void Game::start(){
    squareBoard = new SquareBoard();
    squareBoard->placeSquares(120, 120, 7, 5);
}
