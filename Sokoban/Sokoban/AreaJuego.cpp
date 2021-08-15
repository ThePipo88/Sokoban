#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "AreaJuego.h"
#include "AppContext.h"



AreaJuego::AreaJuego() {

}

void AreaJuego::bucleJugar(RenderWindow*& ventana) {

    Texture texture;
    texture.loadFromFile("Resources/Juego.JPG");
    Sprite sprite(texture);
    sprite.setPosition(0.f, 0.f);

    Texture jugador;
    jugador.loadFromFile("Resources/sprite.png");
    Sprite sJugador(jugador);

    sJugador.setPosition(posX, posY);

    sJugador.setTextureRect(IntRect(32*frame, row, 32, 50));


    ventana->clear();
    ventana->draw(sprite);
    ventana->draw(sJugador);
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

void AreaJuego::eventoTeclas(Event event) {

    if (event.key.code == sf::Keyboard::A) {
        //cout << "Tecla A precionada" << endl;
        posX = posX - 10;
        row = 50;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::D) {
        //cout << "Tecla D precionada" << endl;
        posX = posX + 10;
        row = 100;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::W) {
        //cout << "Tecla W precionada" << endl;
        posY = posY - 10;
        row = 150;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::S) {
        //cout << "Tecla S precionada" << endl;
        posY = posY + 10;
        row = 0;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
}