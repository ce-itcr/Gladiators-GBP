#include "gameover.h"
#include "ui_gameover.h"
#include "mainwindow.h"

GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    close();
    MainWindow *w = new MainWindow();
    w->show();
}
