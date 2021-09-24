#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include "Tablero.h"
#include "Figuras.h"

using namespace std;
using namespace sf;

class AreaJuego{

private:

	float posX = 634;

	float posY = 305;
	int frame = 0;
	int row = 50;
	int frame_counter = 1;
	bool nvlGanado = false;
	bool rep = false;
	bool ini = true;
	bool partidaG = false;
	Tablero* tablero;
	Figuras *sp = new Figuras();
	Figuras *fg = new Figuras[4];
	stack<char> cajas;

	int cX1 = 570, x1 = 2;
	int cY1 = 356, y1 = 2;

	int cX2 = 570, x2 = 2;
	int cY2 = 458, y2 = 4;

	int cX3, x3;
	int cY3, y3;

	int cX4, x4;
	int cY4, y4;

public:

	vector<char> movimientosLvl1;
	vector<char> movimientosLvl2;
	vector<char> movimientosLvl3;
	vector<char> movimientosLvl4;
	vector<char> movimientosLvl5;

	AreaJuego();
	void bucleJugar(RenderWindow*& ventana);
	void clickPantalla(int x, int y);
	void eventoTeclas(Event event, char repeticion);
	void repeticionTeclas(char repeticion);
	void posicionGaneTablero(NodoCentral *nc, NodoCentral *nd, int x, int y);
	void moverCajas(char letra, int f, int c, int cx, int cy, int x, int y);
	void revisarGane();
	bool movimientoValido(char x);
	void reiniciarNivel();

	void inicializarMovimientosCorrectos();
	void llenarAutomatico(Event event);
	void ejecutarMovimientosAutomaticos(int lvl);
};