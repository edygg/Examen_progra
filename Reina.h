#ifndef REINA_H
#define REINA_H
#include "Enumeracion.h"
#include "Pieza.h"
#include "alfil.h"
#include "Torre.h"
#include "Posicion.h"


class Reina: public Pieza{
	public:
		Reina(ENUM_COLOR);
		virtual bool esMovimientoValido(Posicion* , Posicion*);
		virtual void imprimir();
		virtual ~Reina();
};
#endif
