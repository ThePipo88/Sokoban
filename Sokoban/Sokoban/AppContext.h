#pragma once
#include <SFML\Graphics\RenderWindow.hpp>


using namespace sf;
class AppContext{
private:
	AppContext();
	//Atributos
	int pantalla;
	int nivel = 1;
	int posX;
	int posY;
	RenderWindow* ventana;
	Event* ev;
	//Partida* partida;
public:
	static AppContext& getInstance();
	int getPantalla();
	void setPantalla(int p);
	int getNivel();
	void setNivel(int n);
	int getX();
	int getY();
	RenderWindow* getWindow();
	void setWindow(RenderWindow* v);
	Event* getEvent();
	void setEvent(Event* e);
};
