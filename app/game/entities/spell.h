#ifndef SPELL_H
#define SPELL_H

#include <QLabel>

#include "util/collision.h"
#include "entity.h"
#include "game/entities/player.h"

class Spell : public QLabel
{
    Q_OBJECT
public:
    Spell(QWidget *parent = nullptr, QString type = "", QString animation = "");

    ~Spell();

    void update();

    QList<Player *> playersIn(QList<Entity *> entities);

    QRect getRect();

    QRegion getRegion();

    void setStartPoss(int x, int y);

    QString getType() const;
    void setType(const QString &value);

    int getDuration() const;
    void setDuration(int value);

    QString getAnimation() const;
    void setAnimation(const QString &value);

    int getCastCost() const;
    void setCastCost(int value);

signals:

public slots:
    void load();

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

private slots:
    void deactivate();

private:
    bool canMove;
    bool active;
    QString type;
    QString animation;
    QString iconAnimation;
    int xStart;
    int yStart;
    int duration;
    int updateDelay;
    QRect gridRect;
    int castCost;
    int burnDamage;
    int freezeTime;
    int confuseTime;
    static int onKillMoney;

    void activate();

    void loadIconAnimation();

    void loadAnimation();

    void loadNewSpell();

    void setUpdateDelay();

    void burn(QList<Player *> players);

    void freeze(QList<Player *> players);

    void confuse(QList<Player *> players);
};

#endif // SPELL_H
