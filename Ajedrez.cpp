#include "Ajedrez.h"
#include "Torre.h"
#include "Caballo.h"
#include "rey.h"
#include "alfil.h"
#include "Reina.h"
#include "Peon.h"
#include "Enumeracion.h"
#include <iostream>
#include <iomanip>
using namespace std;

Ajedrez::Ajedrez() {
	inicializarTablero();
}

void Ajedrez::inicializarTablero() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tablero[i][j] = new Pieza();	
		}	
	}

	delete tablero[0][0];  	
	delete tablero[0][1]; 
	delete tablero[0][2]; 
	delete tablero[0][3]; 
	delete tablero[0][4]; 
	delete tablero[0][5]; 
	delete tablero[0][6]; 
	delete tablero[0][7];

	delete tablero[7][0]; 	
	delete tablero[7][1]; 
	delete tablero[7][2]; 
	delete tablero[7][4]; 
	delete tablero[7][3]; 
	delete tablero[7][5]; 
	delete tablero[7][6]; 
	delete tablero[7][7];  
	
	tablero[0][0] = new Torre(BLANCA);	
	tablero[0][1] = new Caballo(BLANCA);
	tablero[0][2] = new Alfil(BLANCA);
	tablero[0][3] = new Reina(BLANCA);
	tablero[0][4] = new rey(BLANCA);
	tablero[0][5] = new Alfil(BLANCA);
	tablero[0][6] = new Caballo(BLANCA);
	tablero[0][7] = new Torre(BLANCA);

	tablero[7][0] = new Torre(NEGRO);	
	tablero[7][1] = new Caballo(NEGRO);
	tablero[7][2] = new Alfil(NEGRO);
	tablero[7][4] = new Reina(NEGRO);
	tablero[7][3] = new rey(NEGRO);
	tablero[7][5] = new Alfil(NEGRO);
	tablero[7][6] = new Caballo(NEGRO);
	tablero[7][7] = new Torre(NEGRO);

	for (int i = 0; i < 8; i++) {
		tablero[1][i] = new Peon(BLANCA);
		tablero[6][i] = new Peon(NEGRO);
	}

}



Ajedrez::~Ajedrez() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete tablero[i][j];	
		}	
	}	
}

void Ajedrez::imprimir() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Pieza* tmp = tablero[i][j];
			cout << setw(2);
			tmp->imprimir();
			cout << setw(2) <<" "; 
		}

		cout << endl;
	}
}

bool Ajedrez::estaVacia(Posicion* pos) {
	if (tablero[pos->getY()][pos->getX()]->getTipo() == VACIA) {
		return true;
	} 

	cout << "esta vacia:" << false;
	return false;
}

