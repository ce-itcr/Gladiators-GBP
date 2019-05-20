#include "spell.h"

#include "game/grid.h"
#include "game/gamecontroller.h"
#include "game.h"

int Spell::onKillMoney = 15;

Spell::Spell(QWidget *parent, QString _type, QString animation) : QLabel(parent)
{
    x = 0;
    y = 0;
    canMove = true;
    active = false;
    type = _type;
    iconAnimation = animation;
    duration = 5000;
    updateDelay = 900;
    castCost = 200;
    burnDamage = 1;
    confuseTime = 3000;
    freezeTime = 2000;

    int size = 50;
    width = height = size;
    resize(size, size);
    setStyleSheet("background-color:rgba(255, 255, 255, 100);"
                  "border-radius:20px;");
}

Spell::~Spell()
{

}

void Spell::update()
{
    QTimer::singleShot(updateDelay, this, &Spell::update);
    if (!active) return;

    QList<Player *> players = playersIn(GameController::getInstance()->getEntities());
    if (type == "fire") burn(players);
    else if (type == "ice") freeze(players);
    else if (type == "dark") confuse(players);
}

QList<Player *> Spell::playersIn(QList<Entity *> entities)
{
    QList<Player *> collisions;
    for (Entity *entity : entities)
    {
        if (entity->tag == "player")
        {
            bool collide = Collision::collide(getRegion(), entity->getRect());
            Player *player = dynamic_cast<Player *>(entity);
            if (collide) collisions.push_front(player);
        }
    }
    return collisions;
}

QRect Spell::getRect()
{
    return QRect(x, y, width, height);
}

QRegion Spell::getRegion()
{
    int offset = 10;
    int xPoss = x + offset;
    int yPoss = y + offset;
    int w = width - offset * 2;
    int h = height - offset * 2;
    return QRegion(xPoss, yPoss, w, h, QRegion::Ellipse);
}

void Spell::setStartPoss(int x, int y)
{
    xStart = x;
    yStart = y;
}

void Spell::mousePressEvent(QMouseEvent *)
{
    if (active) return;
    canMove = true;
    Grid *grid = dynamic_cast<Game *>(parent())->getGrid();
    gridRect = grid->geometry();
}

void Spell::mouseReleaseEvent(QMouseEvent *)
{
    if (active) return;

    canMove = false;
    bool contains = gridRect.contains(getRect());
    int money = GameController::getInstance()->getMoney();
    if (contains && money >= castCost) activate();
    else move(xStart, yStart);
}

void Spell::mouseMoveEvent(QMouseEvent *event)
{
    if (!canMove) return;
    int offset = width / 2;
    int x = this->x + event->x() - offset;
    int y = this->y + event->y() - offset;
    move(x, y);
}

void Spell::moveEvent(QMoveEvent *event)
{
    x = event->pos().x();
    y = event->pos().y();
}

void Spell::resizeEvent(QResizeEvent *event)
{
    width = event->size().width();
    height = event->size().height();
    loadIconAnimation();
}

QString Spell::getType() const
{
    return type;
}

void Spell::setType(const QString &value)
{
    type = value;
}

int Spell::getDuration() const
{
    return duration;
}

void Spell::setDuration(int value)
{
    duration = value;
}

void Spell::deactivate()
{
    active = false;
    loadNewSpell();
    this->close();
    dynamic_cast<Game *>(parent())->removeSpell(this);
}

int Spell::getCastCost() const
{
    return castCost;
}

void Spell::setCastCost(int value)
{
    castCost = value;
}

QString Spell::getAnimation() const
{
    return animation;
}

void Spell::setAnimation(const QString &value)
{
    animation = value;
}

void Spell::load()
{
    loadIconAnimation();
}

void Spell::activate()
{
    setStyleSheet("background-color:rgba(255, 255, 255, 0);");
    GameController::getInstance()->spendMoney(castCost);
    active = true;

    int size = width * 3;
    int offset = width;
    int x = this->x - offset;
    int y = this->y - offset;

    move(x, y);
    resize(size, size);
    loadAnimation();
    setUpdateDelay();
    update();
    QTimer::singleShot(duration, this, &Spell::deactivate);
}

void Spell::loadIconAnimation()
{
    QMovie *movie = new QMovie(this);
    movie->setFileName(iconAnimation);
    movie->setScaledSize(this->size());
    this->setMovie(movie);
    movie->start();
}

void Spell::loadAnimation()
{
    this->movie()->stop();
    QMovie *movie = new QMovie(this);
    movie->setFileName(animation);
    movie->setScaledSize(this->size());
    this->setMovie(movie);
    movie->start();
}

void Spell::loadNewSpell()
{
    int x = xStart;
    int y = yStart;

    Spell *spell = new Spell(parentWidget(), type, iconAnimation);
    spell->setAnimation(animation);
    spell->move(x, y);
    spell->setStartPoss(x, y);
    spell->show();

    dynamic_cast<Game *>(parent())->addSpell(spell);
}

void Spell::setUpdateDelay()
{
    if (type == "fire") updateDelay = 500;
    if (type == "ice") updateDelay = 50;
    if (type == "dark") updateDelay = 50;
}

void Spell::burn(QList<Player *> players)
{
    for (Player *player : players)
    {
        player->hit(burnDamage);
        if (player->getGladiator()->getHealth() <= 0)
        {
            GameController::getInstance()->addMoney(onKillMoney);
        }
    }
}

void Spell::freeze(QList<Player *> players)
{
    for (Player *player : players)
    {
        player->freeze(freezeTime);
    }
}

void Spell::confuse(QList<Player *> players)
{
    for (Player *player : players)
    {
        player->confuse(confuseTime);
    }
}
