#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <stack>
#include <Windows.h>
#include "Ventana.h"
#include "AreaJuego.h"
#include "AppContext.h"
#include "Figuras.h"
#include <chrono>
#include <thread>
#include <ctime>
#include <fstream>



AreaJuego::AreaJuego() {

    delete(tablero);
    tablero = new Tablero();
    tablero->llenar(7, 7);
    tablero->imprimir();
}

void AreaJuego::bucleJugar(RenderWindow*& ventana) {

    Texture texture;
    texture.loadFromFile("Resources/Juego.PNG");
    Sprite sprite(texture);
    sprite.setPosition(0.f, 0.f);
    
    if (AppContext::getInstance().getNivel() == 1) {

        Texture mapa;
        mapa.loadFromFile("Resources/mapa1.PNG");
        Sprite mp1(mapa);
        mp1.setPosition(460.f, 250.f);

        sp->crearJugador(posX, posY, frame, row);
        fg[0].crearCajas(cX1, cY1);
        fg[1].crearCajas(cX2, cY2);

        ventana->clear();
        ventana->draw(sprite);
        ventana->draw(mp1);
        ventana->draw(sp->getSpriteJugador());
        ventana->draw(fg[0].getSpriteCaja());
        ventana->draw(fg[1].getSpriteCaja());

        if (partidaG) {
            Texture gane;
            gane.loadFromFile("Resources/guardada.PNG");
            Sprite ganar(gane);
            ganar.setPosition(280.f, 100.f);
            ventana->draw(ganar);
        }

        if (nvlGanado == true) {
            Texture gane;
            gane.loadFromFile("Resources/gane.PNG");
            Sprite ganar(gane);
            ganar.setPosition(0.f, 0.f);
            ventana->draw(ganar);
        }
        ventana->display();
    }
    else if (AppContext::getInstance().getNivel() == 2) {

        Texture mapa;
        mapa.loadFromFile("Resources/mapa2.PNG");
        Sprite mp1(mapa);
        mp1.setPosition(460.f, 230.f);

        sp->crearJugador(posX, posY, frame, row);
        fg[0].crearCajas(cX1, cY1);
        fg[1].crearCajas(cX2, cY2);

        ventana->clear();
        ventana->draw(sprite);
        ventana->draw(mp1);
        ventana->draw(sp->getSpriteJugador());
        ventana->draw(fg[0].getSpriteCaja());
        ventana->draw(fg[1].getSpriteCaja());

        if (partidaG) {
            Texture gane;
            gane.loadFromFile("Resources/guardada.PNG");
            Sprite ganar(gane);
            ganar.setPosition(280.f, 100.f);
            ventana->draw(ganar);
        }

        if (nvlGanado == true) {
            Texture gane;
            gane.loadFromFile("Resources/gane.PNG");
            Sprite ganar(gane);
            ganar.setPosition(0.f, 0.f);
            ventana->draw(ganar);
        }
        ventana->display();

    }
    else if (AppContext::getInstance().getNivel() == 3) {

        Texture mapa;
        mapa.loadFromFile("Resources/mapa3.PNG");
        Sprite mp3(mapa);
        mp3.setPosition(430.f, 230.f);

        sp->crearJugador(posX, posY, frame, row);
        fg[0].crearCajas(cX1, cY1);
        fg[1].crearCajas(cX2, cY2);
        fg[2].crearCajas(cX3, cY3);

        ventana->clear();
        ventana->draw(sprite);
        ventana->draw(mp3);
        ventana->draw(sp->getSpriteJugador());
        ventana->draw(fg[0].getSpriteCaja());
        ventana->draw(fg[1].getSpriteCaja());
        ventana->draw(fg[2].getSpriteCaja());

        if (partidaG) {
            Texture gane;
            gane.loadFromFile("Resources/guardada.PNG");
            Sprite ganar(gane);
            ganar.setPosition(280.f, 100.f);
            ventana->draw(ganar);
        }

        if (nvlGanado == true) {
            Texture gane;
            gane.loadFromFile("Resources/gane.PNG");
            Sprite ganar(gane);
            ganar.setPosition(0.f, 0.f);
            ventana->draw(ganar);
        }
        ventana->display();
    }
    else if (AppContext::getInstance().getNivel() == 4) {
        
        Texture mapa;
        mapa.loadFromFile("Resources/mapa4.PNG");
        Sprite mp4(mapa);
        mp4.setPosition(400.f, 220.f);

        sp->crearJugador(posX, posY, frame, row);
        fg[0].crearCajas(cX1, cY1);
        fg[1].crearCajas(cX2, cY2);
        fg[2].crearCajas(cX3, cY3);

        ventana->clear();
        ventana->draw(sprite);
        ventana->draw(mp4);
        ventana->draw(sp->getSpriteJugador());
        ventana->draw(fg[0].getSpriteCaja());
        ventana->draw(fg[1].getSpriteCaja());
        ventana->draw(fg[2].getSpriteCaja());

        if (partidaG) {
            Texture gane;
            gane.loadFromFile("Resources/guardada.PNG");
            Sprite ganar(gane);
            ganar.setPosition(280.f, 100.f);
            ventana->draw(ganar);
        }

        if (nvlGanado == true) {
            Texture gane;
            gane.loadFromFile("Resources/gane.PNG");
            Sprite ganar(gane);
            ganar.setPosition(0.f, 0.f);
            ventana->draw(ganar);
        }
        ventana->display();

    }
    else if (AppContext::getInstance().getNivel() == 5) {
    Texture mapa;
    mapa.loadFromFile("Resources/mapa5.PNG");
    Sprite mp4(mapa);
    mp4.setPosition(390.f, 190.f);

    sp->crearJugador(posX, posY, frame, row);
    fg[0].crearCajas(cX1, cY1);
    fg[1].crearCajas(cX2, cY2);
    fg[2].crearCajas(cX3, cY3);
    fg[3].crearCajas(cX4, cY4);

    ventana->clear();
    ventana->draw(sprite);
    ventana->draw(mp4);
    ventana->draw(sp->getSpriteJugador());
    ventana->draw(fg[0].getSpriteCaja());
    ventana->draw(fg[1].getSpriteCaja());
    ventana->draw(fg[2].getSpriteCaja());
    ventana->draw(fg[3].getSpriteCaja());

    if (partidaG) {
        Texture gane;
        gane.loadFromFile("Resources/guardada.PNG");
        Sprite ganar(gane);
        ganar.setPosition(280.f, 100.f);
        ventana->draw(ganar);
    }

    if (nvlGanado == true) {
        Texture gane;
        gane.loadFromFile("Resources/terminado.PNG");
        Sprite ganar(gane);
        ganar.setPosition(180.f, 80.f);
        ventana->draw(ganar);
    }
    ventana->display();
    }
    
}

