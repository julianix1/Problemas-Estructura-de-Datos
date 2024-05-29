// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60

#include "hora.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Hora h1(0, 0, 0);
    Hora h2(0, 0, 0);

    cin >> h1 >> h2;

    try
    {
        Hora res = h1 + h2;
        cout << res << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
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