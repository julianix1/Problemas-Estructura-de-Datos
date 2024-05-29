// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <sstream>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    string frase;
    char letra;
    getline(cin, frase);

    if (!std::cin) return false;

    stringstream entrada(frase);
    entrada >> letra;
    list<char> resultado;
    auto it = resultado.begin();

    while (entrada)
    {
        switch (letra) {
        case '-':
            it = resultado.begin();
            break;
        case '+':
            it = resultado.end();
            break;
        case '*':
            if (it != resultado.end())
                it++;
            break;
        case '3':
            if (it != resultado.end()) {
                it = resultado.erase(it);
            }
            break;
        default:
            resultado.insert(it, letra);
            break;
        }

        entrada >> letra;
    }

    for (char letra : resultado)
        cout << letra;

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