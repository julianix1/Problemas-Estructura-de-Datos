#include <iostream>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:

	void mostrar()
	{
		Nodo* act = this->prim;

		while (act != nullptr)
		{
			cout << act->elem << " ";
			act = act->sig;
		}

		cout << endl;
	}

	void mezclaOrdenada(linked_list_ed_plus& lista)
	{
		if (this -> prim == nullptr)
		{
			this->prim = lista.prim;
			lista.prim = nullptr;
		}
		else
		{
			Nodo* lista1 = this->prim;
			Nodo* lista2 = lista.prim;
 
			if (lista1 != nullptr && lista2 != nullptr && lista1->elem > lista2->elem)
			{
				Nodo* aux;
				aux = lista2->sig;

				lista2->sig = lista1;
				this->prim = lista2;

				lista1 = lista2;
				lista2 = aux;
				lista.prim = lista2;
			}

			while (lista1->sig != nullptr && lista2 != nullptr)
			{
				if (lista1->sig -> elem > lista2->elem)
				{
					Nodo* aux = lista2->sig;
					lista2->sig = lista1->sig;
					lista1->sig = lista2;

					lista1 = lista2;
					lista2 = aux;
					lista.prim = lista2;
				}
				else
				{
					lista1 = lista1 -> sig;
				}
			}

			if (lista2 != nullptr)
			{
				lista1->sig = lista2;
				lista.prim = nullptr;
				lista2 = nullptr;
			}
		}	
	}

};