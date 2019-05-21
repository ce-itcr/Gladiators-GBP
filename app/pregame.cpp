#include "pregame.h"
#include "ui_pregame.h"
#include "game.h"
#include "mainwindow.h"

PreGame::PreGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreGame)
{
    ui->setupUi(this);

    QString map = GameController::getInstance()->getMap();
    loadGrid(map);
}

PreGame::~PreGame()
{
    delete ui;
}

void PreGame::on_playGame_clicked(){
    QMediaPlayer* continueB = new QMediaPlayer;
    continueB->setMedia(QUrl("qrc:/audio/click.mp3"));
    continueB->setVolume(50);
    continueB->play();

    close();
    Game *game = new Game();
    game->show();
}

void PreGame::loadGrid(QString map)
{
    grid = new Grid(this, map);

    int xOffset = 150, yOffset = 125;
    int x = xOffset, y = yOffset;
    int width, height;
    width = height = this->height() * 0.6;

    grid->setGeometry(x, y, width, height);
    grid->setFocusable(false);
    grid->load();
    grid->show();
}

void PreGame::on_backButton_clicked()
{
    QMediaPlayer* back = new QMediaPlayer;
    back->setMedia(QUrl("qrc:/audio/click.mp3"));
    back->setVolume(50);
    back->play();
    close();
    MainWindow *w = new MainWindow();
    w->show();
}


void PreGame::on_circle_clicked()
{
    Util* util = new Util();
    util->playClick();
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString path = "://maps/" + button->objectName();
    loadGrid(path);

    GameController::getInstance()->setMap(path);
}

void PreGame::on_donut_clicked()
{
    Util* util = new Util();
    util->playClick();
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString path = "://maps/" + button->objectName();
    loadGrid(path);

    GameController::getInstance()->setMap(path);
}

void PreGame::on_open_clicked()
{
    Util* util = new Util();
    util->playClick();
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString path = "://maps/" + button->objectName();
    loadGrid(path);

    GameController::getInstance()->setMap(path);
}

void PreGame::on_snake_clicked()
{
    Util* util = new Util();
    util->playClick();
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString path = "://maps/" + button->objectName();
    loadGrid(path);

    GameController::getInstance()->setMap(path);
}

void PreGame::on_race_clicked()
{
    Util* util = new Util();
    util->playClick();
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString path = "://maps/" + button->objectName();
    loadGrid(path);

    GameController::getInstance()->setMap(path);
}
