#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "AcercaDe.h"
#include "AppContext.h"



AcercaDe::AcercaDe() {

}

void AcercaDe::bucleJugar(RenderWindow*& ventana) {

    Texture texture;
    texture.loadFromFile("Resources/AcercaDe.JPG");
    Sprite sprite(texture);
    sprite.setPosition(0.f, 0.f);

    Texture acerca;
    acerca.loadFromFile("Resources/Creditos.PNG");
    Sprite acercaD(acerca);
    acercaD.setPosition(20.f, 0.f);

    ventana->clear();
    ventana->draw(sprite);
    ventana->draw(acercaD);
    ventana->display();
}

void AcercaDe::clickPantalla(int x, int y) {

    if (x > 24 && x < 328 && y > 750 && y < 833) {
        cout << "Retroceso" << endl;
        AppContext::getInstance().setPantalla(1);
    }
}