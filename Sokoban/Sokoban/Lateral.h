#pragma once
#include "NodoLateral.h"
#include <SFML\Graphics\RenderWindow.hpp>


using namespace sf;
class Lateral
{
public:
	NodoLateral* primero;
	NodoLateral* ultimo;

	Lateral();

	void insertar(NodoLateral* n);
	void insertarInicio(NodoLateral* n);
	void insertarMedio(NodoLateral* n);
	void insertarFinal(NodoLateral* n);
	void recorrer();
	bool existe(int x);
	NodoLateral* busqueda(int x);
};

