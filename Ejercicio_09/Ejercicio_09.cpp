// Nombre del alumno Julián reguera peñalosa
// Usuario del Juez A56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "linked_list_ed_plus.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num, aux;

    cin >> num;

    if (num == -1) return false;
    linked_list_ed_plus<int> lista;

    for (int i = 0; i < num; i++)
    {
        cin >> aux;
        lista.push_back(aux);
    }

    linked_list_ed_plus<int> res = lista.separar();

    lista.mostrar();
    res.mostrar();

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