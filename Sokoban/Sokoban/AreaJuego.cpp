#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "AreaJuego.h"
#include "AppContext.h"



AreaJuego::AreaJuego() {
 tablero = new Tablero();
    tablero->llenar(7, 7);
    tablero->imprimir();
}

void AreaJuego::bucleJugar(RenderWindow*& ventana) {

   

    Texture mapa;
    mapa.loadFromFile("Resources/mapa1.PNG");
    Sprite mp1(mapa);
    mp1.setPosition(460.f, 250.f);

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
    ventana->draw(mp1);
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

bool AreaJuego::movimientoValido(char x) {

    NodoCentral* aux = tablero->buscarJugador();
   // NodoCentral* aux3 = aux;
    NodoCentral* aux2;
    char c;
    //tablero->buscarJugador();
    if (aux !=NULL && aux->arriba->getDato() != '#' && x == 'W' ) {
        c = aux->getDato();
        aux2 = aux->arriba;
        aux->setDato(aux2->getDato());
        aux2->setDato(c);
        return true;
    }else {
        if (aux != NULL && aux->abajo->getDato() != '#' && x == 'S') {
           // aux3 = aux;
            c = aux->getDato();
            aux2 = aux->abajo;
            
            aux->setDato(aux2->getDato());
            aux2->setDato(c);

            return true;
        }
        else {
            if (aux != NULL && aux->izquierda->getDato() != '#' && x == 'A') {
                c = aux->getDato();
                aux2 = aux->izquierda;
                aux->setDato(aux2->getDato());
                aux2->setDato(c);

                return true;
            }
            else {
                if (aux != NULL && aux->derecha->getDato() != '#' && x == 'D') {
                    c = aux->getDato();
                    aux2 = aux->derecha;
                    aux->setDato(aux2->getDato());
                    aux2->setDato(c);
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    }

   

void AreaJuego::eventoTeclas(Event event) {

    if (event.key.code == sf::Keyboard::A && movimientoValido('A') ) {
        //cout << "Tecla A precionada" << endl;
        tablero->imprimir();
        posX = posX - 54;
        row = 50;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::D && movimientoValido('D')) {
        //cout << "Tecla D precionada" << endl;
        tablero->imprimir();
        posX = posX + 54;
        row = 100;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::W && movimientoValido('W')) {
        //cout << "Tecla W precionada" << endl;
        tablero->imprimir();
        posY = posY - 51;
        row = 150;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::S && movimientoValido('S')) {
        //cout << "Tecla S precionada" << endl;
        tablero->imprimir();
        posY = posY + 51;
        row = 0;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
}