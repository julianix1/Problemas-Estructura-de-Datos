#pragma once
#include "linked_list_ed.h"
#include <iostream>

using namespace std;

class linked_list_ed_plus : public linked_list_ed<string> {
	using Nodo = typename linked_list_ed<string>::Nodo;
public:
	void palabraEmpiezan(char letra)
	{
		Nodo* actual = this->prim;
		
		while (actual != nullptr)
		{
			if (actual->elem[0] == letra)
				cout << actual->elem << " ";

			actual = actual->sig;
		}

		cout << endl;
	}
};