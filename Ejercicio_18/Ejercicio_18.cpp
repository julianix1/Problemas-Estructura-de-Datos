// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

struct accidente {
    string fecha;
    int victimas;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    accidente lectura;

    cin >> num;

    if (!std::cin) return false;

    stack<accidente> pila;

    for(int i = 0; i< num; i++)
    {
        cin >> lectura.fecha;
        cin >> lectura.victimas;

        while(pila.size() != 0 && pila.top().victimas <= lectura.victimas){
            pila.pop();
        }

        if(pila.size() == 0){
            cout << "NO HAY" << endl;
        }
        else {
            cout << pila.top().fecha << endl;
        }

        pila.push(lectura);
    }

    cout << "---" << endl;

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