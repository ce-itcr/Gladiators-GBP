#include "achievements.h"
#include "ui_achievements.h"
#include "mainwindow.h"

Achievements::Achievements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Achievements)
{
    ui->setupUi(this);
}

Achievements::~Achievements()
{
    delete ui;
}

void Achievements::on_toMainWIndow_clicked(){
    close();
    MainWindow *w = new MainWindow();
    w->show();
}
