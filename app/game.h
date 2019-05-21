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
#include "game/entities/spell.h"
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

    void addSpell(Spell *spell);

    void removeSpell(Spell *spell);

    void addPlayerToTable(QString id, int distance);

    void cleanTable();

    QMediaPlayer *music;

    Grid *getGrid() const;

public slots:
    void populationReady();

    void updatePopulations();

    void addedEntity(Entity *entity);

    void loadGladiatorLabel(Gladiator *gladiator);

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);

    void paintEvent(QPaintEvent *);

private:
    Ui::Game *ui;
    Grid *grid;
    GameController *gameController;
    Populations *populations;
    Spawner *spawner;
    int gameSpeed;
    Gladiator *gladiatorLabel;
    QList<Spell *> spells;

    void loadGrid();

    void loadButtons();

    void loadSpells();

private slots:
    void on_waveButton_clicked();
    void on_fastButton_clicked();
    void on_pauseButton_clicked();
    void on_exitButton_clicked();
    void on_spawnBoss_clicked();
};

#endif // GAME_H
