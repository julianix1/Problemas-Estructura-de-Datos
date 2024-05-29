#include "linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:
	void duplicar() {
		Nodo* actual = this->prim;
		Nodo* nuevo = nullptr;

		while (actual != nullptr)
		{
			nuevo = new Nodo(actual->elem);
			nuevo->sig = actual->sig;
			actual->sig = nuevo;

			actual = nuevo->sig;
		}

		this->ult = nuevo;
	}

	void mostrar() {
		Nodo* actual = this->prim;

		while (actual != nullptr) {
			cout << actual->elem <<" ";
			actual = actual->sig;
		}

		cout << endl;
	}
};