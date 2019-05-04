#include "game.h"
#include "ui_game.h"
#include <QLabel>
#include "game/populationsmock.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    gameSpeed = 2;

    spawner = Spawner::getInstance();
    gameController = GameController::getInstance();
    gameController->run();
    populations = Populations::getInstance();
    QObject::connect(populations, &Populations::readyPopulation,
                     this, &Game::populationReady);
    loadGrid();
    loadButtons();

    // Fake population
    PopulationsMock::run();
    PopulationsMock::loadNoadesPath(Map::getInstance()->getNodes());
}

Game::~Game()
{
    delete ui;
}

void Game::enableWaveButton()
{
    ui->waveButton->setEnabled(true);
}

void Game::populationReady()
{
    ui->waveButton->setEnabled(true);
}

void Game::loadGrid()
{
    grid = new Grid(this);

    int xOffset = 16, yOffset = 82;
    int x = xOffset, y = yOffset;
    int width, height;
    width = height = this->height() - yOffset * 2;

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
    width = height = this->height() - 94;
    grid->resize(width, height);
}

void Game::on_waveButton_clicked()
{
    if (gameController->isWaveActive()) return;

    ui->waveButton->setEnabled(false);
    spawner->spawnGladiators(populations->getGladiators());
}

void Game::on_fastButton_clicked()
{
    int cycles = gameController->getCycleTime();
    gameSpeed = gameSpeed % 3 + 1;

    QIcon icon;
    if (gameSpeed == 1) { cycles = 50; icon.addFile(":img/slow.png"); }
    if (gameSpeed == 2) { cycles = 25; icon.addFile(":img/normal.png"); }
    if (gameSpeed == 3) { cycles = 10; icon.addFile(":img/fast.png"); }
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
