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
    loadWaveButton();
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

void Game::loadWaveButton()
{
    int offset = 10;
    int x = grid->x() + offset;
    int y = grid->y() + offset;

    QPushButton *waveButton = new QPushButton(grid);
    waveButton->setGeometry(x, y, 16, 16);
    QObject::connect(waveButton, &QPushButton::clicked, grid, &Grid::on_waveButton_clicked);
    waveButton->setStyleSheet("border-radius: 16px;");

    waveButton->show();
}

void Game::resizeEvent(QResizeEvent *)
{
    int width, height;
    width = height = this->height() - 10 * 2;
    grid->resize(width, height);
}
