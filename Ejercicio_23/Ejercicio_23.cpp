// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void duplicarLista(list<int>& lista) {
    auto it = lista.begin();

    while (it != lista.end()) {
        lista.insert(it, *it);
        it++;
    }
}

void mostrarLista(const list<int>& lista) {
    for (int dato : lista) {
        cout << dato << " ";
    }

    cout << endl;
}

bool resuelveCaso() {
    int num,entrada;

    cin >> entrada;

    if (!std::cin) return false;

    list<int> datos;

    while (entrada != 0) {
        datos.push_back(entrada);
        cin >> entrada;
    }

    duplicarLista(datos);
    mostrarLista(datos);

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