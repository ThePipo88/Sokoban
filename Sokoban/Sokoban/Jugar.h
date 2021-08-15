#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Jugar {

private:
	RenderWindow* vnt;


public:
	Jugar();
	void bucleJugar(RenderWindow*& ventana);
	void clickPantalla(int x, int y);
};