#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "NodoCentral.h"

NodoCentral::NodoCentral() {
	this->x = NULL;
	this->y = NULL;
	this->abajo = NULL;
	this->arriba = NULL;
	this->dato = NULL;
	this->derecha = NULL;
	this->izquierda = NULL;
}

NodoCentral::NodoCentral(char c, int x, int y) {

	this->dato = c;
	this->x = x;
	this->y = y;

	arriba = NULL;
	abajo = NULL;
	izquierda = NULL;
	derecha = NULL;
}

void NodoCentral::setDato(char c) {
	dato = c;
}
void NodoCentral::setX(int X) {
	x = X;
}
void NodoCentral::setY(int Y) {
	y = Y;
}
char NodoCentral::getDato() {
	//cout << dato;
	return dato;
}
int NodoCentral::getX() {
	return x;
}
int NodoCentral::getY() {
	return y;
}
