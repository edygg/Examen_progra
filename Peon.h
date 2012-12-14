#ifndef PEON_H
#define PEON_H
#include "Pieza.h"
#include "Enumeracion.h"
#include "Posicion.h"
#include <cmath>
using namespace std;

class Peon : public Pieza {
public:
	Peon (ENUM_COLOR);
	~Peon ();
	bool esMovimientoValido (Posicion* origen, Posicion* destino);
	void imprimir();
};

#endif
