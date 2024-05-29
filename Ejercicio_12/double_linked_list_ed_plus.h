#pragma once
#include "double_linked_list_ed.h"
#include <iostream>

using namespace std;

class double_linked_list_ed_plus : public double_linked_list_ed<int> {
	using Nodo = typename double_linked_list_ed<int>::Nodo;
public:
	void particion(int pivote) {
		Nodo* actual = this->fantasma->sig;
		Nodo* final = this->fantasma;

		while (actual != final) {
			if (actual->elem > pivote){
				if (final == this->fantasma) final = actual;

				Nodo* siguiente = actual->sig;
				actual->ant->sig = actual->sig;
				actual->sig->ant = actual->ant;

				actual->sig = this->fantasma;
				actual->ant = this->fantasma->ant;
				actual->ant->sig = actual;
				actual->sig->ant = actual;

				actual = siguiente;
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