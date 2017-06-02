#ifndef LISTOFSQUARES_H
#define LISTOFSQUARES_H

#include "Square.h"

class ListOfSquares
{
public:
    static QList<Square *> getListOfSquares();
    static void addItem(Square x);


private:
    ListOfSquares();


protected:
    QList<Square*> squares;

#endif // LISTOFSQUARES_H

