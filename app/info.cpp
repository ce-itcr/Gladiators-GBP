#include "info.h"
#include "ui_info.h"
#include "mainwindow.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
}

Info::~Info()
{
    delete ui;
}

void Info::on_pushButton_clicked()
{
    close();
    MainWindow *w = new MainWindow();
    w->show();
}
