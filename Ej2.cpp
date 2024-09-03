#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void remplazar(Pila<int>& pila,int viejo,int nuevo)
{
    Pila<int> temp;
    while (!pila.esVacia())
    {
        int aux = pila.pop();
        if (aux == viejo)
        {
            pila.push(nuevo);
        }
        else{
            temp.push(aux);
        }
    }
    while (!temp.esVacia())
    {
        pila.push(temp.pop());
    }
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main() {
    Pila<int> pila;
    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);
    
    remplazar(pila,3,1);

    mostrarPila(pila);
    return 0;
}
