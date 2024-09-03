#include <iostream>
#include <string>
#include "Pila/Pila.h"
using namespace std;

void registrarDesplazamiento(Pila<string>& pilaMovimientos,const string& movimiento,const string& lugar)
{
    if(movimiento == "in")
    {
        pilaMovimientos.push(lugar);
    }
    else if (movimiento == "out" && !pilaMovimientos.esVacia())
    {
        pilaMovimientos.pop();
    }
}

void mostrarRecorridoInverso(Pila<string>& pilaMovimientos)
{
    while (!pilaMovimientos.esVacia())
    {
        cout << pilaMovimientos.pop() <<endl;
    }
    
}

int main() {
    Pila<string> pilaMovimientos;

    registrarDesplazamiento(pilaMovimientos, "in", "Recepcion");
    registrarDesplazamiento(pilaMovimientos, "in", "Oficina");
    registrarDesplazamiento(pilaMovimientos, "in", "Sala de Reuniones");
    registrarDesplazamiento(pilaMovimientos, "out", "Sala de Reuniones");
    registrarDesplazamiento(pilaMovimientos, "in", "GYM");

    mostrarRecorridoInverso(pilaMovimientos);
}