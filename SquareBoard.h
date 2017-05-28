#ifndef SQUAREBOARD_H
#define SQUAREBOARD_H

#include <QList>
#include "Square.h"


class SquareBoard{
public:
    //konstruktori
    SquareBoard();

    //geteri i seteri
    QList<Square *> getSquares();
    void setSquares(QList<Square*> squares);

    //metodi
    void placeSquares(int x, int y, int cols, int rows);
private:
    QList<Square*> squares;

    //privatan metod, treba nam samo za squareBoard
    void createSquareColumn(int x, int y, int numOfRows);
};

#endif // SQUAREBOARD_H
