#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tablero.h"

Tablero::Tablero() {
	this->c = new Cabecera();
	this->l = new Lateral();
}

Cabecera* Tablero::getCabecera() {
	return c;
}
Lateral* Tablero::getLateral() {
	return l;
}



void Tablero::insertar(int x, int y, char dato) {

	NodoCentral* nodocentral;
	nodocentral = new NodoCentral(dato, x, y);

	if (!c->existe(x)) {
		c->insertar(new NodoCabecera(x));
	} if (!l->existe(y)) {
		l->insertar(new NodoLateral(y));
	}

	NodoCabecera* auxCabecera;
	NodoLateral* auxLateral;

	auxCabecera = c->busqueda(x);
	auxLateral = l->busqueda(y);

	auxCabecera->columna->insertar(nodocentral);
	auxLateral->filas->insertar(nodocentral);

	cout << "Se insertó el dato: " << dato << " en la columna " << x << " y fila " << y << endl;
}

void Tablero::llenar(int x, int y) {

	for (int i = 0; i < x;i++) {
		for (int j = 0; j < y; j++) {

			if (i == 0 || j == 0 || i == x-1 || y-1 == j || /* validaciones para el mapa -> */ i==1 && j==1 || i==1 && j==2 ||
				i==3 && j==4 || i == 3 && j == 5 || i == 4 && j == 5 || i == 5 && j == 5) {
				insertar(i, j, '#');
			}
			else {
				if (i == 3 && j == 1) {
					insertar(i, j, '@');
				}
				else if (i == 2 && j == 2 || i == 2 && j == 4) {
					insertar(i, j, '$');
				}
				else if (i == 4 && j == 2 || i == 4 && j == 4) {
					insertar(i, j, '.');
				}
				else {
					insertar(i, j, ' ');
				}
			}


		}

	}

	//insertar(3, 1, '$');
}


NodoCentral *Tablero::buscarJugador() {

	NodoCabecera* auxNodoCabecera;
	NodoLateral* auxNodoLateral;
	NodoCentral* auxNodoCentral = new NodoCentral();

	auxNodoCabecera = c->primero;
	if (auxNodoCabecera != NULL) {

		auxNodoLateral = l->primero;
		while (auxNodoLateral != NULL) {

			auxNodoCentral = auxNodoLateral->filas->buscarJugador();

			if (auxNodoCentral !=NULL && auxNodoCentral->getDato() == '@') {
				return auxNodoCentral;
			}
			else {
				//auxNodoCentral = NULL;
				auxNodoLateral = auxNodoLateral->siguiente;
			}


			
		}
		//cout << endl;
		auxNodoCabecera = auxNodoCabecera->siguiente;
	}
	return auxNodoCentral;

}

void Tablero::imprimir() {
	NodoCabecera* auxNodoCabecera;
	NodoLateral* auxNodoLateral;
	//NodoCentral* auxNodoCentral;

	auxNodoCabecera = c->primero;
	if ( auxNodoCabecera != NULL ) {

		auxNodoLateral = l->primero;
		while (auxNodoLateral != NULL) {
			
			auxNodoLateral->filas->recorrer();

			auxNodoLateral = auxNodoLateral->siguiente;
		}
		cout << endl;
		auxNodoCabecera = auxNodoCabecera->siguiente;
	}

}
