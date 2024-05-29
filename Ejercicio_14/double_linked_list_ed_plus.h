#pragma once
#include "double_linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
	void creciente() {
		Nodo* actual = this->fantasma->sig;
		actual = actual->sig;

		while (actual != this->fantasma){
			if(actual->ant->elem > actual->elem){
				Nodo* aEliminar = actual;
				actual = actual->sig;
				this->borra_elem(aEliminar);
			}
			else {
				actual = actual->sig;
			}
		}
	}

	void mostrar() {
		Nodo* actual = this->fantasma->sig;

		while (actual != this->fantasma) {
			cout << actual->elem << " ";
			actual = actual->sig;
		}

		cout << endl;
	}
};