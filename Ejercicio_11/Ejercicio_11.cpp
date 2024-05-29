// Nombre del alumno Julian Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "double_linked_list_ed_plus.h"

using namespace std;


void resuelveCaso() {
    int num;

    cin >> num;
    double_linked_list_ed_plus<int> datos1;
    double_linked_list_ed_plus<int> datos2;

    while (num != 0){
        datos1.push_back(num);
        cin >> num;
    }

    cin >> num;

    while (num != 0) {
        datos2.push_back(num);
        cin >> num;
    }

    datos1.interseccion(datos2);
    datos1.mostrar();
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