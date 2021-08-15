#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class AreaJuego{

private:
	RenderWindow* vnt;


public:
	AreaJuego();
	void bucleJugar(RenderWindow*& ventana);
	void clickPantalla(int x, int y);
};