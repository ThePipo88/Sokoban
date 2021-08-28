#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ventana.h"
#include "AreaJuego.h"
#include "AppContext.h"
#include "Figuras.h"



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

    sp->crearJugador(posX, posY, frame, row);
    fg[0].crearCajas(cX1, cY1);
    fg[1].crearCajas(cX2, cY2);

    ventana->clear();
    ventana->draw(sprite);
    ventana->draw(mp1);
    ventana->draw(sp->getSpriteJugador());
    ventana->draw(fg[0].getSpriteCaja());
    ventana->draw(fg[1].getSpriteCaja());
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

//Ayudaaaaaaaaaaaaaaaaaaaaaaaa

bool AreaJuego::movimientoValido(char x) {

    NodoCentral* aux = tablero->buscarJugador();
   // NodoCentral* aux3 = aux;
    NodoCentral* aux2;
    char c;

    bool dt = false;
    //tablero->buscarJugador();
    if (aux !=NULL && aux->arriba->getDato() != '#' && x == 'W' ) {

        if (aux->arriba->getDato() == '$') {
            if (aux->arriba->arriba->getDato() != '$' && aux->arriba->arriba->getDato() != '#' && aux->arriba->arriba->getDato() != '!') {
                aux->arriba->arriba->setDato('$');
                aux->arriba->setDato('@');
                aux->setDato(' ');
                moverCajas('W', aux->getX(), aux->getY() - 1);
                dt = true;
                posicionGaneTablero(aux, aux->arriba->arriba, 0, -2);
            }
            else
            {
                dt = false;
            }
        }
        else if (aux->arriba->getDato() == '!') {

            if (aux->arriba->arriba->getDato() != '#') {
                aux->arriba->arriba->setDato('$');
                moverCajas('W', aux->getX(), aux->getY() - 1);
                aux->arriba->setDato('@');
                aux->setDato(' ');
                dt = true;
                posicionGaneTablero(aux, aux->arriba->arriba, 0, -2);
            }
            else {
                dt = false;
            }
   
        }
        else if (aux->arriba->getDato() != '#') {
            aux->arriba->setDato('@');
            aux->setDato(' ');
            dt = true;
            posicionGaneTablero(aux, aux->arriba->arriba, 0, -2);
        }
        

        return dt;
    }else {
        if (aux != NULL && aux->abajo->getDato() != '#' && x == 'S') {

            if (aux->abajo->getDato() == '$') {
                if (aux->abajo->abajo->getDato() != '$' && aux->abajo->abajo->getDato() != '#' && aux->abajo->abajo->getDato() != '!') {
                    aux->abajo->abajo->setDato('$');
                    aux->abajo->setDato('@');
                    aux->setDato(' ');
                    moverCajas('S', aux->getX(), aux->getY() + 1);
                    dt = true;
                    posicionGaneTablero(aux, aux->abajo->abajo, 0, +2);
                }
                else
                {
                    dt = false;
                }
            }
            else if (aux->abajo->getDato() == '!') {

                if (aux->abajo->abajo->getDato() != '#') {
                    aux->abajo->abajo->setDato('$');
                    moverCajas('S', aux->getX(), aux->getY() + 1);
                    aux->abajo->setDato('@');
                    aux->setDato(' ');
                    dt = true;
                    posicionGaneTablero(aux, aux->abajo->abajo, 0, +2);
                }
                else {
                    dt = false;
                }              
            }
            else if (aux->abajo->getDato() != '#') {
                aux->abajo->setDato('@');
                aux->setDato(' ');
                dt = true;
                posicionGaneTablero(aux, aux->abajo->abajo, 0, +2);
            }

            return dt;
        }
        else {
            if (aux != NULL && aux->izquierda->getDato() != '#' && x == 'A') {
                if (aux->izquierda->getDato() == '$') {
                    if (aux->izquierda->izquierda->getDato() != '$' && aux->izquierda->izquierda->getDato() != '#' && aux->izquierda->izquierda->getDato() != '!') {
                        aux->izquierda->izquierda->setDato('$');
                        aux->izquierda->setDato('@');
                        aux->setDato(' ');
                        moverCajas('A', aux->getX()-1, aux->getY());
                        dt = true;
                        posicionGaneTablero(aux, aux->izquierda->izquierda, -2, 0);
                    }
                    else
                    {
                        dt = false;
                    }
                }
                else if (aux->izquierda->getDato() == '!') {

                    if (aux->izquierda->izquierda->getDato()  != '#') {
                        aux->izquierda->izquierda->setDato('$');
                        moverCajas('A', aux->getX() - 1, aux->getY());
                        aux->izquierda->setDato('@');
                        aux->setDato(' ');
                        dt = true;
                        posicionGaneTablero(aux, aux->izquierda->izquierda, -2, 0);
                    }
                    else {
                        dt = false;
                    }  
                }
                else if (aux->izquierda->getDato() != '#') {
                    aux->izquierda->setDato('@');
                    aux->setDato(' ');
                    dt = true;
                    posicionGaneTablero(aux, aux->izquierda->izquierda, -2, 0);
                }

                return dt;
            }
            else {
                if (aux != NULL && aux->derecha->getDato() != '#' && x == 'D') {
                    if (aux->derecha->getDato() == '$') {
                        if (aux->derecha->derecha->getDato() != '$' && aux->derecha->derecha->getDato() != '#' && aux->derecha->derecha->getDato() != '!') {
                            aux->derecha->derecha->setDato('$');
                            aux->derecha->setDato('@');
                            aux->setDato(' ');
                            moverCajas('D', aux->getX() + 1, aux->getY());
                            dt = true;
                            posicionGaneTablero(aux, aux->derecha->derecha, 2, 0);
                        }
                        else
                        {
                            dt = false;
                        }
                    }
                    else if (aux->derecha->getDato() == '!') {

                        if (aux->derecha->derecha->getDato() != '#') {

                            aux->derecha->derecha->setDato('$');
                            moverCajas('D', aux->getX() + 1, aux->getY());
                            aux->derecha->setDato('@');
                            aux->setDato(' ');
                            dt = true;
                            posicionGaneTablero(aux, aux->derecha->derecha, 2, 0);
                        }
                        else {
                            dt = false;
                        }                     
                    }
                    else if (aux->derecha->getDato() != '#') {
                        aux->derecha->setDato('@');
                        aux->setDato(' ');
                        dt = true;
                        posicionGaneTablero(aux, aux->derecha->derecha, 2, 0);
                    }

                    return dt;
                }
                else {
                    return dt;
                }
            }
        }
    }
    }

