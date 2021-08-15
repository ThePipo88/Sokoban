#include "AppContext.h"

AppContext::AppContext() {
	pantalla = 1;
	ventana = nullptr;
	nivel = 1;

}

AppContext& AppContext::getInstance() {
	static AppContext INSTANCE;
	return INSTANCE;
}

int AppContext::getPantalla() {
	return this->pantalla;
}

void AppContext::setPantalla(int p) {
	this->pantalla = p;
}

int AppContext::getNivel() {
	return this->nivel;
}

void AppContext::setNivel(int n) {
	this->nivel = n;
}
int AppContext::getX() {
	if (nivel == 1) return 0;
	else if (nivel == 2) return 0;
	else if (nivel == 3) return 0;
	else if (nivel == 4) return 0;
	else return 0;
}

int AppContext::getY() {
	if (nivel == 1) return 0;
	else if (nivel == 2) return 0;
	else if (nivel == 3) return 0;
	else if (nivel == 4) return 0;
	else return 0;
}

RenderWindow* AppContext::getWindow() {
	return ventana;
}

void AppContext::setWindow(RenderWindow* v) {
	this->ventana = v;
}