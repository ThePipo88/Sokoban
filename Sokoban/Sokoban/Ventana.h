#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Ventana {

private:
	int largo;
	int ancho;
	RenderWindow* ventana;

public:
	Ventana(int ancho, int largo);
	void bucleJuego();
	void clickPantalla(int x, int y, int pantalla);
};