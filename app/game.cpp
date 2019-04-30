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

void Game::on_pushButton_clicked()
{
    Entity *player = new Player(this);
    gameController->addEntity(player);

    Enemy *enemy = new Enemy(this);
    enemy->setX(100);
    enemy->setY(100);
    gameController->addEntity(enemy);
}
