#include "spell.h"

#include <game/grid.h>

#include <game.h>

Spell::Spell(QWidget *parent, QString _type, QString animation_) : QLabel(parent)
{
    canMove = true;
    active = false;
    type = _type;
    animation = animation_;
    duration = 5000;

    int size =  50;
    resize(size, size);
    setStyleSheet("background-color:rgba(255, 255, 255, 0);"
                  "border-image:url(" + animation + ")");
}

Spell::~Spell()
{

}

QList<Entity *> Spell::playersIn(QList<Entity *> entities)
{
    QList<Entity *> collisions;
    for (Entity *entity : entities)
    {
        if (entity->tag == "")
        {
            bool collide = Collision::collide(entity->getRect(), getRect());
            if (collide) collisions.push_front(entity);
        }
    }
    return collisions;
}

QRect Spell::getRect()
{
    QRect rect(x(), y(), width(), height());
    return rect;
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
    if (contains) activate();
    else move(xStart, yStart);
}

void Spell::mouseMoveEvent(QMouseEvent *event)
{
    if (!canMove) return;
    int offset = this->width() / 2;
    int x = this->x() + event->x() - offset;
    int y = this->y() + event->y() - offset;
    move(x, y);
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
    this->close();
}

QString Spell::getAnimation() const
{
    return animation;
}

void Spell::setAnimation(const QString &value)
{
    animation = value;
}

void Spell::activate()
{
    active = true;

    int size = width() * 3;
    int offset = width();
    int x = this->x() - offset;
    int y = this->y() - offset;

    move(x, y);
    resize(size, size);
    loadAnimation();
    QTimer::singleShot(duration, this, &Spell::deactivate);
}

void Spell::loadAnimation()
{
    setStyleSheet("border-image:0");

    QMovie *movie = new QMovie(this);
    movie->setFileName(animation);
    movie->setScaledSize(this->size());
    this->setMovie(movie);
    movie->start();
}
