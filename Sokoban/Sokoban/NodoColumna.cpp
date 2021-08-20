#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "NodoColumna.h"

NodoColumna::NodoColumna() {
	this->primero = NULL;
	this->ultimo = NULL;
}
NodoCentral* NodoColumna::getPrimero() {
	return primero;
}



void NodoColumna::recorrer() {
	if (primero != NULL) {
		NodoCentral* aux = primero;
		while (aux != NULL) {
			aux = aux->abajo;
		}
	}
}

void NodoColumna::insertar(NodoCentral* n) {
	if (primero == NULL) {
		primero = ultimo = n;
	}
	else {
		if (n->getY() < primero->getY()) {
			insertarInicio(n);
		}
		else {
			if (n->getY() > ultimo->getY()) {
				insertarFinal(n);
			}
			else {
				insertarMedio(n);
			}
		}
	}
}

void NodoColumna::insertarInicio(NodoCentral* n) {
	primero->arriba = n;
	n->abajo = primero;
	primero = primero->arriba;
}

void NodoColumna::insertarFinal(NodoCentral* n) {
	ultimo->abajo = n;
	n->arriba = ultimo;
	ultimo = ultimo->abajo;
}

void NodoColumna::insertarMedio(NodoCentral* n) {
	NodoCentral* aux1;
	NodoCentral* aux2;
	aux1 = primero;

	while (aux1->getY() < n->getY()) {
		aux1 = aux1->abajo;
	}
	aux2 = aux1->arriba;

	aux2->abajo = n;
	aux1->arriba = n;
	n->abajo = aux1;
	n->arriba = aux2;

}
