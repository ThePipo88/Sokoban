#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tablero.h"

using namespace std;
using namespace sf;

class AreaJuego{

private:

	float posX = 634;
	float posY = 305;
	int frame = 0;
	int row = 50;
	int frame_counter = 1;
	Tablero* tablero;


public:
	AreaJuego();
	void bucleJugar(RenderWindow*& ventana);
	void clickPantalla(int x, int y);
	void eventoTeclas(Event event);
	bool movimientoValido(char x);
};