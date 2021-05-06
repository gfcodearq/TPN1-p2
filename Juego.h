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
	//Textura y sprite del bloque
	Texture* tex_bloque[9];
	Sprite* spr_bloque[9];
	
	//Textos
	Font * fuente1;
	Text * txt_tiempo;
	Text* txt_bloque[9];	
	//Boleanos que verifican la accion del salto
	bool teclaSaltoPresionada = false; //boleano que verifica si la tecla de salto esta activada
	bool enAscenso = false; //booleano para verificar que el personaje sube
	bool saltoEnProceso = false; //booleano para verificar que el salto esta en proceso
	bool sentidoDerecha = false; //boleano para verificar si va en sentido derecha
};
#endif
