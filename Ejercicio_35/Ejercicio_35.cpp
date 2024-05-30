// Nombre del alumno Julian Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include "bintree_eda.h"

using namespace std;

struct result {
    int rescatistas;
    int excursionistas;
};

// función que resuelve el problema
result resolver(bintree<int> arbol) {
    if (arbol.empty()) return {0,0};
    else {
        result der = resolver(arbol.right());
        result hizq = resolver(arbol.left());
        result res = { der.rescatistas + hizq.rescatistas , max(der.excursionistas ,hizq.excursionistas) + arbol.root()};
        if (res.rescatistas == 0 && arbol.root() != 0) res.rescatistas = 1;

        return res;
    }

}

void resuelveCaso() {
    bintree<int> arbol;
    arbol = leerArbol(-1);
    result res = resolver(arbol);
    cout << res.rescatistas << " " << res.excursionistas << endl;
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