//
//  double_linked_list_ed.h
//
//  Implementación del TAD double_linked_list con nodos doblemente
//   enlazados, circular, nodo cabecera (nodo fantasma) y puntero 
//   al nodo cabecera
//
//  Estructuras de Datos. Grupos A y C. Curso 2021/22
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2021 Isabel Pita 
//  Adaptada de la implementación del deque realizada por Alberto Verdejo

#ifndef double_linked_list_ed_h
#define double_linked_list_ed_h

#include <stdexcept>
#include <cassert>

template <typename T>
class double_linked_list_ed {
protected:
    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y dos punteros, uno al nodo anterior y otro al nodo siguiente.
     */
    struct Nodo {
        Nodo() : ant(nullptr), sig(nullptr) {}
        Nodo(T const& elem, Nodo* ant, Nodo* sig) : elem(elem), ant(ant), sig(sig) {}
        T elem;
        Nodo* ant;
        Nodo* sig;
    };

    // puntero al nodo fantasma
    Nodo* fantasma;

public:

    // constructor: cola doble vacía
    double_linked_list_ed() : fantasma(new Nodo()) {
        fantasma->sig = fantasma->ant = fantasma; // circular
    }

    // destructor
    ~double_linked_list_ed() {
        libera();
    }

    // constructor por copia
    double_linked_list_ed(double_linked_list_ed<T> const& other) {
        copia(other);
    }

    // operador de asignación
    double_linked_list_ed<T>& operator=(double_linked_list_ed<T> const& that) {
        if (this != &that) {
            libera();
            copia(that);
        }
        return *this;
    }

    // añadir un elemento por el principio
    void push_front(T const& e) {
        inserta_elem(e, fantasma, fantasma->sig);
    }

    // añadir un elemento por el final
    void push_back(T const& e) {
        inserta_elem(e, fantasma->ant, fantasma);
    }

    // consultar el primer elemento de la lista
    T const& front() const {
        if (empty())
            throw std::domain_error("la lista vacia no tiene primero");
        return fantasma->sig->elem;
    }

    // consultar el último elemento de la lista
    T const& back() const {
        if (empty())
            throw std::domain_error("la lista vacia no tiene ultimo");
        return fantasma->ant->elem;
    }

    // eliminar el primer elemento
    void pop_front() {
        if (empty())
            throw std::domain_error("eliminando el primero de una lista vacia");
        borra_elem(fantasma->sig);
    }

    // eliminar el último elemento
    void pop_back() {
        if (empty())
            throw std::domain_error("eliminando el ultimo de una lista vacia");
        borra_elem(fantasma->ant);
    }

    // consultar si la lista está vacía
    bool empty() const {
        return fantasma->sig == fantasma;
    }

protected:

    void libera() {
        // primero rompemos la circularidad
        fantasma->ant->sig = nullptr;
        fantasma->ant = nullptr;
        while (fantasma != nullptr) {
            Nodo* a_borrar = fantasma;
            fantasma = fantasma->sig;
            delete a_borrar;
        }
    }

    void copia(double_linked_list_ed<T> const& other) {
        fantasma = new Nodo();
        fantasma->sig = fantasma;
        fantasma->ant = fantasma;

        // act recorre la cola que estamos copiando
        Nodo* act = other.fantasma->sig;
        while (act != other.fantasma) {
            push_back(act->elem);
            act = act->sig;
        }
    }

    // insertar un nuevo nodo entre anterior y siguiente
    Nodo* inserta_elem(T const& e, Nodo* anterior, Nodo* siguiente) {
        Nodo* nuevo = new Nodo(e, anterior, siguiente);
        anterior->sig = nuevo;
        siguiente->ant = nuevo;
        return nuevo;
    }

    // eliminar el nodo n
    void borra_elem(Nodo* n) {
        assert(n != nullptr);
        n->ant->sig = n->sig;
        n->sig->ant = n->ant;
        delete n;

    }
};

#endif // double_linked_list_ed_h