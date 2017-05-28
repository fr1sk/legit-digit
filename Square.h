#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsPolygonItem>

class Square: public QGraphicsPolygonItem{
public:
    //konstruktor
    Square(QGraphicsItem* parent=NULL);

    int getValue();
    void setValue(int val);
    void printValue(int x, int y);
    void setColor();
private:
    int value;

};

#endif // SQUARE_H
