#include "Peon.h"
#include "Posicion.h"
#include <cmath>
#include <iostream>
using namespace std;

Peon::Peon (ENUM_COLOR c) : Pieza(c) {
	Pieza::setTipo(PEON);
}

Peon::~Peon () {
}

bool Peon::esMovimientoValido(Posicion* origen, Posicion* destino) {

	if (color == NEGRO && (origen->getY() == 6 && (fabs(origen->getY() - destino->getY()) == 1 ||  fabs(origen->getY() - destino->getY()) == 2)))
		return true;

	if (color == BLANCA && (origen->getY() == 1 && (fabs(origen->getY() - destino->getY()) == 1 ||  fabs(origen->getY() - destino->getY()) == 2)))
		return true;

	if (color == NEGRO && (origen->getY() != 6 && (origen->getY() - destino->getY() == 1)))
		return true;

	if (color == BLANCA && (origen->getY() != 1 && (origen->getY() - destino->getY() == -1)))
		return true;

	return false;

}

void Peon::imprimir() {
	if (this->color == BLANCA) {
		cout << "P";	
	} else {
		cout << "p";
	}	
}