bool Ajedrez::hayPiezaEnMedio(Posicion* ini, Posicion* fin) {
	ENUM_PIEZA piezaA = tablero[ini->getY()][ini->getX()]->getTipo();

	switch (piezaA) {
		case TORRE:
			{
				if (ini->getX() == fin->getX()) {
					if (ini->getY() < fin->getY()) {
						for (int i = ini->getY(); i < fin->getY(); i++) {
							if (tablero[i][ini->getX()]->getTipo() != VACIA){
								cout << "Esta vacia: " << true;
								return true;
							}
						}
					} else {
						for (int i = ini->getY(); i > fin->getY(); i--) {
							if (tablero[i][ini->getX()]->getTipo() != VACIA){
								cout << "esta vacia: " << true;
								return true;
							}
						}
					}

					
				} else {
					if (ini->getY() == fin->getY()) {
						if (ini->getX() < fin->getX()) {
							for (int i = ini->getX(); i < fin->getX(); i++) {
								if (tablero[ini->getY()][i]->getTipo() != VACIA) {
									cout << "Esta vacia: " << true;
									return true;
								}
							}
						} else {
							for (int i = ini->getY(); i > fin->getY(); i--) {
								if (tablero[ini->getY()][i]->getTipo() != VACIA) {
									cout << "esta vacia: " << true;
									return true;
								}
							}
						}
					}
				}
			}

			cout << "Esta vacia: " << false;
			return(false);
		break;

		case ALFIL:
			{
				if (ini->getX() < fin->getX()) {
					if (ini->getY() > fin->getY()) {
						for (int i = ini->getX(), j = ini->getY(); i < fin->getX(); i++, j--) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					} else {
						for (int i = ini->getX(), j = ini->getY(); i < fin->getX(); i++, j++) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					}
				} else {
					if (ini->getY() > fin->getY()) {
						for (int i = ini->getX(), j = ini->getY(); i > fin->getX(); i--, j--) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					} else {
						for (int i = ini->getX(), j = ini->getY(); i > fin->getX(); i--, j++) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					}
				}
			}
		break; 
		
		case REINA:
			{
				if (ini->getX() == fin->getX()) {
					if (ini->getY() < fin->getY()) {
						for (int i = ini->getY(); i < fin->getY(); i++) {
							if (tablero[i][ini->getX()]->getTipo() != VACIA){
								return true;
							}
						}
					} else {
						for (int i = ini->getY(); i > fin->getY(); i--) {
							if (tablero[i][ini->getX()]->getTipo() != VACIA){
								return true;
							}
						}
					}

					
				} else {
					if (ini->getY() == fin->getY()) {
						if (ini->getX() < fin->getX()) {
							for (int i = ini->getX(); i < fin->getX(); i++) {
								if (tablero[ini->getY()][i]->getTipo() != VACIA) {
									return true;
								}
							}
						} else {
							for (int i = ini->getY(); i > fin->getY(); i--) {
								if (tablero[ini->getY()][i]->getTipo() != VACIA) {
									return true;
								}
							}
						}
					}
				}

				if (ini->getX() < fin->getX()) {
					if (ini->getY() > fin->getY()) {
						for (int i = ini->getX(), j = ini->getY(); i < fin->getX(); i++, j--) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					} else {
						for (int i = ini->getX(), j = ini->getY(); i < fin->getX(); i++, j++) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					}
				} else {
					if (ini->getY() > fin->getY()) {
						for (int i = ini->getX(), j = ini->getY(); i > fin->getX(); i--, j--) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					} else {
						for (int i = ini->getX(), j = ini->getY(); i > fin->getX(); i--, j++) {
							if (tablero[j][i]->getTipo() != VACIA) {
								return true;
							}
						}
					}
				}

			}
		break;

		case PEON:
	{
		if(tablero[ini->getX()][ini->getY()] -> getColor() == BLANCA){
			if(ini->getX() == fin->getX()) {
					for (int i = ini->getY() + 1; i <= fin->getY(); i++) {
						if (tablero[i][ini->getX()]->getTipo() != VACIA)
							return true;
					}
				} else {
					if (ini->getX() != fin->getX()) {
						if(tablero[fin->getY()][fin->getX()]->getTipo() == VACIA || tablero[ini->getY()][ini->getX()]->getColor() == tablero[fin->getY()][fin->getX()]->getColor())
							return true;
					}
				}
			}
			else{
				if(tablero[ini->getX()][ini->getY()] -> getColor() == NEGRO){
					if(ini->getX() == fin->getX()) {
						for (int i = ini->getY() - 1; i >= fin->getY(); i--) {
							if (tablero[i][ini->getX()]->getTipo() != VACIA)
								return true;
						}
					} else {
						if (ini->getX() != fin->getX()) {
							if(tablero[fin->getY()][fin->getX()]->getTipo() == VACIA || tablero[ini->getY()][ini->getX()]->getColor() == tablero[fin->getY()][fin->getX()]->getColor())
								return true;
						}
					}
				}
			}
		}
		break;
	}

	return false;
}

bool Ajedrez::moverPieza(Posicion* ini, Posicion* fin) {
	if (estaVacia(ini) && tablero[ini->getY()][ini->getX()]->getColor() == tablero[fin->getY()][fin->getX()]->getColor()) {
		cout << "Paso 1" << endl;
		return false;
	} else {
		if (!tablero[ini->getY()][ini->getX()]->esMovimientoValido(ini, fin) || hayPiezaEnMedio(ini, fin)) {
			cout << "Paso 2" << endl;
			return false;
		} else {
			if (tablero[fin->getY()][fin->getX()]->getTipo() == VACIA) {
				cout << "Paso 4" << endl;
				Pieza* tmp; 
				tmp = tablero[fin->getY()][fin->getX()];
				tablero[fin->getY()][fin->getX()] = tablero[ini->getY()][ini->getX()];
				tablero[ini->getY()][ini->getX()] = tmp;
			} else {
				cout << "Paso 5" << endl;
				delete tablero[fin->getY()][fin->getX()];

				tablero[fin->getY()][fin->getX()] = tablero[ini->getY()][ini->getX()];
				tablero[ini->getY()][ini->getX()] = new Pieza();
			}
		} 
	}

	return true;
}

ENUM_COLOR Ajedrez::piezaColor(Posicion* pos) {
	return tablero[pos->getY()][pos->getX()]->getColor();
}