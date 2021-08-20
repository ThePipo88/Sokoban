#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "NodoCabecera.h"

NodoCabecera::NodoCabecera(int x) {
	this->x = x;
	columna = new NodoColumna();
	siguiente = NULL;
	anterior = NULL;
}

void NodoCabecera::setX(int x) {
	this->x = x;
}

int NodoCabecera::getX() {
	return this->x;
}

