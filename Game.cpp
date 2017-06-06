        #include "Game.h"
    #include "SquareBoard.h"
    #include "Button.h"
    #include "SquaresList.h"
    #include <QBrush>
    #include <QtGui>
    #include <QGraphicsTextItem>
    #include "Score.h"
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
        SquaresList::squares.clear();

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


        Score *score = new Score();
        int txPos = this->width()/2-65;
        int tyPos = 10;
        score->setPos(txPos, tyPos);
        scene->addItem(score);

    }

    void Game::hs(){
          QString val;
          QString dir = QDir::current().absolutePath();
          qWarning() << dir;
          QFile file("../../../../RS16-legit-digit/scores/proba.json");
      //  file.setFileName("/home/milija/Documents/RS/Project/RS16-legit-digit/proba.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();
         //qWarning() << val;
          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();

          sett2.keys().push_back("Zika");
          sett2["Zika"] = "200";

          QJsonDocument doc(sett2);
          QString strJson(doc.toJson(QJsonDocument::Compact));

          qWarning() << strJson;

//          for(kljuc:sett2.keys()){
//            QJsonValue vrednost = sett2.value(QString(kljuc));
//            qWarning() << kljuc << ":" << sett2[kljuc].toString().toInt();
//          }

          file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
          QTextStream stream(&file);
          stream << strJson;
          file.close();


//          QJsonDocument doc(sett2);
//          QString strJson(doc.toJson(QJsonDocument::Compact));

         // QJsonValue value = sett2.value(QString("appName"));
         // qWarning() << value;
         // QJsonObject item = value.toObject();
         // qWarning() << tr("QJsonObject of description: ") << item;

          /* in case of string value get value and convert into string*/
          //qWarning() << tr("QJsonObject[appName] of description: ") << item["Mikic"];
          //QJsonValue subobj = item["Mikic"];
          //qWarning() << subobj.toString();

          /* in case of array get array and convert into string
          qWarning() << tr("QJsonObject[appName] of value: ") << item["imp"];
          QJsonArray test = item["imp"].toArray();
          qWarning() << test[1].toString();*/
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

        Button* highscoreButton = new Button(QString("Highscore"));
        int hxPos = this->width()/2 - highscoreButton->boundingRect().width()/2;
        int hyPos = 350;
        highscoreButton->setPos(hxPos,hyPos);
        connect(highscoreButton,SIGNAL(clicked()),this,SLOT(hs()));
        scene->addItem(highscoreButton);

        // create the quit button
        Button* quitButton = new Button(QString("Quit"));
        int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos = 425;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);
    }


