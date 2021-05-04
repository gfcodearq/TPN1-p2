#include "Juego.h"

using namespace std;
using namespace sf;

Juego::Juego(Vector2i resol, string tit)
{
	wnd = new RenderWindow(VideoMode(800, 600), tit);
	wnd->setFramerateLimit(60);		
	evento = new Event;	
	event = new Event;
	gameloop();
}

void Juego::gameloop()
{
	cargar_recursos();	
	while (wnd->isOpen())
	{
		
		procesar_eventos();		
		dibujar();
	}
}

void Juego::dibujar()
{
	wnd->clear(Color(255,255,255,255));	
	wnd->draw(*spr_background);
	wnd->draw(*spr_bloque);
	wnd->draw(*anim);
	wnd->display();
}

void Juego::cargar_recursos()	
{
	//Carga el fondo 
	tex_background = new Texture;
	tex_background->loadFromFile("mundo_fondo.jpg");
	spr_background = new Sprite;
	spr_background->setTexture(*tex_background);
	
	//Cargar bloque
	tex_bloque = new Texture;
	tex_bloque->loadFromFile("bloque_pared.png");
	spr_bloque = new Sprite;
	spr_bloque->setTexture(*tex_bloque);
	spr_bloque->setPosition(300,180);
	
	personaje = new Personaje(tex);
	anim = new Afichmation ("spritesheet.png", true, 208, 249); 
	//Afichmation anim("spritesheet.png", true, 26, 30);
	anim->Add("idle", {0, 1, 2, 1, 0}, 8, true);
	anim->Add("run", {3, 4, 5, 4}, 8, true);
	anim->Add("falls of", {6}, 8, true);
	anim->Add("stairs", {7, 8}, 8, true);
	anim->Add("jump", { 12,13, 14 }, 8, true);
	anim->Add("collide", { 15 }, 8, false);	
	anim->Play("idle");	
	anim->setScale(Vector2f(.5f, .5f));
	anim->setPosition(50,460);
}
