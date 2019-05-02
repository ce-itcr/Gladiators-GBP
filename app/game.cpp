#include "game.h"
#include "ui_game.h"
#include <QLabel>

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    gameController = GameController::getInstance();
    gameController->run();

    loadGrid();
    loadButtons();
}

Game::~Game()
{
    delete ui;
}

void Game::loadGrid()
{
    grid = new Grid(this);

    int offset = 10;
    int x = offset, y = offset;
    int width, height;
    width = height = this->height() - offset * 2;

    grid->setGeometry(x, y, width, height);
    grid->load();
    grid->show();
}

void Game::loadButtons()
{
    ui->waveButton->raise();
    ui->fastButton->raise();
    ui->pauseButton->raise();
}

void Game::resizeEvent(QResizeEvent *)
{
    int width, height;
    width = height = this->height() - 10 * 2;
    grid->resize(width, height);
}

void Game::on_waveButton_clicked()
{
    grid->on_waveButton_clicked();
}

void Game::on_fastButton_clicked()
{

}

void Game::on_pauseButton_clicked()
{
    bool pause = gameController->isPause();
    gameController->setPause(!pause);
}
