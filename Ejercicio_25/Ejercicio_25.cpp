// Nombre del alumno Julian Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "lista_plus.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int aux;

    lista_plus<int> datos;

    cin >> aux;
    while (aux != 0)
    {
        datos.push_back(aux);
        cin >> aux;
    }

    lista_plus<int>::reverse_iterator<int> it = datos.rend();

    for(int i = 0; i< datos.size();i++)
    {
        cout << it.elem() << " ";
        it.advance();
    }

    cout << endl;
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