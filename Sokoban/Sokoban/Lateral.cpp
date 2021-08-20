#include <SFML/Graphics.hpp>
#include <iostream>
#include "Lateral.h"

Lateral::Lateral() {
	primero = NULL;
	ultimo = NULL;
}

void Lateral::insertar(NodoLateral* n) {

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

void Lateral::insertarInicio(NodoLateral* n) {
	primero->anterior = n;
	n->siguiente = primero;
	primero = primero->anterior;
}

void Lateral::insertarFinal(NodoLateral* n) {
	ultimo->siguiente = n;
	n->anterior = ultimo;
	ultimo = ultimo->siguiente;
}

void Lateral::insertarMedio(NodoLateral* n) {
	NodoLateral* aux1;
	NodoLateral* aux2;
	aux1 = primero;

	while (aux1->getY() < n->getY()) {
		aux1 = aux1->siguiente;
	}
	aux2 = aux1->anterior;

	aux2->siguiente = n;
	aux1->anterior = n;
	n->siguiente = aux1,
	n->anterior = aux2;

}

void Lateral::recorrer() {

	if (primero != NULL) {
		NodoLateral* aux = primero;
		while (aux != NULL) {
			cout << "Filas=" << aux->getY() << endl;
			aux = aux->siguiente;
		}
	}
}

bool Lateral::existe(int y) {


	if (primero == NULL) {
		cout << "No existe en la lista" << endl;
		return false;
	}
	else {
		NodoLateral* aux;
		aux = primero;

		while (aux != NULL) {
			if (aux->getY() == y) {
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

NodoLateral* Lateral::busqueda(int y) {
	if (existe(y)) {

		NodoLateral* aux;
		aux = primero;
		while (aux->getY() != y) {
			aux = aux->siguiente;
		}

		return aux;
	}
	else {
		cout << "No existe" << endl;
		return (new NodoLateral(-1));
	}
}