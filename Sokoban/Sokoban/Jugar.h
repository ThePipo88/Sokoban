#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Jugar {

private:
	RenderWindow* ventana;


public:
	Jugar();
	void bucleJuego();
	void clickPantalla(int x, int y, int pantalla);
};