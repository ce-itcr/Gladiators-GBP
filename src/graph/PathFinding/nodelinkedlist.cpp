#include "nodelinkedlist.h"


NodeLinkedList::NodeLinkedList(Vector *element) {
    this->element = element;
    next = nullptr;
}

// Eliminar todos los Nodos
void NodeLinkedList::delete_all(){
    if (next)
        next->delete_all();
    delete this;
}

// Imprimir un Nodo
void NodeLinkedList::print(){
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << "(" << element->getX() << ", " << element->getY() << ")" "-> ";
}
