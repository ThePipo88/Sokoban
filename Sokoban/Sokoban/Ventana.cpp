#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "AppContext.h"

using namespace std;
using namespace sf;

Ventana::Ventana(int largo, int ancho) {
	ventana = new RenderWindow(VideoMode(largo, ancho), "Sokoban");
    
	bucleJuego();

}

void Ventana::bucleJuego() {

	while (this->ventana->isOpen()) {
        

       

        if (AppContext::getInstance().getPantalla() == 1) {
            Texture texture;
            if (!texture.loadFromFile("Resources/Fondo3.JPG"))
            {
                cout << "Error al cargar imagen" << endl;
            }
            Sprite sprite(texture);
            sprite.setPosition(0.f, 0.f);
            ventana->clear();
            ventana->draw(sprite);
            ventana->display();

        }else if(AppContext::getInstance().getPantalla() == 2){
            Texture texture;
            if (!texture.loadFromFile("Resources/Fondo2.JPG"))
            {
                cout << "Error al cargar imagen" << endl;
            }
            Sprite sprite(texture);
            sprite.setPosition(0.f, 0.f);
            ventana->clear();
            ventana->draw(sprite);
            ventana->display();

        }else if (AppContext::getInstance().getPantalla() == 3) {


        }else if (AppContext::getInstance().getPantalla() == 4) {
            Texture texture;
            if (!texture.loadFromFile("Resources/AcercaDe.JPG"))
            {
                cout << "Error al cargar imagen" << endl;
            }
            Sprite sprite(texture);
            sprite.setPosition(0.f, 0.f);
            ventana->clear();
            ventana->draw(sprite);
            ventana->display();

        }
        else if (AppContext::getInstance().getPantalla() == 6) {
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

        

        Event event;
        while (this->ventana->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                ventana->close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {

                cout << Mouse::getPosition(*ventana).x << " , " << Mouse::getPosition(*ventana).y << endl;

                if (AppContext::getInstance().getPantalla() == 1) {
                    clickPantalla(Mouse::getPosition(*ventana).x, Mouse::getPosition(*ventana).y, 1);
                }

                if (AppContext::getInstance().getPantalla() == 2) {
                    clickPantalla(Mouse::getPosition(*ventana).x, Mouse::getPosition(*ventana).y, 2);
                }
                

            }

        }
	}
}

void Ventana::clickPantalla(int x, int y, int pantalla) {

    if (AppContext::getInstance().getPantalla() == 1) {

        if (x > 494 && x < 796 && y > 339 && y < 419) {
            cout << "Jugar" << endl;
            AppContext::getInstance().setPantalla(2);
        }
        else if (x > 494 && x < 796 && y > 467 && y < 546) {
            cout << "Cargar" << endl;

        }
        else if (x > 494 && x < 796 && y > 592 && y < 674) {
            cout << "Acerca de" << endl;
            AppContext::getInstance().setPantalla(4);
        }
        else if (x > 494 && x < 796 && y > 720 && y < 801) {
            cout << "Saliiiiiiiiiiiir" << endl;
        }

    }
    else if (AppContext::getInstance().getPantalla() == 2) {

        if (x > 15 && x < 419 && y > 759 && y < 840) {
            cout << "Retroceso" << endl;
            AppContext::getInstance().setPantalla(1);
        }
        else if (x >  964 && x < 1268 && y > 759 && y < 840) {
            cout << "Comenzar" << endl;
            AppContext::getInstance().setPantalla(6);
        }

    }
    
  
}