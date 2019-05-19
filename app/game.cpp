#include "game.h"
#include "mainwindow.h"
#include "ui_game.h"
#include <QLabel>
#include <QMovie>
#include "game/populationsmock.h"
#include "game/entities/player.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    gameSpeed = 2;

    spawner = Spawner::getInstance();
    gameController = GameController::getInstance();    
    gameController->setWaveWaiting(true);
    gameController->run();
    populations = Populations::getInstance();
    QObject::connect(populations, &Populations::readyPopulation,
                     this, &Game::populationReady);
    QObject::connect(gameController, &GameController::addedEntity,
                     this, &Game::addedEntity);
    loadGrid();
    loadButtons();

    // Creates Population
    //PopulationsMock::run();
    populations->startNewPopulation();
    QTimer::singleShot(2000, this, &Game::updatePopulations);


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
    for (Tower *tower : *populations->getTowers())
    {
        Tile *tile = grid->tileAt(tower->getI(), tower->getJ());
        spawner->spawnTower(tile, tower);
    }
}

void Game::updatePopulations()
{
    populations->updatePopulation();
}

void Game::addedEntity(Entity *entity)
{
    if (entity->tag == "player")
    {
        Player *player = dynamic_cast<Player *>(entity);
        QObject::connect(player, &Player::gladiatorPressed, this, &Game::loadGladiatorLabel);
    }
}

void Game::loadGladiatorLabel(Gladiator *gladiator)
{
    ui->ageIN->setNum(gladiator->getAge());
    ui->healthIN->setNum(gladiator->getHealth());
    ui->resUPIN->setNum(gladiator->getResistanceUpperBody());
    ui->resLBIN->setNum(gladiator->getResistanceLowerBody());
    ui->dodgeIN->setNum(gladiator->getDodgeChance());
}

void Game::loadGrid()
{
    grid = new Grid(this, gameController->getMap());

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

void Game::paintEvent(QPaintEvent *)
{
    int waveCount = spawner->waveSize();
    ui->waveCount->setNum(waveCount);

    int money = gameController->getMoney();
    ui->moneyCount->setNum(money);
}

void Game::on_waveButton_clicked()
{
    if (gameController->isWaveActive()) return;
    gameController->setWaveActive(true);
    FindPath::instance->shortestPath();
    ui->waveButton->setEnabled(false);
    spawner->spawnGladiators(populations->getGladiators());

    QMediaPlayer* genWave = new QMediaPlayer;
    genWave->setMedia(QUrl("qrc:/audio/PowerUp01.mp3"));
    genWave->setVolume(50);
    genWave->play();
}

void Game::on_fastButton_clicked()
{
    int cycles = gameController->getCycleTime();
    gameSpeed = gameSpeed % 3 + 1;

    QIcon icon;
    if (gameSpeed == 1) { cycles = 50; icon.addFile(":img/slow.png"); spawner->setSpawnDelay(1000); }
    if (gameSpeed == 2) { cycles = 25; icon.addFile(":img/normal.png"); spawner->setSpawnDelay(500); }
    if (gameSpeed == 3) { cycles = 10; icon.addFile(":img/fast.png"); spawner->setSpawnDelay(250); }
    ui->fastButton->setIcon(icon);

    gameController->setCycleTime(cycles);

    QMediaPlayer* fastPowerUp = new QMediaPlayer;
    fastPowerUp->setMedia(QUrl("qrc:/audio/PowerUp02.mp3"));
    fastPowerUp->setVolume(50);
    fastPowerUp->play();
}

void Game::on_pauseButton_clicked()
{
    bool pause = gameController->isPause();
    gameController->setPause(!pause);

//    if(!pause) music->pause();
//    else music->play();

    QIcon icon;
    if (pause) icon.addFile(":img/pauseIcon.png");
    else icon.addFile(":img/playIcon.png");
    ui->pauseButton->setIcon(icon);

    QMediaPlayer* pausesrc = new QMediaPlayer;
    pausesrc->setMedia(QUrl("qrc:/audio/Fire01.wav"));
    pausesrc->setVolume(50);
    pausesrc->play();
}

void Game::on_exitButton_clicked()
{
    gameController->stop();
    spawner->stop();

    QMediaPlayer* exit = new QMediaPlayer;
    exit->setMedia(QUrl("qrc:/audio/Death02.wav"));
    exit->setVolume(100);
    exit->play();

    close();
    MainWindow *w = new MainWindow();
    w->show();


}
