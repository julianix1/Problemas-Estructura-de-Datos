// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include "bintree_eda.h"

using namespace std;

template<typename T>
T resolver(const bintree<T>& arbol) {
    if (arbol.left().empty() && arbol.right().empty()) {
        return arbol.root();
    }
    else if (arbol.left().empty()) {
        T der = resolver(arbol.right());
        return min(der, arbol.root());
    }
    else if (arbol.right().empty()) {
        T hizq = resolver(arbol.left());
        return min(hizq, arbol.root());
    }
    else {
        T hizq = resolver(arbol.left());
        T der = resolver(arbol.right());

        return min(min(hizq, der), arbol.root());
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    char letra;

    cin >> letra;

    if (!std::cin) return false;

    if(letra == 'N') {
        bintree<int> arbol;
        arbol = leerArbol(-1);

        if (!arbol.empty()) {
            int res = resolver(arbol);
            cout << res << endl;
        }
        else {
            cout << endl;
        }
    }
    else if (letra == 'P') {
        bintree<string> arbol;
        arbol = leerArbol((string)"#");
        
        if (!arbol.empty()) {
            string res = resolver(arbol);
            cout << res << endl;
        }
        else {
            cout << endl;
        }
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}