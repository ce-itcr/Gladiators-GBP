/**
 * @file pregame.h
 * @version 1.0
 * @date 19/04/19 -
 * @authors angelortizv
 * @title
 * @brief
 */

#ifndef PREGAME_H
#define PREGAME_H

#include <QDialog>
#include <QDir>
#include <iostream>

#include "game/grid.h"

using namespace std;

namespace Ui {
class PreGame;
}

class PreGame : public QDialog
{
    Q_OBJECT

public:
    explicit PreGame(QWidget *parent = 0);
    ~PreGame();

private slots:
    void on_playGame_clicked();

    void on_backButton_clicked();

    void on_circle_clicked();

    void on_donut_clicked();

    void on_open_clicked();

    void on_snake_clicked();

    void on_race_clicked();

private:
    Ui::PreGame *ui;
    Grid *grid;

    void loadGrid(QString map);
};

#endif // PREGAME_H
