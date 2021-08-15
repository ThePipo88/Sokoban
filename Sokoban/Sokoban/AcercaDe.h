#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class AcercaDe{

private:
	RenderWindow* vnt;


public:
	AcercaDe();
	void bucleJugar(RenderWindow*& ventana);
	void clickPantalla(int x, int y);
}; 
