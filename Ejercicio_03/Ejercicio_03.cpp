// Nombre del alumno Julián reguera peñalosa
// Usuario del Juez A60

#include "polinomio.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    Polinomio datos;
    int coeficiente, exponente, num, x;

    cin >> coeficiente >> exponente;

    if (!std::cin)
        return false;

    while (coeficiente != 0 || exponente != 0)
    {
        datos.AnadirMonomio(coeficiente, exponente);
        cin >> coeficiente >> exponente;
    }

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> x;
        cout << datos.Evalua(x) << " ";
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}