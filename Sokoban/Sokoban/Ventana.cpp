#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "AcercaDe.h"
#include "Jugar.h"
#include "AppContext.h"


using namespace std;
using namespace sf;

Ventana::Ventana(int largo, int ancho) {
	ventana = new RenderWindow(VideoMode(largo, ancho), "Sokoban");
    jg = new Jugar();
    acercaDe = new AcercaDe();
    areaJuego = new AreaJuego();
	bucleJuego();

}

void Ventana::bucleJuego() {

	while (this->ventana->isOpen()) {
         
        AppContext::getInstance().setWindow(ventana);

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
            
            AppContext::getInstance().setNivel(1);
            jg->bucleJugar(ventana); 

        }else if (AppContext::getInstance().getPantalla() == 3) {


        }else if (AppContext::getInstance().getPantalla() == 4) {
            acercaDe->bucleJugar(ventana);

        }
        else if (AppContext::getInstance().getPantalla() == 6) {
            areaJuego->bucleJugar(ventana);
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
                    clickPantalla(Mouse::getPosition(*ventana).x, Mouse::getPosition(*ventana).y);
                }

                if (AppContext::getInstance().getPantalla() == 2) {
                    jg->clickPantalla(Mouse::getPosition(*ventana).x, Mouse::getPosition(*ventana).y);
                }
                
                if (AppContext::getInstance().getPantalla() == 4) {
                    acercaDe->clickPantalla(Mouse::getPosition(*ventana).x, Mouse::getPosition(*ventana).y);
                }

                if (AppContext::getInstance().getPantalla() == 6) {
                    areaJuego->clickPantalla(Mouse::getPosition(*ventana).x, Mouse::getPosition(*ventana).y);
                }

            }
            else if (event.type == sf::Event::KeyPressed) {

                if (AppContext::getInstance().getPantalla() == 6) {
                    areaJuego->eventoTeclas(event, NULL);
                }
                
            }

        }
	}
}

void Ventana::clickPantalla(int x, int y) {

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
            cout << "Salir" << endl;
            ventana->close();
        }
  
}

