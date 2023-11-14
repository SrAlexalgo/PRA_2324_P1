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

    // Métodos heredados de la interfaz List<T>
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición no válida");
        }

        if (pos == 0) {
            prepend(e);
        } else if (pos == n) {
            append(e);
        } else {
            Node<T>* newNode = new Node<T>(e);
            Node<T>* current = first;

            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
            n++;
        }
    }

    void append(T e) override {
        Node<T>* newNode = new Node<T>(e);

        if (first == nullptr) {
            first = newNode;
        } else {
            Node<T>* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        n++;
    }

    void prepend(T e) override {
        Node<T>* newNode = new Node<T>(e);
        newNode->next = first;
        first = newNode;
        n++;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición no válida");
        }

        T removedElement;
        Node<T>* temp;

        if (pos == 0) {
            temp = first;
            first = first->next;
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
        }

        removedElement = temp->data;
        delete temp;
        n--;
        return removedElement;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición no válida");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }

        return current->data;
    }

    int search(T e) const override {
        Node<T>* current = first;
        for (int i = 0; i < n; ++i) {
            if (current->data == e) {
                return i;
            }
            current = current->next;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

};

#endif
