#include "SquaresList.h"
#include "Square.h"
#include <QtGui>
#include <QList>

SquaresList::SquaresList()
{
}
//MyClass::MyClass() : list(QList<MyStuff*> ())
QList<Square*> SquaresList::squares;
//QList<Square *> SquaresList::getListOfSquares(){
//    return SquaresList::squares;
//}

//void SquaresList::addItem(const Square &x){
//    SquaresList::squares.push_back(x);
//}
