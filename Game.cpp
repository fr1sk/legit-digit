#include "Game.h"
#include "SquareBoard.h"
#include "Button.h"
#include <QBrush>
#include <QtGui>
#include <QGraphicsTextItem>
#include "SquaresList.h"

extern Game* game;

Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

void Game::back(){
//    for(int i=0; i<SquaresList::SquaresList.squares.length(); i++){
//        SquaresList::SquaresList.squares.pop_back();
//    }

    SquaresList::squares.clear();
        if(SquaresList::squares.isEmpty()){
            qInfo() << "prazna lista";
        }
    game->scene->clear();
    game->displayMainMenu();
}


void Game::start(){
    // clear the screen
    scene->clear();
    //qInfo() << "Custom item clicked.";

    // test code TODO remove
    squareBoard = new SquareBoard();
    squareBoard->placeSquares(120, 120, 7, 5);


    //back button

    Button* backButton = new Button(QString("<-"));
    backButton->redColor();
    int bxPos = 10;
    int byPos = 10;
    backButton->setPos(bxPos,byPos);
    connect(backButton,SIGNAL(clicked()),this,SLOT(back()));
    scene->addItem(backButton);

}

void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Legit Digit"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}


