#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_Button_clicked(){
    close();
    PreGame pregame;
    pregame.setModal(true);
    pregame.exec();
}

void MainWindow::on_settings_Button_clicked(){
    close();
    Settings settings;
    settings.setModal(true);
    settings.exec();
}

void MainWindow::on_achievements_Button_clicked(){
    close();
    Achievements achievements;
    achievements.setModal(true);
    achievements.exec();
}

void MainWindow::on_exit_Button_clicked()
{
    close();
}

