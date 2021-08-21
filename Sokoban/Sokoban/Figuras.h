#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Figuras {

private:
	int jX = 0;
	int jY = 0;
	Texture jugador;
	Sprite sJugador;

	int jcX = 0;
	int jcY = 0;
	Texture caja;
	Sprite sCaja;

public:
	Figuras();
	void setJx(int jx);
	void setJy(int jy);
	void setTexturaJ(Texture jugador);
	void setSpriteJ(Sprite jugador);
	int getJx();
	int getJy();
	Texture getTexturaJugador();
	Sprite getSpriteJugador();
	Sprite getSpriteCaja();
	void crearJugador(float x, float y, int frame, int row);
	void crearCajas(float x, float y);
};

