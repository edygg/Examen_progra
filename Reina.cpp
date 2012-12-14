#include "Reina.h"
#include <iostream>
using namespace std;

Reina::Reina(ENUM_COLOR color): Pieza(color){
	Pieza:setTipo(REINA);	
}

bool Reina::esMovimientoValido(Posicion* origen, Posicion* destino ){
	Alfil temp;
	Torre temp2;		
	if(temp.esMovimientoValido(origen, destino) || temp2.esMovimientoValido(origen, destino))
		return true;
		
	return false;

}

void Reina::imprimir(){
	if(this->color==NEGRO)
		cout << "q";
	if(this->color==BLANCA)
		cout << "Q";
}
		
Reina::~Reina(){}
