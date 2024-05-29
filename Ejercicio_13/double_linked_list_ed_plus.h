#pragma once
#include "double_linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
	void doblar() {
		Nodo* actual = this->fantasma->sig;
		
		while (this->fantasma->ant != actual && actual != this->fantasma)
		{
			Nodo* final = this->fantasma->ant;
			final->ant->sig = this->fantasma;
			this->fantasma->ant = final->ant;

			actual->sig->ant = final;
			final->sig = actual->sig;
			final->ant = actual;
			actual->sig = final;
			actual = final->sig;
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