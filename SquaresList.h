#ifndef SQUARESLIST_H
#define SQUARESLIST_H
#include "Square.h"
#include <QtGui>
#include <QList>

class SquaresList
{

public:
    //static QList<Square *> getListOfSquares();
    //static void addItem(const Square &x);

    SquaresList();
    static QList<Square*> squares;


};

#endif // SQUARESLIST_H


