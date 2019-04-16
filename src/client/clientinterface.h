#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "client.h"


class ClientInterface
{
public:
    void getGladiators();

private:
    static Client *client;
};

#endif // CLIENTINTERFACE_H
