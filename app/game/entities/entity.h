#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
public:
    virtual ~Entity() {};

    virtual void update() = 0;

    virtual void draw() = 0;
};

#endif // ENTITY_H