void AreaJuego::clickPantalla(int x, int y) {

     if (x > 964 && x < 1268 && y > 759 && y < 840) {
        cout << "Comenzar" << endl;
        AppContext::getInstance().setPantalla(6);
    }
    else if (x > 1185 && x < 1266 && y > 175 && y < 257 || x > 715 && x < 824 && y > 566 && y < 680 && nvlGanado && AppContext::getInstance().getNivel() == 5) {

            AppContext::getInstance().setNivel(1);
            nvlGanado = false;
            delete(tablero);
            tablero = new Tablero();
            tablero->llenar(7, 7);

            cX1 = 570, x1 = 2;
            cY1 = 356, y1 = 2;

            cX2 = 570, x2 = 2;
            cY2 = 458, y2 = 4;

            posX = 634, posY = 305;
        
        AppContext::getInstance().setPantalla(1);
    }
    else if (x > 646 && x < 820 && y > 483 && y < 618 && nvlGanado) {
                
         cout << "Siguiente nivel" << endl;

         AppContext::getInstance().setNivel(AppContext::getInstance().getNivel() + 1);

         nvlGanado = false;

         movimientosLvl1.clear();

         if (AppContext::getInstance().getNivel() == 2) {

             delete(tablero);
             tablero = new Tablero();
             tablero->llenar(8, 8);
             tablero->imprimir();
             
             posY = 335;

             cX1 = 678, x1 = 4;
             cY1 = 440, y1 = 4;
             cX2 = 624, x2 = 3;
             cY2 = 491, y2 = 5;
         }
         else if (AppContext::getInstance().getNivel() == 3) {

             delete(tablero);
             tablero = new Tablero();
             tablero->llenar(8, 8);
             tablero->imprimir();

             posX = 710, posY = 540;
             cX1 = 702, x1 = 5;
             cY1 = 335, y1 = 2;
             cX2 = 702, x2 = 5;
             cY2 = 386, y2 = 3;
             cX3 = 702, x3 = 5;
             cY3 = 437, y3 = 4;

         }
         else if (AppContext::getInstance().getNivel() == 4) {

             delete(tablero);
             tablero = new Tablero();
             tablero->llenar(10, 7);

             posX = 735, posY = 325;
             cX1 = 618, x1 = 4;
             cY1 = 325, y1 = 2;
             cX2 = 564, x2 = 3;
             cY2 = 325, y2 = 2;
             cX3 = 510, x3 = 2;
             cY3 = 325, y3 = 2;

         }
         else if (AppContext::getInstance().getNivel() == 5) {

             delete(tablero);
             tablero = new Tablero();
             tablero->llenar(10, 9);
             tablero->imprimir();

             posX = 726, posY = 298;
             cX1 = 610, x1 = 4;
             cY1 = 298, y1 = 2;
             cX2 = 500, x2 = 2;
             cY2 = 398, y2 = 4;
             cX3 = 608, x3 = 4;
             cY3 = 450, y3 = 5;
             cX4 = 556, x4 = 3;
             cY4 = 501, y4 = 6;
         }

     }
    else if (x > 1185 && x < 1266 && y > 47 && y < 128) {

         movimientosLvl1.clear();
         reiniciarNivel();
        
     }
    else if (x > 490 && x < 601 && y > 492 && y < 616 && nvlGanado) {
    RenderWindow* ventana = AppContext::getInstance().getWindow();
       nvlGanado = false;
       reiniciarNivel();
       bucleJugar(ventana);
       Sleep(200);
       ejecutarMovimientosAutomaticos(1);
       cout << movimientosLvl1.size() << endl;
     }
    else if (x > 513 && x < 633 && y > 557 && y < 684 && nvlGanado && AppContext::getInstance().getNivel() == 5) {

    RenderWindow* ventana = AppContext::getInstance().getWindow();
    nvlGanado = false;
    reiniciarNivel();
    bucleJugar(ventana);
    Sleep(200);
    ejecutarMovimientosAutomaticos(1);

    }
    else if (x > 1186 && x < 1266 && y > 270 && y < 384) {
    ofstream fichero("partida.txt");
    fichero << AppContext::getInstance().getNivel() << endl;
    fichero << posX << endl;
    fichero << posY << endl;
    fichero << tablero->buscarJugador()->getX() << endl;
    fichero << tablero->buscarJugador()->getY() << endl;

    if (AppContext::getInstance().getNivel() == 1 || AppContext::getInstance().getNivel() == 2) {
        fichero << cX1 << endl; fichero << cY1 << endl;
        fichero << x1 << endl; fichero << y1 << endl;
        fichero << cX2 << endl; fichero << cY2 << endl;
        fichero << x2 << endl; fichero << y2 << endl;
    }
    else if (AppContext::getInstance().getNivel() == 3 || AppContext::getInstance().getNivel() == 4) {
        fichero << cX1 << endl; fichero << cY1 << endl;
        fichero << x1 << endl; fichero << y1 << endl;
        fichero << cX2 << endl; fichero << cY2 << endl;
        fichero << x2 << endl; fichero << y2 << endl;
        fichero << cX3 << endl; fichero << cY3 << endl;
        fichero << x3 << endl; fichero << y3 << endl;
    }
    else if (AppContext::getInstance().getNivel() == 5) {
        fichero << cX1 << endl; fichero << cY1 << endl;
        fichero << x1 << endl; fichero << y1 << endl;
        fichero << cX2 << endl; fichero << cY2 << endl;
        fichero << x2 << endl; fichero << y2 << endl;
        fichero << cX3 << endl; fichero << cY3 << endl;
        fichero << x3 << endl; fichero << y3 << endl;
        fichero << cX4 << endl; fichero << cY4 << endl;
        fichero << x4 << endl; fichero << y4 << endl;
    }

    fichero.close();
    partidaG = true;
    }
    else if (x > 512 && x < 815 && y > 405 && y < 486
    && partidaG) {
    partidaG = false;
    }
}

