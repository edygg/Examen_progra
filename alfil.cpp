#include "alfil.h"
#include <cmath>
#include <iostream>

using namespace std;

Alfil::Alfil(ENUM_COLOR color) : Pieza(color){
	Pieza::setTipo(ALFIL);
}

Alfil::~Alfil(){}

bool Alfil::esMovimientoValido(Posicion* origen, Posicion * destino){
	
	if(fabs(origen->getX()-destino->getX())==fabs(origen->getY()-destino->getY()))
		return true;
	
	return false;
}

void Alfil::imprimir(){
	if(this->color==NEGRO)
		cout<<"a";
	if(this->color==BLANCA)
		cout<<"A";
}


