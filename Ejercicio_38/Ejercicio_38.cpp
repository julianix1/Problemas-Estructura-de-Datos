// Nombre del alumno Julián Reguera Peñalosa
// Usuario del Juez A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <sstream>
#include "bintree_eda.h"

using namespace std;

bintree<int> sol(const vector<int>& preOrder, const vector<int>& inOrder, int iniPre, int finPre, int iniIn, int finIn) //los fin apuntan al ultimo elemento .size()-1
{
    if (iniPre > finPre) return bintree<int>();
    else if (iniPre == finPre) 
        return bintree<int>(preOrder[iniPre]);
    else
    {
        int particion = 0;
        int nodo = preOrder[iniPre];

        while (inOrder[iniIn+particion] != nodo)
        {
            particion++;
        }

        bintree<int> hizquierda = sol(preOrder, inOrder, iniPre+1, iniPre+particion, iniIn, iniIn + particion - 1);
        bintree<int> derecha = sol(preOrder, inOrder, iniPre + particion + 1, finPre , iniIn + particion + 1, finIn);

        return bintree<int>(hizquierda, nodo, derecha);
    }
}

bintree<int> crearArbol(const vector<int>& preOrder, const vector<int>& inOrder) //los fin apuntan al ultimo elemento .size()-1
{
    return sol(preOrder, inOrder, 0, preOrder.size() - 1, 0, inOrder.size() - 1);
}

bool resuelveCaso() {
    vector<int> inOrder;
    vector<int> preOrder;
    string entradaPre;
    string entradaIn;

    getline(cin, entradaPre);
    getline(cin, entradaIn);

    if (!cin) return false;
    
    istringstream issPre(entradaPre);
    int numero;
    while (issPre >> numero) {
        // Leer números de la cadena uno por uno y almacenarlos en el vector
        preOrder.push_back(numero);
    }

    istringstream issIn(entradaIn);
    while (issIn >> numero) {
        // Leer números de la cadena uno por uno y almacenarlos en el vector
        inOrder.push_back(numero);
    }

    bintree<int> arbol = crearArbol(preOrder, inOrder);
    vector<int> postOrden = arbol.postorder();

    for(int i = 0; i< postOrden.size();i++)
    {
        cout << postOrden[i] << " ";
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


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}