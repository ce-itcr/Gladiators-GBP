#include "player.h"
#include <QMovie>
#include <QLabel>
#include "game.h"

Player::Player(QWidget *parent) : QLabel (parent), grid(static_cast<Grid *>(parent))
{
    gladiator = nullptr;
    tag = "player";
    x = 0;
    y = 0;
    width = 80;
    height = 80;
    xAcc = 1;
    yAcc = 1;
    maxAcc = 2;
    timeAlive.start();
    canMove = true;
    target = nullptr;
    freezed = false;
    confused = false;
    setStyleSheet("background-color: rgba(255,255,255,0);");

    QMovie *movie = new QMovie(this);
    movie->setFileName(":/img/gladiatorRun.gif");
    //movie->setScaledSize(this->size());
    this->setMovie(movie);
    movie->start();

//    this->setStyleSheet("background-color:green;");
    this->setGeometry(x, y, width, height);
    this->show();
}

Player::~Player()
{

}

void Player::update()
{
    if (gladiator->getHealth() <= 0) kill();
    if (target == nullptr)
    {
        if (!confused) nextTarget();
        else nextVisitedTarget();
    }
    if (canMove && target != nullptr && !freezed) {
        gladiator->setI(target->getI());
        gladiator->setJ(target->getJ());
        move();
    }
}

int Player::getMaxSpeed(){
    int gladiatorSpeed = this->gladiator->getSpeed();
    return gladiatorSpeed;
}

void Player::draw()
{
}

void Player::collide()
{
    //canMove = false;
}

void Player::uncollide()
{
    canMove = true;
}

void killBoss(Gladiator *gladiator){
    gladiator->setHealth(0);
    gladiator->setResistanceUpperBody(Spawner::getInstance()->getTempGladiator()->getResistanceUpperBody());
    gladiator->setResistanceLowerBody(Spawner::getInstance()->getTempGladiator()->getResistanceLowerBody());
    gladiator->setDodgeChance(Spawner::getInstance()->getTempGladiator()->getDodgeChance());
    gladiator->setBoss(false);
}

void Player::kill()
{
    if(gladiator->getBoss()){
        killBoss(gladiator);
    }
    gladiator->setAlive(false);
    GameController::getInstance()->removeEntity(this);

    int elapsedSec = timeAlive.elapsed() / 1000;
    int distance = maxSpeed * elapsedSec;
    Game * game = dynamic_cast<Game *>(parent()->parent());
    game->addPlayerToTable(gladiator->getId(), distance);
}

void Player::hit(int damage)
{
    if (gladiator->getDodgeChance() > Math::random(1, 100))
    {
        miss();
        return;
    }

    int damageDone = damage - gladiator->getThoughness();
    if (damageDone < 0) damageDone = 1;
    int health = gladiator->getHealth() - damageDone;
    gladiator->setHealth(health);
}

void Player::freeze(int time)
{
    freezed = true;
    QTimer::singleShot(time, this, &Player::unFreeze);
}

void Player::unFreeze()
{
    freezed = false;
}

void Player::confuse(int time)
{
    confused = true;
    QTimer::singleShot(time, this, &Player::unConfuse);
}

void Player::unConfuse()
{
    confused = false;
}

QRect Player::getRect()
{
    int offset = 10;
    QRect rect(x, y, width - offset, height- offset);
    return rect;
}

void Player::updatePath()
{
    nodePath = gladiator->getNodePath();
}

int Player::getX() const
{
    return x;
}

void Player::setX(int value)
{
    x = value;
}

int Player::getY() const
{
    return y;
}

void Player::setY(int value)
{
    y = value;
}

QList<Node *> Player::getNodePath() const
{
    return nodePath;
}

void Player::setNodePath(const QList<Node *> &value)
{
    nodePath = value;
}

Gladiator *Player::getGladiator() const
{
    return gladiator;
}

void Player::setGladiator(Gladiator *value)
{
    gladiator = value;
    maxSpeed = this->getMaxSpeed();
    if(maxSpeed<=0){
        maxSpeed=1;
    }
}

void Player::mousePressEvent(QMouseEvent *)
{
    gladiatorPressed(gladiator);
}

void Player::move()
{
    //setNodePath(gladiator->getNodePath());
    xSpeed = Math::clamp(0, maxSpeed, xSpeed + xAcc);
    ySpeed = Math::clamp(0, maxSpeed, ySpeed + yAcc);
    x = Math::approach(x, target->x(), xSpeed);
    y = Math::approach(y, target->y(), ySpeed);;
    
    QFrame::move(x, y);
    if (x == target->x() && y == target->y())
    {
        target = nullptr;
        if (nodePath.isEmpty()){
            Spawner::getInstance()->setEnemiesOver(Spawner::getInstance()->getEnemiesOver() + 1);
            kill();  // Reaches final Node
        }
    }
}

void Player::nextTarget()
{
    Node *node = nodePath.takeFirst();
    QList<Tile *> tiles = grid->getTiles();
    for (Tile *tile : tiles)
    {
        if (tile->getNode() == node)
        {
            target = tile;
            visitedPath.push_front(tile);
            break;
        }
    }
}

void Player::nextVisitedTarget()
{
    if (visitedPath.isEmpty()) return;
    target = visitedPath.takeFirst();
    nodePath.push_front(target->getNode());
}

void Player::miss()
{
    QLabel *miss = new QLabel("Misss", parentWidget());
    miss->move(x, y);
    miss->show();

    miss->setStyleSheet("font-size: 16px; "
                       "color: #FFC300;"
                       "background-color: rgba(255, 255, 255, 0);");

    QTimer::singleShot(500, miss, &QLabel::close);
}

void Player::resizeEvent(QResizeEvent *event)
{
    width = event->size().width();
    height = event->size().height();
}
