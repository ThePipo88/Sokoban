#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Ventana.h"
#include "AreaJuego.h"
#include "AppContext.h"
#include "Figuras.h"

#include <chrono>
#include <thread>
#include <ctime>

//using std::erase;

AreaJuego::AreaJuego() {
 tablero = new Tablero();
    tablero->llenar(7, 7);
    tablero->imprimir();
    inicializarMovimientosCorrectos();
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


    //llenarAutomatico(1);
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

void remove(vector<char>& v, const char & item)
{
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

void f()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void delay(int secs) {
    for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}
void AreaJuego::ejecutarMovimientosAutomaticos(int lvl, Event ev) {
    Event e;
    Time time = seconds(1);
    //double d = 10;
    e.key.code = sf::Keyboard::P;
    /*while (!x.empty()) {
    eventoTeclas(e, x.front);
    x.
    }*/
    //movimientos(Lvl1[0].

    if (lvl == 1) {
        auto elem_to_remove = movimientosLvl1.begin();
        eventoTeclas(e, movimientosLvl1[0]);
        movimientosLvl1.erase(elem_to_remove);
    }
    else if (lvl == 2) {
        auto elem_to_remove = movimientosLvl2.begin();
        eventoTeclas(e, movimientosLvl2[0]);
        movimientosLvl2.erase(elem_to_remove);
    }
    else if (lvl == 2) {
        auto elem_to_remove = movimientosLvl3.begin();
        eventoTeclas(e, movimientosLvl3[0]);
        movimientosLvl3.erase(elem_to_remove);
    }
    else if (lvl == 2) {
        auto elem_to_remove = movimientosLvl4.begin();
        eventoTeclas(e, movimientosLvl4[0]);
        movimientosLvl4.erase(elem_to_remove);
    }
    else if (lvl == 2) {
        auto elem_to_remove = movimientosLvl5.begin();
        eventoTeclas(e, movimientosLvl5[0]);
        movimientosLvl5.erase(elem_to_remove);
    }


    /*switch (lvl)
    {
    case 1:
        auto elem_to_remove1 = movimientosLvl1.begin();
        eventoTeclas(e, movimientosLvl1[0]);
        movimientosLvl1.erase(elem_to_remove1);
        break;
    case 2:
        
        break;
    case 3:
        auto elem_to_remove3 = movimientosLvl3.begin();
        eventoTeclas(e, movimientosLvl3[0]);
        movimientosLvl3.erase(elem_to_remove3);
        break;
    case 4:
        auto elem_to_remove4 = movimientosLvl4.begin();
        eventoTeclas(e, movimientosLvl4[0]);
        movimientosLvl4.erase(elem_to_remove4);
        break;
    case 5:
        auto elem_to_remove5 = movimientosLvl5.begin();
        eventoTeclas(e, movimientosLvl5[0]);
        movimientosLvl5.erase(elem_to_remove5);
        break;
    
    default:
        break;
    }*/

   /* if (movim) {
    auto elem_to_remove = movimientosLvl1.begin();
    eventoTeclas(e, movimientosLvl1[0]);
    movimientosLvl1.erase(elem_to_remove);
    }*/
    
   /* rem
    _Erase_remove(movimientosLvl1, movimientosLvl1[0]);*/

     

         //x.erase(x,x.at(0));
   
    //if (!x.empty()) {
    // cout << "------------------" << x.front();
    ////x.erase();
    //remove(std::remove(x.begin(), x.end(), x.front()),x.end());
   
    //}
   
    //x.at(0);
    //std::chrono::duration<double, std::milli> duration = d;
    //auto duration=100;
         //for (int i = 0; i <x.size();i++) {
         //  
         ////x.erase(x.begin());
         ////sleep(time);
         //
         //}
        //sf::Thread thread(&eventoTeclas,x);
   /* while (x.) {
    
    }
      eventoTeclas(e,x[i]);*/
       
      //int n = x.size();
      //for (int i = 0;i < n;i++) {

      //    cout << x[i] << endl;
      //    
      //    f();
      //    //ventana->resetGLStates();
      //   // void SFML_SYSTEM_API sleep(duration);
      //}


       //ventana->display();
       /*sleep(10); eventoTeclas(e,x[i]);
       sleep(10); eventoTeclas(e,x[i]);
       sleep(10);*/

    //}
}
void AreaJuego::inicializarMovimientosCorrectos() {

    char movs1[] = "SSAASSDWAWDDWDDSSAWDWAWAASSASSDWAWDDAWWDDSSAAWD";
    char movs2[] = "";
    char movs3[] = "";
    char movs4[] = "";
    char movs5[] = "";

    for (int i = 0; i < strlen(movs1);i++) {
        movimientosLvl1.push_back(movs1[i]);
    }
    for (int i = 0; i < strlen(movs2);i++) {
        movimientosLvl2.push_back(movs2[i]);
    }
    for (int i = 0; i < strlen(movs3);i++) {
        movimientosLvl3.push_back(movs3[i]);
    }
    for (int i = 0; i < strlen(movs4);i++) {
        movimientosLvl4.push_back(movs4[i]);
    }
    for (int i = 0; i < strlen(movs5);i++) {
        movimientosLvl5.push_back(movs5[i]);
    }
    
}

void AreaJuego::llenarAutomatico(Event event) {
    /*std::vector<char> moves;
    */
   /* char movimientosLvl2[] = "";
    char movimientosLvl3[] = "";
    char movimientosLvl4[] = "";
    char movimientosLvl5[] = "";*/
    
   /* if (AppContext::getInstance().getNivel() == 1) {
        ejecutarMovimientosAutomaticos(movimientosLvl1, event);
    }else 
        if (AppContext::getInstance().getNivel() == 2) {
            ejecutarMovimientosAutomaticos(movimientosLvl2, event);
        }else
            if (AppContext::getInstance().getNivel() == 3) {
                ejecutarMovimientosAutomaticos(movimientosLvl3, event);
            }else
                if (AppContext::getInstance().getNivel() == 4) {
                    ejecutarMovimientosAutomaticos(movimientosLvl4, event);
                }
                else
                    if (AppContext::getInstance().getNivel() == 5) {
                        ejecutarMovimientosAutomaticos(movimientosLvl5, event);
                    }*/
            
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
    else if (event.key.code == sf::Keyboard::D && movimientoValido('D') || repeticion == 'D' && movimientoValido('D')) {

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
    else if (event.key.code == sf::Keyboard::W && movimientoValido('W') || repeticion == 'W' && movimientoValido('W')) {

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
    else if (event.key.code == sf::Keyboard::S && movimientoValido('S') || repeticion == 'S' && movimientoValido('S')) {

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