#ifndef TORRE_H
#define TORRE_H

#include "Enumeracion.h"
#include "Posicion.h"
#include "Pieza.h"

class Torre:public Pieza{
  Posicion* pos;
public:
  Torre(ENUM_COLOR = NULO);
  ~Torre();
  bool esMovimientoValido(Posicion*, Posicion*);
  void imprimir();
};

#endif
