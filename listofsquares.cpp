#include "ListOfSquares.h"

ListOfSquares::ListOfSquares(){

}

static QList<Square *> ListOfSquares::getListOfSquares(){
    return ListOfSquares::squares;
}

static void ListOfSquares::addItem(Square x){
    ListOfSquares::squares.append(x);
}
