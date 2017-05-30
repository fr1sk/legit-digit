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
    void setGreenColor();//0
    void setRedColor();//1
    void setBlueColor();//2
    void setYellowColor();//3
    void setMagentaColor();//4
    void setCyanColor();//5
private:
    int value;

};

#endif // SQUARE_H
