#include "Pieza.h"

Pieza::Pieza(ENUM_COLOR c) {
	this->color = c;
	tipo = VACIA;
}

void Pieza::setTipo(ENUM_PIEZA t) {
	this->tipo = t;
}

Pieza::~Pieza() {

}

bool Pieza::esMovimientoValido(Posicion* origen, Posicion* destino) {}

void Pieza::imprimir() {
	cout << "*";
}

ENUM_PIEZA Pieza::getTipo() {
	return tipo;
}

ENUM_COLOR Pieza::getColor() {
	return color;
}

const Pieza& Pieza::operator=(const Pieza& val) {
	this->tipo = val.tipo;
	this->color = val.color;
}