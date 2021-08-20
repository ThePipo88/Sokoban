#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "Jugar.h"
#include "AppContext.h"
#include "Tablero.h"



Jugar::Jugar() {

    

    //tab->llenar(10, 10);

    //tab->imprimir();



}

void Jugar::bucleJugar(RenderWindow*& ventana) {

    Texture texture;
    //tab = new Tablero();
    evento1 = new Event;
    if (!texture.loadFromFile("Resources/Fondo2.JPG"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    Sprite sprite(texture);
    sprite.setPosition(0.f, 0.f);
    ventana->clear();
    ventana->draw(sprite);
    ventana->display();
    Jugar();
    //procesarEventos(ventana);

}

void Jugar::clickPantalla(int x, int y) {

    if (x > 15 && x < 419 && y > 759 && y < 840) {
        cout << "Retroceso" << endl;
        AppContext::getInstance().setPantalla(1);
    }
    else if (x > 964 && x < 1268 && y > 759 && y < 840) {
        cout << "Comenzar" << endl;
        AppContext::getInstance().setPantalla(6);
    }

}

//void Jugar::procesarEventos(RenderWindow*& ventana) {
//    while (ventana->pollEvent(*evento1)) {
//        switch (evento1->type) {
//        case Event::KeyPressed:
//            if (Keyboard::isKeyPressed(Keyboard::Down)) {
//                exit(1);
//            }
//            
//        }
//    
//    }
//}