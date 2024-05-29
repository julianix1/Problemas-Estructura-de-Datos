// Nombre del alumno Julian Regura Peñalosa
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Stack_min.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    char tipo;

    cin >> num;
    cin >> tipo;

    if (num == 0) return false;
    
    if (tipo == 'I') {
        Stack_min<int> pila;

        for (int i = 0; i < num; i++) {
            pila.operacion();
        }
    }
    else {
        Stack_min<char> pila;

        for (int i = 0; i < num; i++) {
            pila.operacion();
        }
    }

    cout << "---" << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
