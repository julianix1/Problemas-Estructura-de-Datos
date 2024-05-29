// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include "double_linked_list_ed_plus.h"

using namespace std;

bool resuelveCaso() {
    int num,aux;
    cin >> num;

    if (num == 0)
        return false;

    double_linked_list_ed_plus<int> lista;

    for(int i = 0; i< num; i++){
        cin >> aux;
        lista.push_back(aux);
    }

    lista.intercambiarPares();
    lista.mostrar();

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
