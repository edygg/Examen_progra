/* 
 * File:   rey.cpp
 * Author: Home
 * 
 * Created on 07 de diciembre de 2012, 01:10 PM
 */

#include "rey.h"
#include <iostream>
#include "Pieza.h"
#include <cmath>

using namespace std;

rey::rey(ENUM_COLOR A) : Pieza(A) {
    Pieza::setTipo(REY);
}

bool rey::esMovimientoValido(Posicion* origen, Posicion* destino) {

    if ((fabs(destino->getX() - origen->getX()) == 1 && destino->getY() == origen->getY()) || (fabs(destino->getY() - origen->getY()) == 1 && destino->getX() == origen->getX()) || (fabs(destino->getY() - origen->getY()) == 1 && fabs(destino->getX() - origen->getX()) == 1)) {
        return true;
    } else {

        return false;
    }
}

rey::~rey() {
}

void rey::imprimir() {
    if (this->color == NEGRO) {
        cout << "r";
    }
    if (this->color == BLANCA) {
        cout << "R";
    }

}

