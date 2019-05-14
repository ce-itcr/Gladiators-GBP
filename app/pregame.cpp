#include "pregame.h"
#include "ui_pregame.h"
#include "game.h"
#include "mainwindow.h"

PreGame::PreGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreGame)
{
    ui->setupUi(this);
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
