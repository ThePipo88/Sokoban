#pragma once
#include "NodoCentral.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

//Esta lista se compone de nodos centrales que se usarán para representar las columnas del tablero
class NodoColumna {

private:
	NodoCentral* primero;
	NodoCentral* ultimo;

public:
	NodoColumna();
	void setPrimero(NodoCentral* nodoCentral);
	void setUltimo(NodoCentral* nodoCentral);
	NodoCentral* getPrimero();
	void getUltimo(NodoCentral* nodoCentral);

	void recorrer();
	void insertar(NodoCentral* n);
	void insertarInicio(NodoCentral* n);
	void insertarFinal(NodoCentral* n);
	void insertarMedio(NodoCentral* n);

};

