// Nombre del alumno Julian Regura Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>;

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    cin >> num;

    if (num == -1) return false;

    stack<int> pila;

    while (num != -1){
        while (pila.size() != 0 && pila.top() <= num){
            pila.pop();
        }

        if (pila.size() == 0) cout << "No HAY" << endl;
        else cout << pila.top() << endl;

        pila.push(num);
        cin >> num;
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
