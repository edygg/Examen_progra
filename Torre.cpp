#include "Torre.h"
# include <iostream>
#include "Enumeracion.h"

using namespace std;

Torre::Torre(ENUM_COLOR color):Pieza(color){
  Pieza::setTipo(TORRE);
}

Torre::~Torre(){
}

bool Torre::esMovimientoValido(Posicion* origen, Posicion * destino){
  if((origen -> getX() == destino -> getX()) && (origen -> getY() != destino -> getY())){
    return(true);
  }
  else{
    if((origen -> getY() == destino -> getY()) && (origen -> getX() != destino -> getX())){
      return(true);
    }
    else{
      return(false);
    }
  }
}

void Torre::imprimir(){
  if(this -> color == BLANCA)
    cout << "T";
  
  if(this -> color == NEGRO)
    cout << "t";
  
}
