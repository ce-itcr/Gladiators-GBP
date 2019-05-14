#include "pregame.h"
#include "ui_pregame.h"
#include "game.h"
#include "mainwindow.h"

PreGame::PreGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreGame)
{
    ui->setupUi(this);
    progressBar();

}

PreGame::~PreGame()
{
    delete ui;
}

void PreGame::on_playGame_clicked(){
    close();
    Game *game = new Game();
    game->show();
}

void PreGame::on_backButton_clicked()
{
    close();
    MainWindow *w = new MainWindow();
    w->show();
}

void PreGame::progressBar(){

    for (int i=0;i<5;i++){
        int xi=60*i+450;

            QLabel *w = new QLabel(this);
            QMovie *movie = new QMovie(":/img/gladiatorRun.gif");
            w->setMovie (movie);
            w->setGeometry(xi,510,99,79);
            movie->start ();
    }
}
