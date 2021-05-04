#ifndef JUEGO_H
#define JUEGO_H

#include "SFML\Graphics.hpp"
#include "Animation.h"
#include "Afichmation.h"
#include "Personaje.h"
#include "ImageManager.h"

using namespace sf;
using namespace std;

class Juego
{
public:
	Juego(Vector2i resol, string titulo);
	void gameloop();
	void procesar_eventos();
	void cargar_recursos();
	void dibujar();	
	void controlar_salto(Event *event);
	void controlar_desplazamiento();
private:
	RenderWindow* wnd;
	Event* evento;
	Event* event;
	Afichmation* anim;	
	Personaje *personaje;
	ImageManager *img_mgr;
	Texture* tex_background;
	Sprite* spr_background;
	Texture* tex_bloque;
	Sprite* spr_bloque;
	bool teclaSaltoPresionada = false; //boleano que verifica si la tecla de salto esta activada
	bool enAscenso = false; //booleano para verificar que el personaje sube
	bool saltoEnProceso = false; //booleano para verificar que el salto esta en proceso
	bool sentidoDerecha = false; //boleano para verificar si va en sentido derecha
};
#endif
