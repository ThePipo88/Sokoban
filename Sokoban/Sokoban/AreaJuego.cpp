#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "AreaJuego.h"
#include "AppContext.h"



AreaJuego::AreaJuego() {

}

void AreaJuego::bucleJugar(RenderWindow*& ventana) {

    Texture texture;
    if (!texture.loadFromFile("Resources/Juego.JPG"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    Sprite sprite(texture);
    sprite.setPosition(0.f, 0.f);
    ventana->clear();
    ventana->draw(sprite);
    ventana->display();
}

void AreaJuego::clickPantalla(int x, int y) {

    if (x > 15 && x < 419 && y > 759 && y < 840) {
        cout << "Retroceso" << endl;
        AppContext::getInstance().setPantalla(1);
    }
    else if (x > 964 && x < 1268 && y > 759 && y < 840) {
        cout << "Comenzar" << endl;
        AppContext::getInstance().setPantalla(6);
    }

}