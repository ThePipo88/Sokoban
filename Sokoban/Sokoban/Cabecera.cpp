#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cabecera.h"

Cabecera::Cabecera() {
	primero = NULL;
	ultimo = NULL;
}

void Cabecera::insertar(NodoCabecera* n) {

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

void Cabecera::insertarInicio(NodoCabecera* n) {
	primero->anterior = n;
	n->siguiente = primero;
	primero = primero->anterior;
}

void Cabecera::insertarFinal(NodoCabecera* n) {
	ultimo->siguiente = n;
	n->anterior = ultimo;
	ultimo = ultimo->siguiente;
}

void Cabecera::insertarMedio(NodoCabecera* n) {
	NodoCabecera* aux1;
	NodoCabecera* aux2;
	aux1 = primero;

	while (aux1->getX() < n->getX()) {
		aux1 = aux1->siguiente;
	}
	aux2 = aux1->anterior;

	aux2->siguiente = n;
	aux1->anterior = n;
	n->siguiente = aux1,
		n->anterior = aux2;

}

void Cabecera::recorrer() {

	if (primero != NULL) {
		NodoCabecera* aux = primero;
		while (aux != NULL) {
			cout << "Cabecera=" << aux->getX() << endl;
			aux = aux->siguiente;
		}
	}
}

bool Cabecera::existe(int x) {

	if (primero == NULL) {
		cout << "No existe en la lista" << endl;
		return false;
	}
	else {
		NodoCabecera* aux;
		aux = primero;

		while (aux != NULL) {
			if (aux->getX() == x) {
				return true;
			}
			else {
				if (aux->siguiente == NULL) {
					cout << "No se encontró cabecera (se insertará)" << endl;
					return false;
				}
				aux = aux->siguiente;
			}
		}

	}

}

NodoCabecera* Cabecera::busqueda(int x) {
	if (existe(x)) {

		NodoCabecera* aux;
		aux = primero;
		while (aux->getX() != x) {
			aux = aux->siguiente;
		}

		return aux;
	}
	else {
		cout << "No existe" << endl;
		return (new NodoCabecera(-1));
	}
}
