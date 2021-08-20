#pragma once
#include "NodoFila.h"
#include <SFML\Graphics\RenderWindow.hpp>


using namespace sf;

class NodoLateral {
private:
	int y;
public:
	NodoLateral* siguiente;
	NodoLateral* anterior;
	NodoFila* filas;

	NodoLateral(int y);
	void setY(int y);
	int getY();
};

