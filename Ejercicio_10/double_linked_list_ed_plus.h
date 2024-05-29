#pragma once
#include "double_linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
	
	void intercambiarPares(){
		Nodo* actual = this->fantasma->sig;
		Nodo* aux;

		while (actual != this->fantasma && actual->sig != this->fantasma){
			aux = actual->sig->sig;
			actual->ant->sig = actual->sig;
			actual->sig->sig->ant = actual;
			actual->sig->ant = actual->ant;
			actual->sig->sig = actual;
			actual->ant = actual->sig;
			actual->sig = aux;
			actual = aux;
		}
	}

	void mostrar(){
		Nodo* actual = this->fantasma->sig;

		while (actual != this->fantasma){
			cout << actual->elem << " ";
			actual = actual->sig;
		}

		cout << endl;
	}
};