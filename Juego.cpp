#include "Juego.h"


using namespace std;
using namespace sf;

Juego::Juego(Vector2i resol, string tit)
{
	wnd = new RenderWindow(VideoMode(800, 600), tit);
	wnd->setFramerateLimit(60);		
	evento = new Event;	
	event = new Event;
	
	img_mgr = new ImageManager();
	cargar_recursos();	
	Texture tex = img_mgr->getImage("spritesheet.png");	
	personaje = new Personaje(tex);
	gameloop();
}

void Juego::gameloop()
{
	while (wnd->isOpen())
	{	
		personaje->ControlarSalto(event);
		personaje->ControlarDesplazamiento();
		personaje->Actualizar();		
		dibujar();
	}
}

void Juego::dibujar()
{
	wnd->clear(Color(255,255,255,255));	
	wnd->draw(*spr_background);
	for (int i=0;i<9;i++)
	{
		wnd->draw(*spr_bloque[i]);
	}
	personaje->Dibujar(wnd);
	wnd->display();
}

void Juego::cargar_recursos()	
{
	img_mgr->addResourceDirectory("Recursos/imagenes/");	
	spr_background = new Sprite(img_mgr->getImage("mundo_fondo.jpg"));
	
	//bucle for que dibuje todos los bloques	
	for(int i=0;i<9;i++)
	{
		spr_bloque[i] = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	}
	
	fuente1 = new Font();
	fuente1->loadFromFile("Recursos/fuentes/smbfont.ttf");	
	
	txt_tiempo = new Text();
	txt_tiempo->setFont(*fuente1);
	txt_tiempo->setString("Tiempo: ");
	txt_tiempo->setPosition(590,10);
	
	
}


