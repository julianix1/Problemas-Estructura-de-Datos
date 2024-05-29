#pragma once
#include "linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:
	void burbuja() {
		bool ordenado = false;

		while (!ordenado) {
			Nodo* actual = this->prim;
			ordenado = true;

			if(actual != nullptr && actual->elem > actual->sig->elem)
			{
				this->prim = actual->sig;
				actual->sig = actual->sig->sig;
				this->prim->sig = actual;
				actual = this->prim;
				ordenado = false;
			}

			while(actual != nullptr && actual->sig != nullptr && actual->sig->sig !=nullptr) {
				if (actual->sig->elem > actual->sig->sig->elem){
					intercambio(actual);
					ordenado = false;
				}

				actual = actual->sig;
			}
		}

	}

	void intercambio(Nodo* nodo){
		Nodo* segundo = nodo->sig->sig;
		nodo->sig->sig = segundo->sig;
		segundo->sig = nodo->sig;
		nodo->sig = segundo;

		if (segundo = this->ult){
			this->ult = segundo->sig;
		}
	}

	void mostrar() {
		Nodo* actual = this->prim;

		while (actual != nullptr) {
			cout << actual->elem << " ";
			actual = actual->sig;
		}

		cout << endl;
	}
};