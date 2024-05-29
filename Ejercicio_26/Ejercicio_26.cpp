// Nombre del alumno Julian Regura Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "cola.h"

using namespace std;

bool resuelveCaso() {
    string entrada;
    getline(cin, entrada);

    if (entrada == ".") return false;

    cola<char> datos;

    for (int i = 0; i < entrada.size(); i++)
    {
        datos.push(entrada[i]);
    }

    while (!datos.empty())
    {
        cout << datos.front();
        datos.pop();
    }

    cout << endl;

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
