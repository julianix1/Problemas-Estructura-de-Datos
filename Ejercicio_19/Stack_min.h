#pragma once
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class Stack_min{
	stack<T> pilaAuxiliar;
	stack<T> pilaPrincipal;
public:

	T top() {
		return pilaPrincipal.top();
	}

	void pop() {
		if (pilaPrincipal.top() == pilaAuxiliar.top()) {
			pilaAuxiliar.pop();
		}

		pilaPrincipal.pop();
	}

	bool empty() {
		return pilaPrincipal.empty();
	}

	void push(T elem){
		pilaPrincipal.push(elem);

		if(pilaAuxiliar.empty() || pilaAuxiliar.top() >= elem ) {
			pilaAuxiliar.push(elem);
		}
	}

	T min_stack(){
		return pilaAuxiliar.top();
	}

	void operacion() {
		char operacion;

		cin >> operacion;

		switch (operacion)
		{
		case 'A':
			T entrada;
			cin >> entrada;
			this->push(entrada);
			break;
		case 'D':
			if (this->empty()) {
				cout << "ERROR: Pila vacia" << endl;
			}
			else {
				this->pop();
			}
			break;
		case 'C':
			if (this->empty()) {
				cout << "ERROR: Pila vacia" << endl;
			}
			else {
				cout << this->top() << endl;
			}
			break;
		case 'M': 
			if (this->empty()) {
				cout << "ERROR: Pila vacia" << endl;
			}
			else {
				cout << this->min_stack() << endl;
			}
		}
	}
};