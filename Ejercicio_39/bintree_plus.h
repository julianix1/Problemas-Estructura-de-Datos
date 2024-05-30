#include "bintree_eda.h"
#include <iostream>

using namespace std;

template <class T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:
    bintree_plus() : bintree <T >() {}
    bintree_plus(bintree_plus <T > const& l, T const& e, bintree_plus <T > const& r) :bintree <T >(l, e, r) {}

    int resolver(T valor){
        if (this->raiz == nullptr) return -1;

        vector<Link> lista(1);
        lista[0] = this->raiz;
        return resolverL(lista,0, valor);
    }

private:

    int resolverL(const vector<Link>& nodos, int piso, T buscado){
        if (nodos.size() == 0) return -1;
        else
        {
            bool aparecido = false;
            vector<Link> nuevaLista;
            piso++;

            for (Link nodo : nodos)
            {
                if (nodo->elem == buscado)
                {
                    if (aparecido) return piso;
                    aparecido = true;
                }

                if (nodo->left != nullptr) nuevaLista.push_back(nodo->left);
                if (nodo->right != nullptr) nuevaLista.push_back(nodo->right);
            }

            return resolverL(nuevaLista, piso, buscado);
        }
        
    }
};

template <typename T >
inline bintree_plus<T> leerArbol_plus(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_plus <T> iz = leerArbol_plus(vacio);
        bintree_plus <T> dr = leerArbol_plus(vacio);
        return { iz , raiz , dr };
    }
}