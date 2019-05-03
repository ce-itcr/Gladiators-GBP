/**
 * @file game.h
 * @version 1.0
 * @date 19/04/19 -
 * @authors angelortizv
 * @title
 * @brief
 */

#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QPushButton>

#include "game/grid.h"
#include "game/gamecontroller.h"
#include "game/populations.h"
#include "game/spawner.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    void enableWaveButton();

public slots:
    void populationReady();

private:
    Ui::Game *ui;
    Grid *grid;
    GameController *gameController;
    Populations *populations;
    Spawner *spawner;
    int speed;

    void loadGrid();

    void loadButtons();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_waveButton_clicked();
    void on_fastButton_clicked();
    void on_pauseButton_clicked();
};

#endif // GAME_H
