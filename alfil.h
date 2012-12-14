#ifndef ALFIL_H
#define ALFIL_H

#include "Enumeracion.h"
#include "Pieza.h"
#include "Posicion.h"

class Alfil: public Pieza{
	
	public:
		Alfil(ENUM_COLOR = NULO);
		virtual ~Alfil();	
		virtual bool esMovimientoValido(Posicion*,Posicion*);
		virtual void imprimir();
};

#endif
