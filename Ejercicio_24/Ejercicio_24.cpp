// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60

#include <iostream>
#include <iomanip>
#include <deque>
#include <stack>
#include <string>

using namespace std;

bool esVocal(char letra) {
    bool result = letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u';
    result |= letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U';

    return result;
}

bool resuelveCaso() {
    string frase;
    char letra;
    deque<char> xprima;
    stack<char> x;
    getline(cin,frase);

    if (!std::cin) return false;

    if (frase.size() != 0 && frase.size() % 2 == 1) {
        xprima.push_front(frase[frase.size()-1]);
    }

    for (int i = frase.size() - 1- (frase.size() % 2); i >= 0; i = i-2){
        xprima.push_back(frase[i]);
        xprima.push_front(frase[i-1]);
    }
    
    for (char letra : xprima) {
        if (!esVocal(letra)) {
            x.push(letra);
        }
        else {
            while (!x.empty()) {
                cout << x.top();
                x.pop();
            }

            cout << letra;
        }
    }

    while (!x.empty()) {
        cout << x.top();
        x.pop();
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