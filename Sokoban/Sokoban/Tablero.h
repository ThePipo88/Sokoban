#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "Lateral.h"
#include "Cabecera.h"


using namespace sf;
class Tablero {
private:
	Cabecera* c;
	Lateral* l;

public:
	Tablero();
	NodoCentral * buscarJugador();
	Cabecera* getCabecera();
	Lateral* getLateral();
	void insertar(int x, int y, char n);
	void llenar(int x, int y);
	void imprimir();
};
