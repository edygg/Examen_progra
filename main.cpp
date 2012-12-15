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
    Ajedrez ajedrez;

    do
    { 


        do {
            cout << "\t1. Jugar" << endl
                 << "\t2. Crear archivo" << endl
                 << "\t3. Cargar archivo" << endl
                 << "\t4. Imprimir bitácora" << endl
                 << "\t5. Imprimir capturas" << endl
                 << "\t6. Salir" << endl
                 << "Ingrese una opcion: ";
            cin >> opcion;
        } while (opcion < 1 || opcion > 6);
        switch (opcion){
            case 1:
                {
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

                        if (jugadorActual == jugador1 && ajedrez.piezaColor(p1) == NEGRO)
                            break;

                        if (jugadorActual == jugador2 && ajedrez.piezaColor(p1) == BLANCA)
                            break;

                    } while (!ajedrez.moverPieza(p1, p2)); 

                    delete p1;
                    delete p2;

                    jugadorActual = (jugadorActual == jugador1 ? jugador2 : jugador1);
                }
            break;

            case 4:
                {
                    ajedrez.imprimirBitacora();
                }
            break;

            case 5:
                {
                    ajedrez.imprimirCapturas();
                }
            break;
        }
        

        

    } while (opcion != 6);

    return 0;
}
