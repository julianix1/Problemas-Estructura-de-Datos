// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;

pair<int, int> solucion(bintree<int> arbol) //primer elemento es el caudal y el segundo el numero de tramos navegables 
{
    if (arbol.empty()) return make_pair(0, 0);
    else if (arbol.left().empty() && arbol.right().empty()) return make_pair(max(1 - arbol.root(), 0), 0);
    else
    {
        pair<int, int> hizquierda = solucion(arbol.left());
        pair<int, int> derecha = solucion(arbol.right());

        int tramos = hizquierda.second + derecha.second;
        int agua = hizquierda.first + derecha.first - arbol.root();
        agua = std::max(agua, 0);

        if (hizquierda.first >= 3) tramos++;
        if (derecha.first >= 3) tramos++;

        return make_pair(agua, tramos);
    }
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);

    pair<int, int> par = solucion(arbol);
    cout << par.second << endl;


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