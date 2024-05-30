// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_plus.h"

using namespace std;

void resuelveCaso() {
    char letra;
    int solucion;

    cin >> letra;

    if (letra == 'N')
    {
        int repetido;

        cin >> repetido;

        bintree_plus<int> arbol = leerArbol_plus(-1);
       solucion = arbol.resolver(repetido);
    }
    else if (letra == 'C')
    {
        char repetido;

        cin >> repetido;

        bintree_plus<char> arbol = leerArbol_plus('.');
        solucion = arbol.resolver(repetido);
    }

    if (solucion == -1) cout << "NO EXISTE" << endl;
    else cout << solucion << endl;

    
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