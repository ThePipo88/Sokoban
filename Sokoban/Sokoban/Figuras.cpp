#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Figuras.h"

using namespace std;
using namespace sf;

Figuras::Figuras() {

}

void Figuras::setJx(int jux) {
	jX = jux;
}

int Figuras::getJx() {
	return jX;
}

void Figuras::setJy(int juy) {
	jY = juy;
}

int Figuras::getJy() {
	return jY;
}

void Figuras::setTexturaJ(Texture tx) {
	jugador = tx;
}

Texture Figuras::getTexturaJugador() {
	return jugador;
}

void Figuras::setSpriteJ(Sprite sp) {
	sJugador = sp;
}

Sprite Figuras::getSpriteJugador() {
	return sJugador;
}

Sprite Figuras::getSpriteCaja() {
	return sCaja;
}

void Figuras::crearJugador(float x, float y, int frame, int row) {
	jugador.loadFromFile("Resources/sprite.png");
	sJugador.setTexture(jugador);
	sJugador.setPosition(x, y);
	sJugador.setTextureRect(IntRect(32 * frame, row, 32, 50));

}

void Figuras::crearCajas(float x, float y) {
	caja.loadFromFile("Resources/caja.png");
	sCaja.setTexture(caja);
	sCaja.setPosition(x,y);
}