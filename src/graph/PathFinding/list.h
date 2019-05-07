#ifndef LIST_H
#define LIST_H


#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "graph/PathFinding/nodelinkedlist.h"
#include "graph/PathFinding/vector.h"

using namespace std;

class List
{
public:
    List();

    void add_head(Vector *element);
    void add_end(Vector *element);
    void del_all();
    void del_by_data(Vector *element);
    void print();
    bool search(Vector *element);
    NodeLinkedList *m_head;
public:
    NodeLinkedList *getM_head() const;

private:
    int m_num_nodes;
};
#endif // LIST_H
