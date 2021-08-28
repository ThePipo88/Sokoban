#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jugar.h"
#include "AcercaDe.h"
#include "AreaJuego.h"
#include "AppContext.h"

using namespace std;
using namespace sf;

class Ventana {

private:
	
	Jugar* jg;
	AcercaDe* acercaDe;
	AreaJuego* areaJuego;
	RenderWindow* ventana;


public:
	Ventana(int x, int y);
	void bucleJuego();
	void clickPantalla(int x, int y);
};
