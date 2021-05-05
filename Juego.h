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
	//Eventos
	Event* evento;
	Event* event;		
	Personaje *personaje;
	ImageManager *img_mgr;
	//Textura y sprite del background
	Texture* tex_background;
	Sprite* spr_background;
	
	//Texturas y sprites bloques
	Texture* tex_bloque1;
	Sprite* spr_bloque1;
	Texture* tex_bloque2;
	Sprite* spr_bloque2;
	Texture* tex_bloque3;
	Sprite* spr_bloque3;
	Texture* tex_bloque4;
	Sprite* spr_bloque4;
	Texture* tex_bloque5;
	Sprite* spr_bloque5;
	Texture* tex_bloque6;
	Sprite* spr_bloque6;
	Texture* tex_bloque7;
	Sprite* spr_bloque7;
	Texture* tex_bloque8;
	Sprite* spr_bloque8;
	Texture* tex_bloque9;
	Sprite* spr_bloque9;
	Texture* tex_bloque10;
	Sprite* spr_bloque10;
	
	//Textos
	Font * fuente1;
	Text * txt_tiempo;
		
	//Boleanos que verifican la accion del salto
	bool teclaSaltoPresionada = false; //boleano que verifica si la tecla de salto esta activada
	bool enAscenso = false; //booleano para verificar que el personaje sube
	bool saltoEnProceso = false; //booleano para verificar que el salto esta en proceso
	bool sentidoDerecha = false; //boleano para verificar si va en sentido derecha
};
#endif
