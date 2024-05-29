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

	linked_list_ed_plus separar()
	{
		linked_list_ed_plus result;

		Nodo* lista1 = this->prim;
		Nodo* lista2 = result.prim;
		Nodo* aux;
		bool inicio = true;
		bool primero = true;

		
		while (inicio && lista1 != nullptr)
		{
			if (lista1->elem == 0)
			{
				aux = lista1;
				lista1 = lista1->sig;
				delete aux;
				this->prim = lista1;
			}
			else if (lista1->elem < 0)
			{
				if (primero) {
					result.prim = lista1;
					primero = false;
				}
				else
				{
					lista2->sig = lista1;
				}
				lista2 = lista1;
				this->prim = lista1->sig;
				lista1 = lista1->sig;
				lista2->sig = nullptr;
			}
			else inicio = false;
		}

		if (lista1 != nullptr)
		{
			while (lista1->sig != nullptr)
			{
				if (lista1->sig->elem == 0)
				{
					aux = lista1->sig;
					lista1->sig = lista1->sig->sig;
					delete aux;
				}
				else if (lista1->sig->elem < 0)
				{
					if (primero) {
						result.prim = lista1->sig;
						primero = false;
					}
					else
					{
						lista2->sig = lista1->sig;
					}
					lista2 = lista1->sig;
					lista1->sig = lista1->sig->sig;
					lista2->sig = nullptr;
				}
				else lista1 = lista1->sig;
			}
		}
		

		return result;
	}
};