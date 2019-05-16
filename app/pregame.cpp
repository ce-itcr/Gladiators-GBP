#include "pregame.h"
#include "ui_pregame.h"
#include "game.h"
#include "mainwindow.h"

PreGame::PreGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreGame)
{
    ui->setupUi(this);

    QString map = GameController::getInstance()->getMap();
    loadGrid(map);
    loadMaps();
}

PreGame::~PreGame()
{
    delete ui;
}

void PreGame::on_playGame_clicked(){
    QMediaPlayer* playGAME = new QMediaPlayer;
    playGAME->setMedia(QUrl("qrc:/audio/PowerUp03.wav"));
    playGAME->setVolume(50);
    playGAME->play();
    close();
    Game *game = new Game();
    game->show();
}

void PreGame::loadGrid(QString map)
{
    grid = new Grid(this, map);

    int xOffset = 100, yOffset = 82;
    int x = xOffset, y = yOffset;
    int width, height;
    width = height = this->height() * 0.6;

    grid->setGeometry(x, y, width, height);
    grid->setFocusable(false);
    grid->load();
    grid->show();
}

void PreGame::loadMaps()
{
    QDir directory("://maps");
    QStringList maps = directory.entryList(QStringList(), QDir::Files);
    QLayout *layout = ui->mapsLayout;
    foreach(QString filename, maps) {
        QPushButton *button = new QPushButton(filename);
        layout->addWidget(button);
        button->show();
        QObject::connect(button, &QPushButton::clicked, this, &PreGame::mapButtonClicked);
    }
}

void PreGame::mapButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString path = "://maps/" + button->text();
    loadGrid(path);
    GameController::getInstance()->setMap(path);

}

void PreGame::on_backButton_clicked()
{
    close();
    MainWindow *w = new MainWindow();
    w->show();
}
