#include "list.h"

using namespace std;

// Constructor por defecto
List::List(){
    m_num_nodes = 0;
    m_head = NULL;
}

// Insertar al inicio
void List::add_head(Vector *element){
    NodeLinkedList *new_node = new NodeLinkedList(element);
    NodeLinkedList *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

void List::add_end(Vector *element)
{
    NodeLinkedList *new_node = new NodeLinkedList (element);
    NodeLinkedList *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}

// Eliminar todos los nodos
void List::del_all(){
    m_head->delete_all();
    m_head = 0;
}

void List::del_by_data(Vector *element)
{
    NodeLinkedList *temp = m_head;
    NodeLinkedList *temp1 = m_head->next;

    int cont = 0;

    if (m_head->element->getX() == element->getX() && m_head->element->getY() == element->getY()) {
        m_head = temp->next;
    } else {
        while (temp1) {
            if (temp1->element->getX() == element->getX() && temp1->element->getY() == element->getY()) {
                NodeLinkedList *aux_node = temp1;
                temp->next = temp1->next;
                cout << "Deleted Node: (" << aux_node->element->getX() << ", " << aux_node->element->getY() << ")" << endl;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}


// Imprimir la Lista
void List::print(){
    NodeLinkedList *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

// Buscar el dato de un nodo

bool List::search(Vector *element){
    NodeLinkedList *temp = m_head;
    int elementX = element->getX();
    int elementY = element->getY();

    while (temp) {

//        cout << "(" << elementX << ", " << elementY << ")" << " -> ";
//        cout << "(" << temp->element->getX() << ", " << temp->element->getY() << ")" << endl;

        if (temp->element->getX() == elementX && temp->element->getY() == elementY) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

NodeLinkedList *List::getM_head() const {
    return m_head;
}

