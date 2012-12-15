#ifndef AJEDREZ_H
#define AJEDREZ_H
#include "Pieza.h"

class Ajedrez {
	Pieza* tablero[8][8];
public: 
	Ajedrez();
	ENUM_COLOR piezaColor(Posicion*);
	void imprimir();
	bool moverPieza(Posicion*, Posicion*);
	void inicializarTablero();
	bool estaVacia(Posicion* pos);
	bool hayPiezaEnMedio(Posicion*, Posicion*);
	~Ajedrez();	
};

#endif
