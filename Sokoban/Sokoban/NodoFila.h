#pragma once
#include "NodoCentral.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include <iostream>

using namespace sf;
class NodoFila {
private:
	NodoCentral* primero;
	NodoCentral* ultimo;
public:
	NodoFila();
	void setPrimero(NodoCentral* nodoCentral);
	void setUltimo(NodoCentral* nodoCentral);
	NodoCentral* getPrimero();
	NodoCentral* getUltimo();

	void recorrer();
	NodoCentral *buscarJugador();
	void insertar(NodoCentral* n);
	void insertarInicio(NodoCentral* n);
	void insertarFinal(NodoCentral* n);
	void insertarMedio(NodoCentral* n);
};


