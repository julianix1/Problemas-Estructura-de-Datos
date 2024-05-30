#include "bintree_eda.h"
#include <iostream>

using namespace std;

struct solucion {
    int profMin;
    int num;
};

const vector<int> primos({ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71 });

template <class T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:
    bintree_plus() : bintree <T >() {}
    bintree_plus(bintree_plus <T > const& l, T const& e, bintree_plus <T > const& r) :bintree <T >(l, e, r) {}

    solucion resolver() {
        {
            return resolverL(this->raiz, 1, {-1,-1});
        }
    }

private:

    solucion resolverL(const Link& r, int profActual,solucion sol) {
        
        if (r == nullptr || (sol.profMin != -1 && profActual >= sol.profMin)) return sol;
        else
        {
            
            if(!esPrimo(r->elem))
            {
                if (r->elem % 7 == 0) return{ profActual, r->elem };
                else
                {
                    solucion hizquierda = resolverL(r->left, profActual + 1, sol);
                    solucion derecha = resolverL(r->right, profActual + 1, sol);

                    if (hizquierda.profMin != -1)
                    {
                        if (derecha.profMin != -1 && hizquierda.profMin > derecha.profMin)
                        {
                            return derecha;
                        }
                        else
                        {
                            return hizquierda;
                        }
                    }
                    else if (derecha.profMin != -1) return derecha;

                    return sol;
                }
            }

            return sol;
        }
    }

    bool esPrimo(int num)
    {
        int i = 0;
       
        while ((i< primos.size()) && (num%primos[i] != 0))
        {
            i++;
        }

        return (i == primos.size() || num == primos[i]);
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