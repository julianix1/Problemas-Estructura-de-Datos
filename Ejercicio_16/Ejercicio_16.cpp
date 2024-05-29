// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool esSimbolo(char letra) {
    return letra == '[' || letra == ']' || letra == '{' || letra == '}' || letra == '(' || letra == ')';
}

bool esSimboloCorrespondiente(char letra1, char letra2)
{
    return (letra1 == '[' && letra2 == ']') || (letra1 == '{' && letra2 == '}') || (letra1 == '(' && letra2 == ')');
}

/*No es lo mas eficiente del mundo pero me da pereza cambiarlo*/
bool resuelveCaso() {
    string linea;
    stack<char> pila;
    char letra;
    getline(cin, linea);

    if (!std::cin) return false;

    stringstream lectura(linea);
    lectura >> letra;
    while (lectura){
        if(esSimbolo(letra)){
            if (pila.size() != 0 && esSimboloCorrespondiente(pila.top(), letra)){
                pila.pop();
            }
            else {
                pila.push(letra);
            }
        }
        lectura >> letra;
    }

    if (pila.size() == 0){
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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