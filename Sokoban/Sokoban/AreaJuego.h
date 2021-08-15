#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class AreaJuego{

private:
	RenderWindow* vnt;
	float posX = 200;
	float posY = 200;
	int frame = 0;
	int row = 50;
	int frame_counter = 1;


public:
	AreaJuego();
	void bucleJugar(RenderWindow*& ventana);
	void clickPantalla(int x, int y);
	void eventoTeclas(Event event);
};