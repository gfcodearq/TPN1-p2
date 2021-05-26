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
	buffer_colision = new SoundBuffer;
	sonido = new Sound;
	sonido_game = new Sound;
	sonido_colision = new Sound;
	//Texturas
	img_mgr = new ImageManager(); 	
	Texture tex = img_mgr->getImage("Recursos\\imagenes\\spritesheet.png");
	//Personaje
	personaje = new Personaje(tex);
	game_over = false;	
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
		if (!game_over) {
			*tiempo = reloj->getElapsedTime(); //obtengo el tiempo que ha pasado
			tiempoEntero = reloj->getElapsedTime().asSeconds(); //paso a entero el numero del reloj
			if (tiempo1 - tiempoEntero < 0) {
				game_over = true;
				sonido_game->stop();
			}			
			txt_tiempo->setString("Tiempo: "+to_string(tiempo1-tiempoEntero));//paso a string un valor entero		
			personaje->Actualizar();
			procesar_eventos();		
			personaje->ControlarDesplazamiento();		
			procesar_colisiones();		
		}
		dibujar();
	}
}

void Juego::dibujar()
{
	
	wnd->draw(*spr_background); //Dibuja el sprite del background
	for (int i=0;i<10;i++)
	{
		bloques[i]->DrawBloque(wnd);//Dibuja los bloques en pantalaa
	}
	personaje->Dibujar(wnd);//Dibuja el personaje	
	wnd->draw(*txt_tiempo);	//Dibuja el texto del tiempo
	if(indiceAvanceBusqueda == 10) //si el indice de busqueda alcanza los 10 termina el juego
	{
		game_over = true;
	}
	if (game_over) { //Si es game over dibujo		
		wnd->draw(*txt_game_over);				
		for (int i = 0; i < 10; i++)
		{
			bloques[i]->SetValor(numeros[i]); //cambio el valor del texto por el nuevo ordenado 
		}
	}
	wnd->display(); //Muestra en pantalla todo lo dibujado
}

void Juego::cargar_recursos()	
{
	//Cargo las imagenes a traves del image manager
	img_mgr->addResourceDirectory("Recursos\\imagenes\\");	
	spr_background = new Sprite(img_mgr->getImage("mundo_fondo.jpg"));
	
	//Cargo la fuente 
	fuente1 = new Font();	
	fuente1->loadFromFile("Recursos\\fuentes\\smbfont.ttf");		
		
	//Seteo la posicion y contenido del texto
	txt_tiempo = new Text();
	txt_tiempo->setFont(*fuente1);	
	txt_tiempo->setPosition(590,10);	
	txt_game_over = new Text();
	txt_game_over->setFont(*fuente1);
	txt_game_over->setPosition(330,300);
	txt_game_over->setString("GAME OVER");
	txt_game_over->setCharacterSize(50);
	
	//seteo la posicion de los bloques
	int x = 70;	
	for (int i = 0; i < 10; i++) { 
		numeros[i] =  rand() % 99 + 1; //Genero numero aleatorio
		bloques[i] = new Bloque(x, 200, numeros[i]); //Creo el bloque
		x += 69; //Corro la posicion para la creacion del siguiente bloque
	}
	
	ordenar_numeros();
		
	//Cargar sonidos
	if(!buffer->loadFromFile("Recursos\\sonidos\\mario-bros-jump.wav"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido->setBuffer(*buffer);
	if(!buffer_game->loadFromFile("Recursos\\sonidos\\super-mario-bros.wav"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido_game->setBuffer(*buffer_game);
	if(!buffer_colision->loadFromFile("Recursos\\sonidos\\mario-bros-coin.wav"))
	{
		cout<<"No se pudo cargar efectos"<<endl;
	}
	sonido_colision->setBuffer(*buffer_colision);
}


//Ordena el arreglo de numeros mediante el metodo burbuja
void Juego::ordenar_numeros()
{
	int aux;
	for (int i = 0; i < 10; i++) {
		cout<<numeros[i]<<endl;
	}	
	
	for(int i=0; i<10; i++){
		for(int j=0; j < 9; j++)
		{
			if(numeros[j] > numeros[j+1])
			{
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}	
	for (int i = 0; i < 10; i++) {
		cout<<numeros[i]<<endl;		
	}
}



//Procesa las coliciones entre el personaje y el bloque
void Juego::procesar_colisiones()
{
	Bloque *aux;
	for (int i = 0; i < 10; i++) {
		aux = bloques[i];	
		FloatRect boxColliderMario = personaje->get_sprite().getGlobalBounds();
		boxColliderMario.width *=0.5;
		boxColliderMario.left += boxColliderMario.width * .25f;
		if (boxColliderMario.intersects(aux->ObtenerColisionador())) //Si el personaje intersecta con el bloque
		{
			cout<<aux->ObtenerValorBloque()<<"/"<<numeros[indiceAvanceBusqueda]<<endl;
			if (aux->ObtenerValorBloque() == numeros[indiceAvanceBusqueda]) { //Si el valor del bloque es igual al numero ordenado se pone en verde 
				aux->SetColor(Color::Green);
				sonido_colision->play();				
				indiceAvanceBusqueda++;
			} else {				
				aux->SetColor(Color::Red); //Si el valor del bloque no corresponde al numero ordenado se pone en rojo
				sonido_colision->play();				
				tiempo1 -= 10;				
			}
		}		
	}
}

//Procesa eventos 
void Juego::procesar_eventos()
{
	while(wnd->pollEvent(*evento))
	{
		if(evento->type == Event::Closed) //Evento para cerrar la ventana
		wnd->close();		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //Evento creado para disparar el sonido del personaje cuando salta
		{
			sonido->setVolume(3);
			sonido->play();
		}
	}		
	personaje->ControlarSalto(evento);	
}

