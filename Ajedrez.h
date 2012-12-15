#ifndef AJEDREZ_H
#define AJEDREZ_H
#include "Pieza.h"
#include "Movimiento.h"
#include <vector>
using namespace std;

class Ajedrez {
	Pieza* tablero[8][8];
	vector<Pieza*> capturas;
	vector<Movimiento*> movimientos;
public: 
	Ajedrez();
	void imprimirCapturas();
	void imprimirBitacora();
	ENUM_COLOR piezaColor(Posicion*);
	void imprimir();
	bool moverPieza(Posicion*, Posicion*);
	void inicializarTablero();
	bool estaVacia(Posicion* pos);
	bool hayPiezaEnMedio(Posicion*, Posicion*);
	~Ajedrez();	
};

#endif
