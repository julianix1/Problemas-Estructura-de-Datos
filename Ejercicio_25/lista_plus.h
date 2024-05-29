#pragma once
#include "list_eda.h"

template <class T>
class lista_plus : public list<T> {
protected:
    using Nodo = typename deque<T>::Nodo;
public:
        lista_plus() {};
public:

    template <class Apuntado>
    class reverse_iterator {
        Nodo* act; //puntero al actual
        Nodo* fan; //puntero al fantasma

    public:
        reverse_iterator() : act(nullptr), fan(nullptr) {}

        void advance()
        {
            act = act->ant;
        }

        Apuntado elem()
        {
            return act->elem;
        }
    private:
        friend class lista_plus;
        reverse_iterator(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}
    };

    reverse_iterator<T> rbegin() {
        return reverse_iterator<T>(this->fantasma->sig, this->fantasma);
    }
    reverse_iterator<T> rend() {
        return reverse_iterator<T>(this->fantasma->ant, this->fantasma);
    }
};