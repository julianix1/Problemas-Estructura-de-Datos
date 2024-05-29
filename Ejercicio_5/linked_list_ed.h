#pragma once

//
//  linked_list_ed.h
//
//  Implementación del TAD linked_list con nodos enlazados
//  y punteros al primer y  último nodo
//
//  Estructuras de Datos. Grupos A y C. Curso 2021/22
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2021 Isabel Pita 
//  Adaptada de la implementación del queue realizada por Alberto Verdejo

#ifndef linked_list_ed_h
#define linked_list_ed_h

#include <stdexcept>  // std::domain_error

template <typename T>
class linked_list_ed {
protected:

    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el último de la lista enlazada.
     */
    struct Nodo {
        Nodo() : sig(nullptr) {}
        Nodo(T const& elem, Nodo* si = nullptr) : elem(elem), sig(si) {}
        T elem;
        Nodo* sig;
    };

    // punteros al primer y último elemento
    Nodo* prim;
    Nodo* ult;

public:

    // constructor: lista enlazada vacia 
    linked_list_ed() : prim(nullptr), ult(nullptr) {}

    // destructor
    ~linked_list_ed() {
        libera();
    }

    // constructor por copia
    linked_list_ed(linked_list_ed<T> const& other) {
        copia(other);
    }

    // operador de asignación
    linked_list_ed<T>& operator=(linked_list_ed<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // añadir un elemento al final de la lista enlazada
    void push_back(T const& elem) {
        Nodo* nuevo = new Nodo(elem);

        if (ult != nullptr)
            ult->sig = nuevo;
        ult = nuevo;
        if (prim == nullptr) // la lista estaba vacía
            prim = nuevo;
    }

    // añadir un elemento al principio de la lista enlazada
    void push_front(T const& elem) {
        Nodo* nuevo = new Nodo(elem, prim);
        prim = nuevo;
        if (ult == nullptr) // la lista estaba vacía
            ult = nuevo;
    }


    // eliminar el primero de la lista enlazada
    void pop_front() {
        if (empty())
            throw std::domain_error("eliminando de una lista enlazada vacia");
        Nodo* a_borrar = prim;
        prim = prim->sig;
        if (prim == nullptr) // la lista enlazada se ha quedado vacía
            ult = nullptr;
        delete a_borrar;
    }

    // consultar si la lista enlazada está vacía
    bool empty() const {
        return this->prim == nullptr;
    }

protected:

    void libera() {
        while (prim != nullptr) {
            Nodo* a_borrar = prim;
            prim = prim->sig;
            delete a_borrar;
        }
        ult = nullptr;
    }

    // this está sin inicializar
    void copia(linked_list_ed const& other) {
        if (other.empty()) {
            prim = ult = nullptr;
        }
        else {
            Nodo* act = other.prim; // recorre la cola original
            ult = new Nodo(act->elem); // último nodo copiado
            prim = ult;
            while (act->sig != nullptr) {
                act = act->sig;
                ult->sig = new Nodo(act->elem);
                ult = ult->sig;
            }
        }
    }
};

#endif // linked_list_ed_h