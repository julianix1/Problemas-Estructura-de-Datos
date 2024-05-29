#pragma once
#include "double_linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
	void interseccion(double_linked_list_ed_plus<T> l2) {
		Nodo* punt1 = this->fantasma->sig, * punt2 = l2.fantasma->sig;
		while (punt1 != this->fantasma && punt2 != l2.fantasma)
		{
			if (punt1->elem == punt2->elem)
			{
				punt1 = punt1->sig;
				punt2 = punt2->sig;
			}
			else if (punt1->elem < punt2->elem)
			{
				Nodo* siguiente = punt1->sig;
				this->borra_elem(punt1);

				punt1 = siguiente;
			}
			else
			{
				punt2 = punt2->sig;
			}
		}

		if (punt1 != this->fantasma)
		{
			punt1->ant->sig = this->fantasma;//para cortar la lista 1 con los ultimos elementos sobrantes
			this->fantasma->ant = punt1->ant;

			punt1->ant = l2.fantasma->ant; //para q se elimine el final de la primera lista
			l2.fantasma->ant->sig = punt1;
			punt1->sig = l2.fantasma;
			l2.fantasma->ant = punt1;
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