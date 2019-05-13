#include "pregame.h"
#include "ui_pregame.h"
#include "game.h"

PreGame::PreGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreGame)
{
    ui->setupUi(this);
    runProgressBar();
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

void PreGame::runProgressBar(){
//    ui->progressBar->setValue(10);
//    usleep(50*1000);
//    ui->progressBar->setValue(30);
//    usleep(50*1000);
//    ui->progressBar->setValue(60);
//    usleep(50*1000);
//    ui->progressBar->setValue(80);
//    usleep(50*1000);
//    ui->progressBar->setValue(100);
}
