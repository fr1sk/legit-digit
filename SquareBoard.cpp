#include "SquareBoard.h"
#include "Game.h"
#include "SquaresList.h"
#include <QList>
#include <QtGui>

extern Game* game;
SquareBoard::SquareBoard(){

}

//QList<Square *> SquareBoard::getSquares(){
//    return squares;
//}

void SquareBoard::placeSquares(int x, int y, int cols, int rows){
    int xShift=110;

    for (size_t i=0, n=cols; i<n; i++){
        createSquareColumn(x+xShift*i, y, rows);
    }
    setSquareNumInList();
}

void SquareBoard::createSquareColumn(int x, int y, int numOfRows){
    int yShift=110;
    //pravi kolonu kvadrata na odredjenoj pozociji sa odredjenim brojem redova
    for(size_t i=0,n=numOfRows; i<n; i++){
        Square* square = new Square();
        square->setValue(10);
        //square->setPosInList(i+1);
        //square->printValue(x+yShift/3.2, y+yShift*i+yShift/3.8);
        square->setPos(x,y+yShift*i);//pomeramo na dole za 60 (60 je velicina kvadrata)
        //ListOfSquares::addItem(square);
        //squares.append(square);
        SquaresList::squares.append(square);
        game->scene->addItem(square);
        square->printValue(x+yShift/3.2, y+yShift*i+yShift/3.8);
    }
}

void SquareBoard::setSquareNumInList(){
    int i=0;
    qInfo() << "list size: " << SquaresList::squares.size();
    for (auto j = SquaresList::squares.begin(); j != SquaresList::squares.end(); ++j)
    {
            (*j)->setPosInList(i);
            i++;
    }
}

//void SquareBoard::swapSquares(){
//    Square* a = squares[1];
////    a->setValue(squares[1]->getValue());
////    a->setPosInList(squares[1]->getPosInList());
//    squares[1] = squares[2];
//    squares[2] = a;
//    qInfo() << "swap";
//}


