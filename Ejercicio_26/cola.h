#pragma once
#include <iostream>
#include <stack>

using namespace std;

template <class T>
class cola {
protected:
	stack<T> pila1;
	stack<T> pila2;
public:
	cola(){};

	void push(T dato)
	{
		pila2.push(dato);
	}

	T front()
	{
		if (pila1.empty())
		{
			while (!pila2.empty())
			{
				pila1.push(pila2.top());
				pila2.pop();
			}
		}

		return pila1.top();
	}

	void pop()
	{
		if (pila1.empty())
		{
			while (!pila2.empty())
			{
				pila1.push(pila2.top());
				pila2.pop();
			}
		}

		pila1.pop();
	}

	bool empty()
	{
		return pila1.empty() && pila2.empty();
	}
};