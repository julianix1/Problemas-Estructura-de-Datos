#pragma once
#include <cmath>
#include "bintree_eda.h"

using namespace std;

struct resultado {
	int nodos;
	int hojas;
	int altura;
};

template <typename T>
class bintree_plus : public bintree<T> {
	using Link = typename bintree<T>::Link;
private:
	resultado estructura(const Link& arbol) {
		if(arbol == nullptr){
			return { 0,0,0 };
		}
		else {
			resultado hizq = estructura(arbol->left);
			resultado der = estructura(arbol->right);

			resultado calculo;
			calculo.nodos = hizq.nodos + der.nodos + 1;
			calculo.hojas = hizq.hojas + der.hojas;
			if (calculo.hojas == 0) calculo.hojas = 1;
			calculo.altura = max(hizq.altura, der.altura) + 1;
			
			return calculo;
		}
	}
public:
	bintree_plus() : bintree <T >() {}
	bintree_plus(bintree_plus <T > const& l, T const& e, bintree_plus <T > const& r) :bintree <T >(l, e, r) {}

	resultado estructura() {
		return estructura(this->raiz);
	}
};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_plus<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}
}