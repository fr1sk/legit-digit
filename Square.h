#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsPolygonItem>
//#include <SquareBoard.h>


class Square: public QGraphicsPolygonItem{
public:
    //konstruktor
    Square(QGraphicsItem* parent=NULL);//, SquareBoard* squareB);

    int getValue();
    //void setValue(int val);
    int getPosInList();
    void setPosInList(int pos);
    void setGreenColor();//0
    void setRedColor();//1
    void setBlueColor();//2
    void setYellowColor();//3
    void setMagentaColor();//4
    void setCyanColor();//5
    void setSquareNumInList();
    void algCheck();
    void hideThisWidget();
    QGraphicsTextItem* text;
    //Square operator+(const Square& other);

    //SquareBoard sb;
private:
    int value;
    int posInList;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};


#endif // SQUARE_H

