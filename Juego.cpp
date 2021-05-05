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
//	for (int i=1;i<=10;i++)
//	{
//		wnd->draw(*spr_bloque1);
//	}
//		
	wnd->draw(*spr_bloque1);
	wnd->draw(*spr_bloque2);
	wnd->draw(*spr_bloque3);
	wnd->draw(*spr_bloque4);
	wnd->draw(*spr_bloque5);
	wnd->draw(*spr_bloque6);
	wnd->draw(*spr_bloque7);
	wnd->draw(*spr_bloque8);
	wnd->draw(*spr_bloque9);
	wnd->draw(*spr_bloque10);
	wnd->draw(*txt_tiempo);
	
	personaje->Dibujar(wnd);
	wnd->display();
}

void Juego::cargar_recursos()	
{
	img_mgr->addResourceDirectory("Recursos/imagenes/");	
	spr_background = new Sprite(img_mgr->getImage("mundo_fondo.jpg"));
	//crear un bucle for que dibuje todos los bloques
	spr_bloque1 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque1->setPosition(200,180);	
	spr_bloque2 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque2->setPosition(245,180);	
	spr_bloque3 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque3->setPosition(290,180);	
	spr_bloque4 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque4->setPosition(335,180);	
	spr_bloque5 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque5->setPosition(380,180);	
	spr_bloque6 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque6->setPosition(425,180);	
	spr_bloque7 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque7->setPosition(470,180);	
	spr_bloque8 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque8->setPosition(515,180);	
	spr_bloque9 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque9->setPosition(560,180);	
	spr_bloque10 = new Sprite(img_mgr->getImage("bloque_pared.png"));	
	spr_bloque10->setPosition(155,180);	
	
	fuente1 = new Font();
	fuente1->loadFromFile("Recursos/fuentes/smbfont.ttf");	
	
	txt_tiempo = new Text();
	txt_tiempo->setFont(*fuente1);
	txt_tiempo->setString("Tiempo: ");
	txt_tiempo->setPosition(590,10);
	
	
}


