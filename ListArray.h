#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <iostream> // Incluye la cabecera para la sobrecarga del operador <<

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;             // Puntero al inicio del array
    int max;            // Tamaño actual del array
    int n;              // Número de elementos en la lista
    static const int MINSIZE = 2; // Tamaño mínimo del array (inicializado a 2)

    // Método privado para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() {
        max = MINSIZE;
        n = 0;
        arr = new T[max];
    }

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Métodos heredados de la interfaz List<T>
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición no válida");
        }
        if (n == max) {
            resize(max * 2); // Duplica la capacidad si está llena
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e); // Inserta al final
    }

    void prepend(T e) override {
        insert(0, e); // Inserta al principio
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición no válida");
        }
        T removed = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        n--;
        if (n < max / 4 && max > MINSIZE) {
            resize(max / 2); // Reduce la capacidad si está "demasiado vacío"
        }
        return removed;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición no válida");
        }
        return arr[pos];
    }

    int search(T e) const override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i; // Devuelve la posición si se encuentra.
            }
        }
        return -1; // Devuelve -1 si no se encuentra.
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición no válida");
        }
        return arr[pos];
    }

    // Sobrecarga del operador << para imprimir la lista
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};

#endif