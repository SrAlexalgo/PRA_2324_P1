#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <iostream>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;         

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición no válida");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "[";
        Node<T>* current = list.first;
        for (int i = 0; i < list.n; i++) {
            out << current->data;
            if (i < list.n - 1) {
                out << ", ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }

};

#endif