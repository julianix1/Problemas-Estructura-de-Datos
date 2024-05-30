// Nombre del alumno Julian Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include "bintree_eda.h"

using namespace std;

// función que resuelve el problema
void resolver(const bintree<int>& arbol, queue<int>& cola) {
    if (arbol.empty()) return;
    else if (arbol.left().empty() && arbol.right().empty()) {
        cola.push(arbol.root());
    }
    else{
        resolver(arbol.left(), cola);
        resolver(arbol.right(),cola);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol;
    queue<int> cola;
    arbol = leerArbol(-1);
    resolver(arbol,cola);

    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }

    cout << endl;
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