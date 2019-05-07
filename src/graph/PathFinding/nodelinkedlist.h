#ifndef NODELINKEDLIST_H
#define NODELINKEDLIST_H

#include <iostream>
#include "graph/PathFinding/vector.h"

using namespace std;

class NodeLinkedList
{
public:

    NodeLinkedList(Vector *element);

    NodeLinkedList *next = nullptr;
    Vector *element = nullptr;

    void delete_all();
    void print();
};

#endif // NODELINKEDLIST_H
