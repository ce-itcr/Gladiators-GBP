#include "achievements.h"
#include "ui_achievements.h"
#include "mainwindow.h"

Achievements::Achievements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Achievements)
{
    ui->setupUi(this);
    tableMethod();
    celebrateGif();


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

void Achievements::tableMethod(){
    QStringList titles;
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setShowGrid(false);
    titles << "Achievement" << "Description";
    ui->tableWidget->horizontalHeader()->adjustSize();
    ui->tableWidget->setHorizontalHeaderLabels(titles);

    ui->tableWidget->setItem(0,0, new QTableWidgetItem("Achievement 1"));
    ui->tableWidget->setItem(1,0, new QTableWidgetItem("Achievement 2"));
    ui->tableWidget->setItem(2,0, new QTableWidgetItem("Achievement 3"));
    ui->tableWidget->setItem(3,0, new QTableWidgetItem("Achievement 4"));
    ui->tableWidget->setItem(4,0, new QTableWidgetItem("Achievement 5"));
    ui->tableWidget->setItem(5,0, new QTableWidgetItem("Achievement 6"));

    ui->tableWidget->setItem(0,1, new QTableWidgetItem("Description 1"));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem("Description 2"));
    ui->tableWidget->setItem(2,1, new QTableWidgetItem("Description 3"));
    ui->tableWidget->setItem(3,1, new QTableWidgetItem("Description 4"));
    ui->tableWidget->setItem(4,1, new QTableWidgetItem("Description 5"));
    ui->tableWidget->setItem(5,1, new QTableWidgetItem("Description 6"));
}

void Achievements::celebrateGif(){


}
