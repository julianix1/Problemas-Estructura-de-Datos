// Nombre del alumno Julian Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include "bintree_eda.h"

using namespace std;

struct resultado {
    int caminoMax;
    int caminoActual;
};

// función que resuelve el problema
resultado resolver(bintree<int> arbol) {
    if (arbol.empty()) return { 0,0 };
    else {
        resultado der = resolver(arbol.right());
        resultado hizq = resolver(arbol.left());
        resultado res;

        res.caminoMax = max(der.caminoMax, hizq.caminoMax);
        if (arbol.root() % 2 == 1) res.caminoActual = 0;
        else {
            res.caminoActual = max(der.caminoActual, hizq.caminoActual) + 1;
            res.caminoMax = max(res.caminoActual, res.caminoMax);
            res.caminoMax = max(res.caminoMax, der.caminoActual + hizq.caminoActual + 1);
        }

        return res;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol;
    arbol = leerArbol(-1);

    cout << resolver(arbol).caminoMax << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}