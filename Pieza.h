#ifndef PIEZA_H
#define PIEZA_H
#include "Posicion.h"
#include "Enumeracion.h"
#include <iostream>
using namespace std;

class Pieza {
protected:
	ENUM_COLOR color;
	ENUM_PIEZA tipo;
public:
	Pieza (ENUM_COLOR = NULO);	
	virtual bool esMovimientoValido(Posicion*, Posicion*);
	virtual void imprimir();
	~Pieza();
	void setTipo(ENUM_PIEZA);
	ENUM_PIEZA getTipo();
	ENUM_COLOR getColor();
};

#endif
