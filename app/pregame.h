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
#include <QMediaPlayer>
#include "mainwindow.h"
#include <unistd.h>

namespace Ui {
class PreGame;
}

class PreGame : public QDialog
{
    Q_OBJECT

public:
    explicit PreGame(QWidget *parent = 0);
    ~PreGame();
    void runProgressBar();

private slots:
    void on_playGame_clicked();

    void on_backButton_clicked();

private:
    Ui::PreGame *ui;
};

#endif // PREGAME_H
