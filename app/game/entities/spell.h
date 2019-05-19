#ifndef SPELL_H
#define SPELL_H

#include <QLabel>

#include "util/collision.h"
#include "entity.h"

class Spell : public QLabel
{
    Q_OBJECT
public:
    Spell(QWidget *parent = nullptr, QString type = "", QString animation = "");

    ~Spell();

    QList<Entity *> playersIn(QList<Entity *> entities);

    QRect getRect();

    void setStartPoss(int x, int y);

    QString getType() const;
    void setType(const QString &value);

    int getDuration() const;
    void setDuration(int value);

    QString getAnimation() const;
    void setAnimation(const QString &value);

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
    QRect gridRect;

    void activate();

    void loadIconAnimation();

    void loadAnimation();

    void loadNewSpell();
};

#endif // SPELL_H
