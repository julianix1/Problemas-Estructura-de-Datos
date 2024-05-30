#pragma once
#include "bintree_eda.h"

class bintree_plus : public bintree<int> {
	using Link = typename bintree<int>::Link;
private:
	int sumaValores(Link arbol) {
		if (arbol == nullptr) return 0;
		else {
			int hizq = sumaValores(arbol->left);
			int der = sumaValores(arbol->right);
			return hizq + der + arbol->elem;
		}
	}

public:
	bintree_plus() : bintree<int>() {};
	bintree_plus(bintree_plus const& l, int const& e, bintree_plus const& r) :bintree<int>(l,e,r) {};

	int sumaValores() {
		return sumaValores(this->raiz);
	}
};

// lee un �rbol binario de la entrada est�ndar
inline bintree_plus leerArbol(int vacio) {
	int raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un �rbol vac�o
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}
}