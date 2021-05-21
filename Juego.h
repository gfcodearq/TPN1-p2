#ifndef JUEGO_H
#define JUEGO_H

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
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
	void get_numeros_aleatorios();
	void ordenar_numeros();
	void ordenar_bloques();
	void mostrar_pantalla_numeros();
	void procesar_colisiones();	
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
	Texture* tex_bloque[10];
	Sprite* spr_bloque[10];
	//Numeros
	int numeros[10];
	//Creacion del reloj y tiempo
	Clock *reloj;
	Time *tiempo;		
	int tiempo1 = 60;
	//Textos
	Font * fuente1;
	Text * txt_tiempo;
	Text* txt_bloque[10];	
	//Sonido 
	SoundBuffer* buffer; //Contiene el archivo de sonido
	Sound* sonido; //Sonido va a cargar el buffer
	SoundBuffer* buffer_game;
	Sound *sonido_game;
};
#endif
