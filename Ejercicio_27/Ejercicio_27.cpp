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
bool resuelveCaso() {
    int num, seg, aux;

    cin >> num;
    cin >> seg;

    if (!std::cin) return false;

    list<int> datos;
    list<int> maximos;

    if (num != 0)
    {
        cin >> aux;
        datos.push_back(aux);
        maximos.push_back(aux);
    }

    for (int i = 1; i < seg; i++)
    {
        cin >> aux;

        while (!maximos.empty() && maximos.back() < aux)
        {
            maximos.pop_back();
        }

        maximos.push_back(aux);
        datos.push_front(aux);
    }

    cout << maximos.front() << " ";

    for (int i = seg; i < num; i++)
    {
        if (datos.back() == maximos.front())
        {
            maximos.pop_front();
        }
        datos.pop_back();

        cin >> aux;

        while (!maximos.empty() && maximos.back() < aux)
        {
            maximos.pop_back();
        }

        maximos.push_back(aux);
        datos.push_front(aux);

        cout << maximos.front() << " ";
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