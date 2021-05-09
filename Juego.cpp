#include "Juego.h"
#include <string>
#include <iostream>
#include <ctime>


using namespace std;
using namespace sf;

Juego::Juego(Vector2i resol, string tit)
{
	wnd = new RenderWindow(VideoMode(800, 600), tit);
	wnd->setFramerateLimit(60);		
	evento = new Event;	
	event = new Event;
	reloj = new Clock;
	tiempo = new Time;	
	img_mgr = new ImageManager(); 	
	Texture tex = img_mgr->getImage("spritesheet.png");	
	personaje = new Personaje(tex);
	gameloop();
}

void Juego::gameloop()
{
	cargar_recursos();		
	while (wnd->isOpen())
	{			
		*tiempo = reloj->getElapsedTime(); //inicio el reloj		
		cout<<tiempo->asSeconds();
		reloj->restart();
		personaje->ControlarDesplazamiento();	
		personaje->Actualizar();					
		procesar_eventos();		
		personaje->ControlarSalto(event);
		/*procesar_colisiones();*/
		dibujar();
	}
}

void Juego::dibujar()
{
	wnd->clear(Color(255,255,255,255));	
	wnd->draw(*spr_background);
	for (int i=0;i<10;i++)
	{
		wnd->draw(*spr_bloque[i]);
		wnd->draw(*txt_bloque[i]);
	}
	personaje->Dibujar(wnd);	
	wnd->draw(*txt_tiempo);	
	wnd->display();
}

void Juego::cargar_recursos()	
{
	img_mgr->addResourceDirectory("Recursos/imagenes/");	
	spr_background = new Sprite(img_mgr->getImage("mundo_fondo.jpg"));
	
	//bucle for que dibuje todos los bloques	
	for(int i=0;i<10;i++)
	{
		spr_bloque[i] = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	}
	
	//Cargo la fuente 
	fuente1 = new Font();	
	fuente1->loadFromFile("Recursos/fuentes/smbfont.ttf");		
		
	//Seteo la posicion y contenido del texto
	txt_tiempo = new Text();
	txt_tiempo->setFont(*fuente1);
	txt_tiempo->setString("Tiempo: "+to_string(tiempo->asSeconds()));
	txt_tiempo->setPosition(590,10);
	
	for(int i=0;i<10;i++)
	{
	txt_bloque[i] = new Text();
	txt_bloque[i]->setFont(*fuente1);
	txt_bloque[i]->setString(to_string(numeros[i])); //imprime el espacio de memoria 	
	}
	
	//seteo la posicion de los bloques
	spr_bloque[0]->setPosition(155,180);
	spr_bloque[1]->setPosition(200,180);
	spr_bloque[2]->setPosition(245,180);
	spr_bloque[3]->setPosition(290,180);
	spr_bloque[4]->setPosition(335,180);
	spr_bloque[5]->setPosition(380,180);
	spr_bloque[6]->setPosition(425,180);
	spr_bloque[7]->setPosition(470,180);
	spr_bloque[8]->setPosition(515,180);
	spr_bloque[9]->setPosition(560,180);
	
	//Setear posicion texto con respecto al bloque	
	txt_bloque[0]->setPosition(177,180);
	txt_bloque[1]->setPosition(222,180);
	txt_bloque[2]->setPosition(267,180);
	txt_bloque[3]->setPosition(312,180);
	txt_bloque[4]->setPosition(357,180);
	txt_bloque[5]->setPosition(402,180);
	txt_bloque[6]->setPosition(447,180);
	txt_bloque[7]->setPosition(492,180);
	txt_bloque[8]->setPosition(537,180);
	txt_bloque[9]->setPosition(582,180);
	
}

void Juego::get_numeros_aleatorios()
{
	for(int i=0;i<10;i++)
	{
		numeros[i] =  rand() % 999 + 1;
	}
}


void Juego::procesar_colisiones()
{
	FloatRect box = spr_bloque[10]->getGlobalBounds();
	if(personaje->get_sprite().getGlobalBounds().intersects(box));
	{
		txt_bloque[10]->scale(2,2);
	}
}


void Juego::procesar_eventos()
{
	while(wnd->pollEvent(*evento))
	{
		if(evento->type == Event::Closed)
		wnd->close();
	}	
	
}

