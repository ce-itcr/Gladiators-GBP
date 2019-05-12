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
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "game/grid.h"
#include "game/gamecontroller.h"
#include "game/populations.h"
#include "game/spawner.h"
#include "graph/PathFinding/findpath.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    FindPath *Path = new FindPath();
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    void enableWaveButton();

    QMediaPlayer *music;

public slots:
    void populationReady();

    void updatePopulations();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::Game *ui;
    Grid *grid;
    GameController *gameController;
    Populations *populations;
    Spawner *spawner;
    int gameSpeed;

    void loadGrid();

    void loadButtons();

private slots:
    void on_waveButton_clicked();
    void on_fastButton_clicked();
    void on_pauseButton_clicked();
};

#endif // GAME_H