void AreaJuego::posicionGaneTablero(NodoCentral* nc,NodoCentral *nd, int x, int y) {

    if (AppContext::getInstance().getNivel() == 1) {

        if (nc->getX() + x == 4 && nc->getY() + y == 2 && nd->getDato() == '$') {
            nd->setDato('!');
        }
        else if (nc->getX() + x == 4 && nc->getY() + y == 4 && nd->getDato() == '$') {
            nd->setDato('!');
        }
        
        if (nc->getX() == 4 && nc->getY() == 2 || nc->getX() == 4 && nc->getY() == 4) {
            nc->setDato('.');
        }   

    }
}

void AreaJuego::eventoTeclas(Event event, char repeticion) {

    if (event.key.code == sf::Keyboard::A && movimientoValido('A') || repeticion == 'A' && movimientoValido('A')) {
        tablero->imprimir();
        posX = posX - 54;
        cout << posX << endl;
        row = 50;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
        
    }
    else if (event.key.code == sf::Keyboard::D && movimientoValido('D')) {

        tablero->imprimir();
        posX = posX + 54;
        cout << posX << endl;
        row = 100;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::W && movimientoValido('W')) {

        tablero->imprimir();
        posY = posY - 51;
        cout << posY << endl;
        row = 150;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
    else if (event.key.code == sf::Keyboard::S && movimientoValido('S')) {

        tablero->imprimir();
        posY = posY + 51;
        cout << posY << endl;
        row = 0;
        if (frame_counter == 1) {
            frame = (frame + 1) % 4;
            frame_counter = 0;
        }
        frame_counter++;
    }
}

void AreaJuego::moverCajas(char letra, int f, int c) {

    if (AppContext::getInstance().getNivel() == 1) {

            if (x1 == f && y1 == c)
            {
                if (letra == 'W') {
                    cY1 = cY1 - 51;
                    y1 = y1 - 1;
                }
                else if (letra == 'S') {
                    cY1 = cY1 + 51;
                    y1 = y1 + 1;
                }
                else if (letra == 'A') {
                    cX1 = cX1 - 54;
                    x1 = x1 - 1;
                }
                else if (letra == 'D') {
                    cX1 = cX1 + 54;
                    x1 = x1 + 1;
                }
                
            }
            else if(x2 == f && y2 == c)
            {
                if (letra == 'W') {
                    cY2 = cY2 - 51;
                    y2 = y2 - 1;
                }
                else if (letra == 'S') {
                    cY2 = cY2 + 51;
                    y2 = y2 + 1;
                }
                else if (letra == 'A') {
                    cX2 = cX2 - 51;
                    x2 = x2 - 1;
                }
                else if (letra == 'D') {
                    cX2 = cX2 + 51;
                    x2 = x2 + 1;
                }
            }
         
    }
    else if (AppContext::getInstance().getNivel() == 2) {

    }
    else if (AppContext::getInstance().getNivel() == 3) {

    }
    else if (AppContext::getInstance().getNivel() == 4) {

    }
    else if (AppContext::getInstance().getNivel() == 5) {

    }
}