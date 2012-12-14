#include "Reina.h"
#include <iostream>
using namespace std;

Reina::Reina(ENUM_COLOR color): Pieza(color){
	Pieza:setTipo(REINA);	
}

bool Reina::esMovimientoValido(Posicion* origen, Posicion* destino ){
	Posicion x = Posicion(origen->getX(),origen->getY()); 	
 	Posicion y = Posicion(origen->getX(),origen->getY());
	Alfil temp;
	Torre temp2;		
	if(temp.esMovimientoValido(&x, &y) && temp2.esMovimientoValido(&x,&y))
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
