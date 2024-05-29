#pragma once
#include "linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class linked_lis_ed_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:
	void eliminarPares() {
		Nodo* actual = this->prim;

		while(actual != nullptr && actual->sig != nullptr){
			Nodo* aBorrar = actual->sig;
			actual->sig = aBorrar->sig;
			delete aBorrar;

			actual = actual->sig;
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
