#include "Posicion.h"
#include "Ajedrez.h"

#include <iostream>
#include <string>
using namespace std;

bool validarEntrada(int);

int main(int argc, char *argv[])
{
    int opcion;
    string jugador1 = "1", jugador2 = "2";
    string jugadorActual = jugador1;

    do
    {
        Ajedrez ajedrez;
        ajedrez.imprimir();

        Posicion* p1;
        Posicion* p2;

        do
        {
            int x1, x2, y1, y2;

            cout << "Juagador " << jugadorActual << ": " << endl;

            cout << "Ingrese x(Origen):";
            cin >> x1;

            cout << "Ingrese y(Origen):";
            cin >> y1;

            cout << "Ingrese x(Destino):";
            cin >> x2;

            cout << "Ingrese y(Destino):";
            cin >> y2;

            p1 = new Posicion(x1, y1); 
            p2 = new Posicion(x2, y2);

        } while (!ajedrez.moverPieza(p1, p2));

        delete p1;
        delete p2;

        jugadorActual = (jugadorActual == jugador1 ? jugador2 : jugador1);

        cout << "\n\nDesea salir: " << endl;
        cin >> opcion;

    } while (opcion != 1);

    return 0;
}
