#ifndef CABALLO_H
#define CABALLO_H

#include "Posicion.h"
#include "Pieza.h"
#include "Enumeracion.h"

class Caballo : public Pieza
{
public:
    Caballo(ENUM_COLOR);
    ~Caballo();
    virtual bool esMovimientoValido(Posicion*, Posicion*);
    virtual void imprimir();

};

#endif // CABALLO_H
