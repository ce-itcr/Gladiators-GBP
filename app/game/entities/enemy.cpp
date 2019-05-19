#include "enemy.h"

#include "game/spawner.h"

int Enemy::buildCost = 200;
int Enemy::onKillMoney = 5;
int Enemy::boostCost = 100;
int Enemy::boostTime = 4000;
int Enemy::boostRate = 3;

Enemy::Enemy(QWidget *parent, int x, int y) : QFrame(parent)
{
    tower = nullptr;
    tag = "enemy";
    this->x = x;
    this->y = y;
    width = 50;
    height = 50;
    range = 2;
    target = nullptr;
    shootDelay.start();
    canShoot = false;

    setStyleSheet("background-color:#635255;"
                  "image: url(:img/tower1.png)");
    this->setGeometry(x, y, width, height);
    this->show();
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    this->move(x, y);
    updateShootDelay();
    if (shootDelay.elapsed() >= fireRate) canShoot = true;
}

void Enemy::draw()
{

}

void Enemy::collide()
{
    QList<Entity *> players;
    for (Entity *entity : GameController::getInstance()->getEntities())
    {
        if (entity->tag == "player" &&
                Collision::collide(getCircle(), entity->getRect()))
        {
            players.push_back(entity);
        }
    }
    collide(players);


}

void Enemy::collide(QList<Entity *> players)
{
    if (players.isEmpty()) target = nullptr;
    else
    {
        target = closerPlayer(players);
        if(canShoot) shoot(target);
    }

}

void Enemy::uncollide()
{

}

void Enemy::updateDelta()
{
    int cycleSpeed = GameController::getInstance()->getCycleTime();
    deltaTime = tower->getAttackSpeed() / cycleSpeed;
}

QRect Enemy::getRect()
{
    QRect rect(x, y, width, height);
    return rect;
}

void Enemy::playerKill()
{
    GameController::getInstance()->addMoney(onKillMoney);
}

QRegion Enemy::getCircle()
{
    int xPoss = x - width * range;
    int yPoss = y - height * range;
    int diameter = width * range * 2 + width;
    QRegion circle(xPoss, yPoss, diameter, diameter, QRegion::Ellipse);
    return circle;
}

int Enemy::getX() const
{
    return x;
}

void Enemy::setX(int value)
{
    x = value;
}

int Enemy::getY() const
{
    return y;
}

void Enemy::setY(int value)
{
    y = value;
}

Tower *Enemy::getTower() const
{
    return tower;
}

void Enemy::setTower(Tower *value)
{
    tower = value;
}

int Enemy::getBuildCost()
{
    return buildCost;
}

void Enemy::setBuildCost(int value)
{
    buildCost = value;
}

int Enemy::getOnKillMoney()
{
    return onKillMoney;
}

void Enemy::setOnKillMoney(int value)
{
    onKillMoney = value;
}

void Enemy::mousePressEvent(QMouseEvent *)
{
    int offset = 5;
    int size = width - offset * 2;

    QPushButton *upgrade = new QPushButton(this);
    upgrade->setGeometry(offset, offset, size, size);
    upgrade->setStyleSheet("background-color:rgba(150, 150, 255, 100);");
    upgrade->show();

    QObject::connect(upgrade, &QPushButton::clicked, this, &Enemy::boost);
    QTimer::singleShot(3000, upgrade, &QPushButton::close);
}

void Enemy::resizeEvent(QResizeEvent *)
{
    width = QWidget::width();
    height = QWidget::height();
}

void Enemy::boost()
{
    int money = GameController::getInstance()->getMoney();
    if (money < boostCost) return;

    attackSpeedSaved = tower->getAttackSpeed();
    damageSaved = tower->getDamagePerShoot();
    int attackSpeed = attackSpeedSaved / boostRate;
    int damage = damageSaved * boostRate;
    tower->setAttackSpeed(attackSpeed);
    tower->setDamagePerShoot(damage);

    updateDelta();
    GameController::getInstance()->spendMoney(boostCost);
    QTimer::singleShot(boostTime, this, &Enemy::endBoost);
}

void Enemy::endBoost()
{
    tower->setAttackSpeed(attackSpeedSaved);
    tower->setDamagePerShoot(damageSaved);
    updateDelta();
}

Entity *Enemy::closerPlayer(QList<Entity *> players)
{
    Entity *closer = nullptr;
    float min = INFINITY;
    for (Entity *player : players)
    {
        QRect rect1 = this->getRect();
        QRect rect2 = player->getRect();

        int x1 = rect1.x();
        int y1 = rect1.y();
        int x2 = rect2.x();
        int y2 = rect2.y();

        int distance = Math::distance(x1, y1, x2, y2);
        if (distance < min) {
            closer = player;
            min = distance;
        }
    }
    return closer;
}

void Enemy::shoot(Entity *entity)
{
    if (entity == nullptr &&
            entity->tag != "player") return;
    canShoot = false;
    shootDelay.restart();

    int xPoss = x + width / 4;
    int yPoss = y + width / 4;
    Spawner::getInstance()->spawnArrow(xPoss, yPoss, entity, this->tower->damagePerShoot, this);
}

void Enemy::updateShootDelay()
{
    int cycleSpeed = GameController::getInstance()->getCycleTime();
    fireRate = cycleSpeed * deltaTime;
}
