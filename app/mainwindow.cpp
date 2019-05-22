#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Util* util = new Util();
    util->playMusic();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_Button_clicked(){

    QMediaPlayer* continueB = new QMediaPlayer;
    continueB->setMedia(QUrl("qrc:/audio/click.mp3"));
    continueB->setVolume(50);
    continueB->play();
    close();
    PreGame pregame;
    pregame.setModal(true);
    pregame.exec();
}

void MainWindow::on_settings_Button_clicked(){
    QMediaPlayer* continueB = new QMediaPlayer;
    continueB->setMedia(QUrl("qrc:/audio/click.mp3"));
    continueB->setVolume(50);
    continueB->play();
    close();
    Settings settings;
    settings.setModal(true);
    settings.exec();
}

void MainWindow::on_exit_Button_clicked()
{
    this->close();
}

