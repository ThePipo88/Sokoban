#pragma once

#include<iostream>
#include <SFML\Graphics\RenderWindow.hpp>

using namespace std;
using namespace sf;

//será el nodo principal usado para almacenar los campos de la matriz

class NodoCentral {
private:
	char dato;
	int x;
	int y;

public:
	NodoCentral* arriba;
	NodoCentral* abajo;
	NodoCentral* izquierda;
	NodoCentral* derecha;

	NodoCentral();
	NodoCentral(char dato, int x, int y);
	void setDato(char c);
	void setX(int x);
	void setY(int y);
	char getDato();
	int getX();
	int getY();

};

