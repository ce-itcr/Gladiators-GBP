#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include "client/client.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}


void Settings::on_toMainWindow_clicked(){
    close();
    MainWindow *w = new MainWindow();
    w->show();
}

void Settings::on_pushButton_clicked()
{
    QString ip = ui->ipEdit->toPlainText();
    QString port = ui->portEdit->toPlainText();
    Client::getInstance()->loadHost(ip, port);

    close();
    PreGame pregame;
    pregame.setModal(true);
    pregame.exec();
}
