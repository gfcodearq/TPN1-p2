#include "Juego.h"
#include <string>
#include <iostream>
#include <ctime>


using namespace std;
using namespace sf;

Juego::Juego(Vector2i resol, string tit)
{
	//Windows
	wnd = new RenderWindow(VideoMode(800, 600), tit);
	wnd->setFramerateLimit(60);
	//Eventos
	evento = new Event;	
	event = new Event;
	reloj = new Clock;
	tiempo = new Time;		
	reloj->restart();//le doy inicio al reloj
	//Sonidos
	buffer = new SoundBuffer;
	buffer_game = new SoundBuffer;
	sonido = new Sound;
	sonido_game = new Sound;
	//Texturas
	img_mgr = new ImageManager(); 	
	Texture tex = img_mgr->getImage("spritesheet.png");
	//Personaje
	personaje = new Personaje(tex);
	get_numeros_aleatorios();
	gameloop();	
}

void Juego::gameloop()
{
	cargar_recursos();	
	sonido_game->setVolume(3);
	sonido_game->play();
	sonido_game->setLoop(true);	
	while (wnd->isOpen())
	{		
		*tiempo = reloj->getElapsedTime(); //obtengo el tiempo que ha pasado
		int tiempoEntero = reloj->getElapsedTime().asSeconds(); //paso a entero el numero del reloj
		txt_tiempo->setString("Tiempo: "+to_string(tiempo1-tiempoEntero));	
		personaje->Actualizar();
		procesar_eventos();		
		personaje->ControlarDesplazamiento();		
		procesar_colisiones();		
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
		spr_bloque[i]->setScale(1.5,1.5);
	}	
	//Cargo la fuente 
	fuente1 = new Font();	
	fuente1->loadFromFile("Recursos/fuentes/smbfont.ttf");		
		
	//Seteo la posicion y contenido del texto
	txt_tiempo = new Text();
	txt_tiempo->setFont(*fuente1);	
	txt_tiempo->setPosition(590,10);
	
	for(int i=0;i<10;i++)
	{
		txt_bloque[i] = new Text();
		txt_bloque[i]->setFont(*fuente1);
		txt_bloque[i]->setString(to_string(numeros[i])); 
	}
	
	//seteo la posicion de los bloques
	int x = 70;
	for (int i = 0; i < 10; i++) {
		spr_bloque[i]->setPosition(x, 200);
		x += 69;
	}	
	
	//Setear posicion texto con respecto al bloque
	x = 95;
	for (int i = 0; i < 10; i++) {
		txt_bloque[i]->setPosition(x, 210);
		x += 68;
	}	
	//Cargar sonidos
	if(!buffer->loadFromFile("Recursos/sonidos/mario-bros-jump.wav"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido->setBuffer(*buffer);
	if(!buffer_game->loadFromFile("Recursos/sonidos/super-mario-bros.wav"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido_game->setBuffer(*buffer_game);
}

//Genara numeros al azar entre 99 y 1
void Juego::get_numeros_aleatorios()
{
	for(int i=0;i<10;i++)
	{
		numeros[i] =  rand() % 99 + 1;
	}
}

//Ordena el arreglo de numeros mediante el metodo burbuja
void Juego::ordenar_numeros()
{
	int aux;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
		{
			if(numeros[j]<numeros[j+1])
			{
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}
}


//Procesa las coliciones entre el personaje y el bloque
void Juego::procesar_colisiones()
{
	for (int i = 0; i < 10; i++) {
		FloatRect box = spr_bloque[i]->getGlobalBounds();
		FloatRect per = personaje->get_sprite().getGlobalBounds();
		if (per.intersects(box))
		{			
			txt_bloque[i]->setColor(Color::Green);
		}			
	}
}

//Procesa eventos 
void Juego::procesar_eventos()
{
	while(wnd->pollEvent(*evento))
	{
		if(evento->type == Event::Closed)
		wnd->close();		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sonido->setVolume(3);
			sonido->play();
		}
	}		
	personaje->ControlarSalto(evento);	
}

