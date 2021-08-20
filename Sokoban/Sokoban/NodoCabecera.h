#pragma once
#include "NodoColumna.h"
#include <SFML\Graphics\RenderWindow.hpp>


using namespace sf;
//Esta clase será utilizada para almacenar los nodos que se encuentran en la cabeza de las columnas
class NodoCabecera {
private:
	int x;
public:
	NodoCabecera* siguiente;
	NodoCabecera* anterior;
	NodoColumna* columna;

	NodoCabecera(int x);
	void setX(int x);
	int getX();
};



