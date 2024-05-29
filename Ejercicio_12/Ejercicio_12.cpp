// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "double_linked_list_ed_plus.h"

using namespace std;

bool resuelveCaso() {
    int num,pivote,aux;

    cin >> num;
    cin >> pivote;

    if (!std::cin) return false;

    double_linked_list_ed_plus datos;

    for(int i = 0; i< num; i++)
    {
        cin >> aux;
        datos.push_back(aux);
    }

    datos.particion(pivote);
    datos.mostrar();

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