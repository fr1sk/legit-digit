    #include "Game.h"
    #include "SquareBoard.h"
    #include "Button.h"
    #include "SquaresList.h"
    #include <QBrush>
    #include <QtGui>
    #include <QGraphicsTextItem>
    #include "Score.h"
    #include "SquaresList.h"
    #include "Moves.h"
    #include <QLineEdit>
    #include <QTextEdit>
    #include<QVBoxLayout>
    #include<QPushButton>
    #include <algorithm>
    #include <QString>
    #include <QLabel>
    #include <QLineEdit>
    #include <QPushButton>

    extern Game* game;
    Game::Game(QWidget *parent){
        // set up the screen
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(1024,768);

        // set up the scene
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,1024,768);
        QBrush brush(QColor(0x20, 0x50, 0x40, 255));
        scene->setBackgroundBrush(brush);
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



    void Game::insertScore(){
        QLayout * vbox = new QVBoxLayout();
        QGraphicsView * view = new QGraphicsView();
        QLineEdit *line = new QLineEdit();

        line->setPlaceholderText("Unesite ime");
        QPushButton *butt = new QPushButton();
        butt->setFixedSize(100, 20);
        butt->setText("Unesi");
        vbox->addWidget(line);
        vbox->addWidget(butt);
        QString string = line->text();


        QWidget * w = new QWidget();
        connect(butt, SIGNAL(clicked()), w, SLOT(getValueOfArea(string)));
        w->setLayout(vbox);
        w->show();
        //scene->addItem(line);
    }


    void Game::start(){
        // clear the screen
        scene->clear();
        //qInfo() << "Custom item clicked.";

        // test code TODO remove
        squareBoard = new SquareBoard();
        squareBoard->placeSquares(120, 120, 7, 5);


        //back button

        Button* backButton = new Button(QString("Back"));
        backButton->redColor();
        int bxPos = 10;
        int byPos = 10;
        backButton->setPos(bxPos,byPos);
        connect(backButton,SIGNAL(clicked()),this,SLOT(back()));
        scene->addItem(backButton);


        score = new Score();
        int txPos = this->width()/2-65;
        int tyPos = 10;
        score->setPos(txPos, tyPos);
        scene->addItem(score);

        moves = new Moves();
        int movX = this->width()-245;
        int movY = 10;
        moves->setPos(movX, movY);
        scene->addItem(moves);


    }

    void Game::displayHighscores(){
          scene->clear();
            /*LIST OF HIGHSCORES BEGIN*/
          //insertHighscore(QString("Padre"),QString("900"));

          int mv=50;
          int i=1;

          QString val;

          //QFile file("../RS16-legit-digit/scores/proba.json");

          QString dir = QDir::current().absolutePath();
          qWarning() << dir;

          QFile file("../../../rezultati.json");


      //  file.setFileName("/home/milija/Documents/RS/Project/RS16-legit-digit/proba.json");
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          val = file.readAll();
          file.close();
         //qWarning() << val;
          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject sett2 = d.object();


//          for(kljuc:sett2.keys()){
//            QJsonValue vrednost = sett2.value(QString(kljuc));
//            qWarning() << kljuc << ":" << sett2[kljuc].toString().toInt();
//          }

         // qWarning() << sett2.keys().at(0);


          /*PLAYERS BEGIN*/

          QStringList keysList = sett2.keys();
          QStringList valueList;



          QStringList::iterator j = keysList.begin();
          for(j;j!=keysList.end();j++){
              QString pom = *j;
             // qWarning() << pom;
              //              QString pom = sett2[j];
              valueList.push_back(sett2[pom].toString());
          }
          QStringList valueListCopy = valueList;
          qSort(valueListCopy.rbegin(), valueListCopy.rend());


          /*algoritam pocetak*/
          QStringList sortedKeys;

         // qWarning() << valueListCopy;

          //QString::iterator k = valueListCopy.begin();
          int posl;
          for(int k=0;k<valueListCopy.length();k++){
            posl = valueList.indexOf(valueListCopy.at(k));
            sortedKeys.push_back(keysList[posl]);
          // qWarning() << sortedKeys[k] << ": " << valueListCopy[k];
          }

          /*algoritam kraj*/
          //qWarning() << valueList;
         // qWarning() << valueList;
          //qWarning() << valueList;
          //qWarning() << keysList;
          Button* prvi = new Button(QString(sortedKeys[0]));
          int prvixPos = this->width()/2 - prvi->boundingRect().width();
          int prviyPos = mv;
          prvi->setPos(prvixPos,prviyPos);
          prvi->whiteColor();
          scene->addItem(prvi);

          Button* drugi = new Button(QString(sortedKeys[i]));
          int drugixPos = this->width()/2 - drugi->boundingRect().width();
          int drugiyPos = mv+i*mv;
          i++;
          drugi->setPos(drugixPos,drugiyPos);
          drugi->whiteColor();
          scene->addItem(drugi);

          Button* treci = new Button(QString(sortedKeys[i]));
          int trecixPos = this->width()/2 - treci->boundingRect().width();
          int treciyPos = mv+i*mv;
          i++;
          treci->setPos(trecixPos,treciyPos);
          treci->whiteColor();
          scene->addItem(treci);

          Button* cetvrti = new Button(QString(sortedKeys[i]));
          int cetvrtixPos = this->width()/2 - cetvrti->boundingRect().width();
          int cetvrtiyPos = mv+i*mv;
          i++;
          cetvrti->setPos(cetvrtixPos,cetvrtiyPos);
          cetvrti->whiteColor();
          scene->addItem(cetvrti);

          Button* peti = new Button(QString(sortedKeys[i]));
          int petixPos = this->width()/2 - peti->boundingRect().width();
          int petiyPos = mv+i*mv;
          i++;
          peti->setPos(petixPos,petiyPos);
          peti->whiteColor();
          scene->addItem(peti);

          Button* sesti = new Button(QString(sortedKeys[i]));
          int sestixPos = this->width()/2 - sesti->boundingRect().width();
          int sestiyPos = mv+i*mv;
          i++;
          sesti->setPos(sestixPos,sestiyPos);
          sesti->whiteColor();
          scene->addItem(sesti);

          Button* sedmi = new Button(QString(sortedKeys[i]));
          int sedmixPos = this->width()/2 - sedmi->boundingRect().width();
          int sedmiyPos = mv+i*mv;
          i++;
          sedmi->setPos(sedmixPos,sedmiyPos);
          sedmi->whiteColor();
          scene->addItem(sedmi);

          Button* osmi = new Button(QString(sortedKeys[i]));
          int osmixPos = this->width()/2 - osmi->boundingRect().width();
          int osmiyPos = mv+i*mv;
          i++;
          osmi->setPos(osmixPos,osmiyPos);
          osmi->whiteColor();
          scene->addItem(osmi);

          Button* deveti = new Button(QString(sortedKeys[i]));
          int devetixPos = this->width()/2 - deveti->boundingRect().width();
          int devetiyPos = mv+i*mv;
          i++;
          deveti->setPos(devetixPos,devetiyPos);
          deveti->whiteColor();
          scene->addItem(deveti);

          Button* deseti = new Button(QString(sortedKeys[i]));
          int desetixPos = this->width()/2 - deseti->boundingRect().width();
          int desetiyPos = mv+i*mv;
          i++;
          deseti->setPos(desetixPos,desetiyPos);
          deseti->whiteColor();
          scene->addItem(deseti);
          /*PLAYERS END*/

          /*SCORES BEGIN*/
          i=1;
          Button* prviV = new Button(QString(valueListCopy[0]));
          int prvixPosV = this->width()/2;
          int prviyPosV = mv;
          prviV->setPos(prvixPosV,prviyPosV);
          prviV->whiteColor();
          scene->addItem(prviV);

          Button* drugiV = new Button(QString(valueListCopy[i]));
          int drugiVxPos = this->width()/2;
          int drugiVyPos = mv+i*mv;
          i++;
          drugiV->setPos(drugiVxPos,drugiVyPos);
          drugiV->whiteColor();
          scene->addItem(drugiV);

          Button* treciV = new Button(QString(valueListCopy[i]));
          int treciVxPos = this->width()/2;
          int treciVyPos = mv+i*mv;
          i++;
          treciV->setPos(treciVxPos,treciVyPos);
          treciV->whiteColor();
          scene->addItem(treciV);

          Button* cetvrtiV = new Button(QString(valueListCopy[i]));
          int cetvrtiVxPos = this->width()/2;
          int cetvrtiVyPos = mv+i*mv;
          i++;
          cetvrtiV->setPos(cetvrtiVxPos,cetvrtiVyPos);
          cetvrtiV->whiteColor();
          scene->addItem(cetvrtiV);

          Button* petiV = new Button(QString(valueListCopy[i]));
          int petiVxPos = this->width()/2;
          int petiVyPos = mv+i*mv;
          i++;
          petiV->setPos(petiVxPos,petiVyPos);
          petiV->whiteColor();
          scene->addItem(petiV);


          Button* sestiV = new Button(QString(valueListCopy[i]));
          int sestiVxPos = this->width()/2;
          int sestiVyPos = mv+i*mv;
          i++;
          sestiV->setPos(sestiVxPos,sestiVyPos);
          sestiV->whiteColor();
          scene->addItem(sestiV);


          Button* sedmiV = new Button(QString(valueListCopy[i]));
          int sedmiVxPos = this->width()/2;
          int sedmiVyPos = mv+i*mv;
          i++;
          sedmiV->setPos(sedmiVxPos,sedmiVyPos);
          sedmiV->whiteColor();
          scene->addItem(sedmiV);


          Button* osmiV = new Button(QString(valueListCopy[i]));
          int osmiVxPos = this->width()/2;
          int osmiVyPos = mv+i*mv;
          i++;
          osmiV->setPos(osmiVxPos,osmiVyPos);
          osmiV->whiteColor();
          scene->addItem(osmiV);


          Button* devetiV = new Button(QString(valueListCopy[i]));
          int devetiVxPos = this->width()/2;
          int devetiVyPos = mv+i*mv;
          i++;
          devetiV->setPos(devetiVxPos,devetiVyPos);
          devetiV->whiteColor();
          scene->addItem(devetiV);


          Button* desetiV = new Button(QString(valueListCopy[i]));
          int desetiVxPos = this->width()/2;
          int desetiVyPos = mv+i*mv;
          i++;
          desetiV->setPos(desetiVxPos,desetiVyPos);
          desetiV->whiteColor();
          scene->addItem(desetiV);
          /*SCORES END*/
            /*LIST OF HIGHSCORES END*/

          Button* backButton = new Button(QString("Back"));
          backButton->redColor();
          int bxPos = this->width()/2 - 95;
          int byPos = 600;
          backButton->setPos(bxPos,byPos);

          //connect(backButton,SIGNAL(clicked()),this,SLOT(gameOver()));

         // connect(backButton,SIGNAL(clicked()),this,SLOT(insertScore()));
          connect(backButton,SIGNAL(clicked()),this,SLOT(gameOver()));
          //connect(backButton,SIGNAL(clicked()),this,SLOT(back()));

          scene->addItem(backButton);

    
    }
    void Game::insertHighscore(QString name,QString score){
        QString val;
        QFile file("../../../rezultati.json");
    //  file.setFileName("/home/milija/Documents/RS/Project/RS16-legit-digit/proba.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
       //qWarning() << val;
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();

        sett2.keys().push_back(name);
        sett2[name] = score;

        QJsonDocument doc(sett2);
        QString strJson(doc.toJson(QJsonDocument::Compact));

     //   qWarning() << strJson;

//        for(kljuc:sett2.keys()){
//          QJsonValue vrednost = sett2.value(QString(kljuc));
//          qWarning() << kljuc << ":" << sett2[kljuc].toString();
//        }

        file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
        QTextStream stream(&file);
        stream << strJson;
        file.close();
    }

    void Game::getValueOfArea(QString string){
        qWarning() << "VREDNOST POLJA: " << string;
    }

    void Game::gameOver()
    {
        scene->clear();
        QLayout * vbox = new QVBoxLayout();
        QGraphicsView * view = new QGraphicsView();
        QLineEdit *line = new QLineEdit();

        line->setPlaceholderText("ENTER NICKNAME");
        QPushButton *butt = new QPushButton();
        butt->setFixedSize(190, 25);
        butt->setText("OK");
        vbox->addWidget(line);
        vbox->addWidget(butt);

        QWidget * w = new QWidget();
        //QString str = line->text();
        connect(butt, &QPushButton::clicked,
                this, [=](){getValueOfArea(line->text());});
        w->setLayout(vbox);
        w->show();

        //QLineEdit *edit = new QLineEdit("");
        //QPushButton *button = new QPushButton("&Download", this);
        //scene->addWidget(w);


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
        connect(highscoreButton,SIGNAL(clicked()),this,SLOT(displayHighscores()));
        scene->addItem(highscoreButton);

        // create the quit button
        Button* quitButton = new Button(QString("Quit"));
        int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos = 425;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);
    }


