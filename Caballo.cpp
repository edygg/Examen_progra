#include "Caballo.h"
#include "Enumeracion.h"
#include "Posicion.h"

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

Caballo::Caballo(ENUM_COLOR color)
    : Pieza(color)
{
    Pieza::setTipo(CABALLO);
}

Caballo::~Caballo()
{

}

bool Caballo::esMovimientoValido(Posicion *origen, Posicion *destino)
{
    if ( ( (fabs(origen->getY() - destino->getY()) == 2) || (fabs(origen->getY() - destino->getY()) == 1) ) &&
         ( (fabs(origen->getX() - destino->getX()) == 2) || (fabs(origen->getX() - destino->getX()) == 1) ) )
    {
        return true;
    }

    return false;
}

void Caballo::imprimir()
{
    cout << (color == BLANCA ? "C" : "c");
}