void AreaJuego::reiniciarNivel() {


    if (AppContext::getInstance().getNivel() == 1 && nvlGanado == false) {

        delete(tablero);
        tablero = new Tablero();
        tablero->llenar(7, 7);
        cX1 = 570, x1 = 2;
        cY1 = 356, y1 = 2;
        cX2 = 570, x2 = 2;
        cY2 = 458, y2 = 4;
        posX = 634, posY = 305;

    }
    else if (AppContext::getInstance().getNivel() == 2 && nvlGanado == false) {

        delete(tablero);
        tablero = new Tablero();
        tablero->llenar(8, 8);

        posX = 634, posY = 335;
        cX1 = 678, x1 = 4;
        cY1 = 440, y1 = 4;
        cX2 = 624, x2 = 3;
        cY2 = 491, y2 = 5;

    }
    else if (AppContext::getInstance().getNivel() == 3 && nvlGanado == false) {

        delete(tablero);
        tablero = new Tablero();
        tablero->llenar(8, 8);

        posX = 710, posY = 540;
        cX1 = 702, x1 = 5;
        cY1 = 335, y1 = 2;
        cX2 = 702, x2 = 5;
        cY2 = 386, y2 = 3;
        cX3 = 702, x3 = 5;
        cY3 = 437, y3 = 4;

    }
    else if (AppContext::getInstance().getNivel() == 4 && nvlGanado == false) {

        delete(tablero);
        tablero = new Tablero();
        tablero->llenar(10, 7);

        posX = 735, posY = 325;
        cX1 = 618, x1 = 4;
        cY1 = 325, y1 = 2;
        cX2 = 564, x2 = 3;
        cY2 = 325, y2 = 2;
        cX3 = 510, x3 = 2;
        cY3 = 325, y3 = 2;
    }
    else if (AppContext::getInstance().getNivel() == 5 && !nvlGanado) {

        delete(tablero);
        tablero = new Tablero();
        tablero->llenar(10, 9);

        posX = 726, posY = 298;
        cX1 = 610, x1 = 4;
        cY1 = 298, y1 = 2;
        cX2 = 500, x2 = 2;
        cY2 = 398, y2 = 4;
        cX3 = 608, x3 = 4;
        cY3 = 450, y3 = 5;
        cX4 = 556, x4 = 3;
        cY4 = 501, y4 = 6;
    }

    tablero->imprimir();
    while (cajas.size() != 0) {
        cajas.pop();
    }

}

