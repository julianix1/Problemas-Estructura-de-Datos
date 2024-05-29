// Nombre del alumno Julian Regura Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num,saltos;
    list<int> candidatos;

    cin >> num;
    cin >> saltos;

    if (num == 0 && saltos == 0) return false;

    for (int i = 1; i<= num;i++)
    {
        candidatos.push_front(i);
    }

    while(candidatos.size() > 1)
    {
        for (int i = 0; i < saltos; i++){
            candidatos.push_front(candidatos.back());
            candidatos.pop_back();
        }

        candidatos.pop_back();
    }

    cout << candidatos.front() << endl;

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
