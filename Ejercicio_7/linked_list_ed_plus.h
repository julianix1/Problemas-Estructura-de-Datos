#pragma once
#include "linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:
	void invertir(){
		Nodo* actual = this->prim;
		Nodo* anterior = nullptr;
		
		while(actual != nullptr)
		{
			Nodo* siguiente = actual->sig;
			actual->sig = anterior;
			anterior = actual;
			actual = siguiente;
		}

		Nodo* aux = this->prim;
		this->prim = this->ult;
		this->ult = aux;
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