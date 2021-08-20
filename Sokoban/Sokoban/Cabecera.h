#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "NodoCabecera.h"

using namespace sf;
class Cabecera
{
public:
	NodoCabecera* primero;
	NodoCabecera* ultimo;

	Cabecera();

	void insertar(NodoCabecera* n);
	void insertarInicio(NodoCabecera* n);
	void insertarMedio(NodoCabecera* n);
	void insertarFinal(NodoCabecera* n);
	void recorrer();
	bool existe(int x);
	NodoCabecera* busqueda(int x);
};

