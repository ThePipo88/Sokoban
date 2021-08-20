#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "NodoFila.h"

NodoFila::NodoFila() {
	this->primero = NULL;
	this->ultimo = NULL;
}
void NodoFila::setPrimero(NodoCentral* nodoCentral) {
	this->primero = nodoCentral;
}
void NodoFila::setUltimo(NodoCentral* nodoCentral) {
	this->ultimo=nodoCentral;
}

NodoCentral* NodoFila::getPrimero() {
	return primero;
}
NodoCentral* NodoFila::getUltimo() {
	return ultimo;
}


void NodoFila::recorrer() {
	if (primero != NULL) {
		NodoCentral* aux = primero;
		while (aux != NULL) {
			cout << "[" << aux->getDato() << "]";
			aux = aux->derecha;
		}
	}
cout << endl;
}

NodoCentral* NodoFila::buscarJugador() {

	bool bandera = false;
	if (primero != NULL) {
		NodoCentral* aux = primero;
		while (aux != NULL) {
			if (aux->getDato() == '@') {

				bandera = true;
				break;
			}
			else {
				aux = aux->derecha;
			}
			
		}
		if (bandera) {
			return aux;
		}
		else {
			return NULL;
		}

	}
	//cout << endl;
}

void NodoFila::insertar(NodoCentral* n) {
	if (primero == NULL) {
		primero = ultimo = n;
	}
	else {
		if (n->getX() < primero->getX()) {
			insertarInicio(n);
		}
		else {
			if (n->getX() > ultimo->getX()) {
				insertarFinal(n);
			}
			else {
				insertarMedio(n);
			}
		}
	}
}

void NodoFila::insertarInicio(NodoCentral* n) {
	primero->izquierda = n;
	n->derecha = primero;
	primero = primero->izquierda;
}

void NodoFila::insertarFinal(NodoCentral* n) {
	ultimo->derecha = n;
	n->izquierda = ultimo;
	ultimo = ultimo->derecha;
}

void NodoFila::insertarMedio(NodoCentral* n) {
	NodoCentral* aux1;
	NodoCentral* aux2;
	aux1 = primero;

	while (aux1->getX() < n->getX()) {
		aux1 = aux1->derecha;
	}
	aux2 = aux1->izquierda;

	aux2->derecha = n;
	aux1->izquierda = n;
	n->derecha = aux1;
	n->izquierda = aux2;

}
