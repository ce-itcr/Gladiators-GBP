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

void Game::resizeEvent(QResizeEvent *)
{
    int width, height;
    width = height = this->height() - 10 * 2;
    grid->resize(width, height);
}

void Game::on_pushButton_clicked()
{
    Entity *player = new Player(grid);
    QList<Node *> nodes;
    for (Tile *tile : grid->getTiles())
    {
        nodes.push_back(tile->getNode());
    }
    static_cast<Player *>(player)->setNodePath(nodes);
    gameController->addEntity(player);

    Enemy *enemy = new Enemy(grid);
    enemy->setX(600);
    enemy->setY(600);
    gameController->addEntity(enemy);
}

