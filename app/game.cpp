#include "game.h"
#include "ui_game.h"
#include <QLabel>

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    loadGrid();
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

void Game::resizeEvent(QResizeEvent *event)
{
    int width, height;
    width = height = this->height() - 10 * 2;
    grid->resize(width, height);
}
