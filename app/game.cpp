#include "game.h"
#include "ui_game.h"
#include <QLabel>

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    speed = 2;

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

    int xOffset = 16, yOffset = 82;
    int x = xOffset, y = yOffset;
    int width, height;
    width = height = this->height() - yOffset;

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
    int cycles = gameController->getCycleTime();
    speed = speed % 3 + 1;

    QIcon icon;
    if (speed == 1) { cycles = 50; icon.addFile(":img/slow.png"); }
    if (speed == 2) { cycles = 25; icon.addFile(":img/normal.png"); }
    if (speed == 3) { cycles = 10; icon.addFile(":img/fast.png"); }
    ui->fastButton->setIcon(icon);

    gameController->setCycleTime(cycles);
}

void Game::on_pauseButton_clicked()
{
    bool pause = gameController->isPause();
    gameController->setPause(!pause);

    QIcon icon;
    if (pause) icon.addFile(":img/pauseIcon.png");
    else icon.addFile(":img/playIcon.png");
    ui->pauseButton->setIcon(icon);
}
