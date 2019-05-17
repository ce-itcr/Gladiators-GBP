#include "arrow.h"
#include "game/entities/player.h"
#include "game/entities/gladiator.h"
#include "game/grid.h"

Arrow::Arrow(QWidget *parent, int x, int y) : QFrame(parent)
{
    tag = "arrow";
    this->x = x;
    this->y = y;
    width = 10;
    height = 10;
    damage = 10;
    xSpeed = 0;
    ySpeed = 0;
    xAcc = 1;
    yAcc = 1;
    maxSpeed = 60;
    maxAcc = 10;
    target = nullptr;

    setStyleSheet("background-color:#635255;"
                  "image: url(:/img/fire/00fire.png)");

    //    this->setStyleSheet("background-color:#EBF5EE;");
    this->setGeometry(x, y, width, height);
    this->show();
}

void Arrow::setDamage(int Damage){
    this->damage = Damage;
}

int Arrow::getDamage(){
    return this->damage;
}

Arrow::~Arrow()
{

}

void Arrow::update()
{
    if (target != nullptr) move();
    else GameController::getInstance()->removeEntity(this);
}

void Arrow::draw()
{

}

void Arrow::collide()
{
    for (Entity *entity : GameController::getInstance()->getEntities())
    {
        if (entity->tag == "player" &&
                Collision::collide(getRect(), entity->getRect()))
        {
            Player *player = dynamic_cast<Player *>(entity);
            int damageDone = tower->getDamagePerShoot() - player->getGladiator()->getThoughness();
            if(damageDone < 1){
                damageDone = 1;
            }
            if(tower->getType() != 3){
                player->getGladiator()->setHealth(player->getGladiator()->getHealth() - damageDone);
                if(player->getGladiator()->getHealth() <= 0){
                    tower->setXp(tower->getXp() + 1);
                    player->kill();
                    kill();
                }
            }
            else{
                QList<Entity *> playersHit = AOECollide();
                QList<Entity *>::iterator i;
                for(i = playersHit.begin(); i != playersHit.end(); i++){
                    Player *tempPlayer = dynamic_cast<Player *>(*i);
                    tempPlayer->getGladiator()->setHealth(player->getGladiator()->getHealth() - damageDone);
                    if(tempPlayer->getGladiator()->getHealth() <= 0){
                        tower->setXp(tower->getXp() + 1);
                        tempPlayer->kill();
                    }
                }
                playersHit.clear();
                kill();

                Grid *grid = dynamic_cast<Grid *>(parent());
                QFrame *qFrame = new QFrame(grid);
                qFrame->setStyleSheet("background-color:#635255;");
                int xPoss = x - grid->getTileSize();
                int yPoss = y - grid->getTileSize();
                int diameter = grid->getTileSize() * 3;
                qFrame->setGeometry(xPoss,yPoss,diameter,diameter);
                qFrame->show();

                QTimer::singleShot(200, qFrame, &QFrame::close);
            }
            break;
        }
    }
}

void Arrow::uncollide()
{

}

QRect Arrow::getRect()
{
    QRect rect(x, y, width, height);
    return rect;
}

void Arrow::kill()
{
    GameController::getInstance()->removeEntity(this);
}

int Arrow::getX() const
{
    return x;
}

void Arrow::setX(int value)
{
    x = value;
}

int Arrow::getY() const
{
    return y;
}

void Arrow::setY(int value)
{
    y = value;
}

Entity *Arrow::getTarget() const
{
    return target;
}

void Arrow::setTarget(Entity *value)
{
    target = value;
}

void Arrow::setTower(Tower *value)
{
    tower = value;
}

void Arrow::move()
{
    if (target == nullptr || target->tag != "player") return;

    int offset = 10;
    Player *targetPlayer = static_cast<Player *>(target);
    xSpeed = Math::clamp(0, maxSpeed, xSpeed + xAcc);
    ySpeed = Math::clamp(0, maxSpeed, ySpeed + yAcc);
    x = Math::approach(x, targetPlayer->getX() + offset, xSpeed);
    y = Math::approach(y, targetPlayer->getY() + offset, ySpeed);;

    QFrame::move(x, y);
}

QRegion Arrow::getCircle()
{
    Grid *grid = dynamic_cast<Grid *>(parent());
    int xPoss = x - grid->getTileSize();
    int yPoss = y - grid->getTileSize();
    int diameter = grid->getTileSize() * 3;
    QRegion circle(xPoss, yPoss, diameter, diameter, QRegion::Ellipse);
    return circle;
}

QList<Entity *> Arrow::AOECollide(){
    QList<Entity *> players;
    for (Entity *entity : GameController::getInstance()->getEntities())
    {
        if (entity->tag == "player" &&
                Collision::collide(getCircle(), entity->getRect()))
        {
            players.push_back(entity);
        }
    }
    return players;
}
