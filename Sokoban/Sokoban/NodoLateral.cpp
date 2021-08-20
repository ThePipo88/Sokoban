#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "NodoLateral.h"

NodoLateral::NodoLateral(int y) {
	this->y = y;
	filas = new NodoFila();
	siguiente = NULL;
	anterior = NULL;
}

void NodoLateral::setY(int y) {
	this->y = y;
}

int NodoLateral::getY() {
	return this->y;
}
