#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Jugar {

private:
	RenderWindow* vnt;
	Event* evento1;
	//Tablero* tab;

public:
	Jugar();
	void bucleJugar(RenderWindow*& ventana);
	void clickPantalla(int x, int y);
	//void procesarEventos(RenderWindow*& ventana);

	
};