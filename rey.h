/* 
 * File:   rey.h
 * Author: Home
 *
 * Created on 07 de diciembre de 2012, 01:10 PM
 */

#ifndef REY_H
#define	REY_H
#include "Enumeracion.h"
#include "Pieza.h"
#include "Posicion.h"

class rey: public Pieza{
public:
     rey(ENUM_COLOR);
     bool esMovimientoValido(Posicion*,Posicion*);
     virtual void imprimir();
     virtual ~rey();
private:

};

#endif	/* REY_H */

