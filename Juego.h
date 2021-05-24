/*
Antes que nada... los archivos que te voy a eliminar no hacen falta porque son para Visual Studio
asi se reduce el peso de entrega

Que picardía llegar hasta acá y que no me insistas!!! no tenes que tener verguenza ni cosas parecidas
Si, entiendo... pero, mirá se trata de estrategias, si vos te sabes manejar con las estructuras por tu cuenta vas BIEN!

Empiezo! Es un lío controlar los valores si estos se encuentra inconexos con los bloques...
por ende, voy a crear una clase que contenga Sprite + Text vamos!
*/


#ifndef JUEGO_H
#define JUEGO_H

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Animation.h"
#include "Afichmation.h"
#include "Personaje.h"
#include "ImageManager.h"
#include "Bloque.h"

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
	bool game_over();
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
	//Sprite* spr_bloque[10];
	Bloque *bloques[10];
	//Numeros
	int numeros[10];
	//Creacion del reloj y tiempo
	Clock *reloj;
	Time *tiempo;		
	int tiempo1 = 60;
	int tiempoEntero;
	//Textos
	Font * fuente1;
	Text * txt_tiempo;
	Text* txt_bloque[10];	
	Text* txt_game_over;
	//Sonido 
	SoundBuffer* buffer; //Contiene el archivo de sonido
	Sound* sonido; //Sonido va a cargar el buffer
	SoundBuffer* buffer_game;
	Sound *sonido_game;
	SoundBuffer* buffer_colision;
	Sound* sonido_colision;
	SoundBuffer* buffer_game_over;
	Sound* sonido_game_over;
	//Busqueda arreglo
	int indiceAvanceBusqueda = 0;//es para ir pasando por el arreglo ordenado a medida que vas acertando
	
};
#endif