void AreaJuego::inicializarMovimientosCorrectos() {  

}


void AreaJuego::ejecutarMovimientosAutomaticos(int lvl) {

    if (lvl == 1) {

        RenderWindow* ventana = AppContext::getInstance().getWindow();
        int i = 0;
        while (i < movimientosLvl1.size() && !nvlGanado) {
            Sleep(500);
            repeticionTeclas(movimientosLvl1[i]);
            bucleJugar(ventana);
            i++;
        }

    }

}

bool AreaJuego::movimientoValido(char x) {

    system("cls");
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
                moverCajas('-', aux->getX(), aux->getY() - 1, 0, -51, 0, -1);
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
                moverCajas('-', aux->getX(), aux->getY() - 1, 0, -51, 0, -1);
                aux->arriba->setDato('@');
                aux->setDato(' ');
                cajas.pop();
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
                    moverCajas('+', aux->getX(), aux->getY() + 1, 0, 51, 0, 1);
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
                    moverCajas('+', aux->getX(), aux->getY() + 1, 0, 51, 0, 1);
                    aux->abajo->setDato('@');
                    aux->setDato(' ');
                    cajas.pop();
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
                        moverCajas('-', aux->getX() - 1, aux->getY(), -54, 0, -1, 0);
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
                        moverCajas('-', aux->getX() - 1, aux->getY(), -54, 0, -1, 0);
                        aux->izquierda->setDato('@');
                        aux->setDato(' ');
                        cajas.pop();
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
                            moverCajas('+',aux->getX() + 1, aux->getY(), 54, 0, 1, 0);
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
                            moverCajas('+', aux->getX() + 1, aux->getY(),54,0,1,0);
                            aux->derecha->setDato('@');
                            aux->setDato(' ');
                            cajas.pop();
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

void AreaJuego::revisarGane() {
    if (AppContext::getInstance().getNivel() == 1 || AppContext::getInstance().getNivel() == 2) {
        if (cajas.size() == 2) {
            nvlGanado = true;
            cajas.pop();
            cajas.pop();
            cout << "Juego ganado" << endl;
        }
        cout << "Tamanio " << cajas.size() << endl;
    }
    else if (AppContext::getInstance().getNivel() == 3 || AppContext::getInstance().getNivel() == 4) {
        if (cajas.size() == 3) {
            nvlGanado = true;
            cajas.pop();
            cajas.pop();
            cajas.pop();
            cout << "Juego ganado" << endl;
        }
        cout << "Tamanio " << cajas.size() << endl;
    }
    else if (AppContext::getInstance().getNivel() == 3 || AppContext::getInstance().getNivel() == 5) {
        if (cajas.size() == 4) {
            nvlGanado = true;
            cajas.pop();
            cajas.pop();
            cajas.pop();
            cajas.pop();
            cout << "Juego ganado" << endl;
        }
        cout << "Tamanio " << cajas.size() << endl;
    }
   
}

void AreaJuego::posicionGaneTablero(NodoCentral* nc,NodoCentral *nd, int x, int y) {

    if (AppContext::getInstance().getNivel() == 1) {

        if (nc->getX() + x == 4 && nc->getY() + y == 2 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 4 && nc->getY() + y == 4 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        
        if (nc->getX() == 4 && nc->getY() == 2 || nc->getX() == 4 && nc->getY() == 4) {
            nc->setDato('.');
        }   

    }
    else if (AppContext::getInstance().getNivel() == 2) {

        if (nc->getX() + x == 2 && nc->getY() + y == 4 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 3 && nc->getY() + y == 6 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }

        if (nc->getX() == 2 && nc->getY() == 4 || nc->getX() == 3 && nc->getY() == 6) {
            nc->setDato('.');
        }

    }
    else if (AppContext::getInstance().getNivel() == 3) {

        if (nc->getX() + x == 6 && nc->getY() + y == 2 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 6 && nc->getY() + y == 3 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 6 && nc->getY() + y == 4 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }

        if (nc->getX() == 6 && nc->getY() == 2 || nc->getX() == 6 && nc->getY() == 3 || nc->getX() == 6 && nc->getY() == 4) {
            nc->setDato('.');
        }
    }
    else if (AppContext::getInstance().getNivel() == 4) {

        if (nc->getX() + x == 6 && nc->getY() + y == 1 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 7 && nc->getY() + y == 1 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 8 && nc->getY() + y == 1 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }

        if (nc->getX() == 6 && nc->getY() == 1 || nc->getX() == 7 && nc->getY() == 1 || nc->getX() == 8 && nc->getY() == 1) {
            nc->setDato('.');
        }
    }
    else if (AppContext::getInstance().getNivel() == 5) {

        if (nc->getX() + x == 1 && nc->getY() + y == 6 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 2 && nc->getY() + y == 6 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 1 && nc->getY() + y == 7 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }
        else if (nc->getX() + x == 2 && nc->getY() + y == 7 && nd->getDato() == '$') {
            cajas.push('$');
            revisarGane();
            nd->setDato('!');
        }

        if (nc->getX() == 1 && nc->getY() == 6 || nc->getX() == 2 && nc->getY() == 6 || nc->getX() == 1 && nc->getY() == 7 || nc->getX() == 2 && nc->getY() == 7) {
            nc->setDato('.');
        }
    }
}

void AreaJuego::eventoTeclas(Event event, char repeticion) {


    if (nvlGanado == false) {

        if (event.key.code == sf::Keyboard::A) {

            repeticionTeclas('A');
        }
        else if (event.key.code == sf::Keyboard::D) {

            repeticionTeclas('D');
        }
        else if (event.key.code == sf::Keyboard::W) {

            repeticionTeclas('W');
        }
        else if (event.key.code == sf::Keyboard::S) {

            repeticionTeclas('S');
        }
    }

}

void AreaJuego::repeticionTeclas(char repeticion) {

    if (nvlGanado == false) {

        if (repeticion == 'A' && movimientoValido('A')) {
            movimientosLvl1.push_back('A');
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
        else if (repeticion == 'D' && movimientoValido('D')) {
            movimientosLvl1.push_back('D');
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
        else if (repeticion == 'W' && movimientoValido('W')) {
            movimientosLvl1.push_back('W');
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
        else if (repeticion == 'S' && movimientoValido('S')) {
            movimientosLvl1.push_back('S');
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

}

void AreaJuego::moverCajas(char letra, int f, int c, int cx, int cy, int x, int y) {

    if (AppContext::getInstance().getNivel() == 1 || AppContext::getInstance().getNivel() == 2) {
        
            if (x1 == f && y1 == c)
            {
             cX1 = cX1 + cx;
             cY1 = cY1 + cy;
             x1 = x1 + x;
             y1 = y1 + y;

            }
            else if(x2 == f && y2 == c)
            {
             cX2 = cX2 + cx;
             cY2 = cY2 + cy;
             x2 = x2 + x;
             y2 = y2 + y;
                
            }     
    }
    else if (AppContext::getInstance().getNivel() == 3 || AppContext::getInstance().getNivel() == 4) {

        if (x1 == f && y1 == c)
        {
            cX1 = cX1 + cx;
            cY1 = cY1 + cy;
            x1 = x1 + x;
            y1 = y1 + y;

        }
        else if (x2 == f && y2 == c)
        {
            cX2 = cX2 + cx;
            cY2 = cY2 + cy;
            x2 = x2 + x;
            y2 = y2 + y;

        }
        else if (x3 == f && y3 == c) {
            cX3 = cX3 + cx;
            cY3 = cY3 + cy;
            x3 = x3 + x;
            y3 = y3 + y;
        }
    }
    else if (AppContext::getInstance().getNivel() == 5) {

        if (x1 == f && y1 == c)
        {
            cX1 = cX1 + cx;
            cY1 = cY1 + cy;
            x1 = x1 + x;
            y1 = y1 + y;

        }
        else if (x2 == f && y2 == c)
        {
            cX2 = cX2 + cx;
            cY2 = cY2 + cy;
            x2 = x2 + x;
            y2 = y2 + y;

        }
        else if (x3 == f && y3 == c) {
            cX3 = cX3 + cx;
            cY3 = cY3 + cy;
            x3 = x3 + x;
            y3 = y3 + y;
        }
        else if (x4 == f && y4 == c) {
            cX4 = cX4 + cx;
            cY4 = cY4 + cy;
            x4 = x4 + x;
            y4 = y4 + y;
        }
    }
}