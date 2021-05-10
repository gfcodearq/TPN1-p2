#pragma once
#include "Afichmation.h"

//DECLARACION DE CONSTANTES
const int POSICION_TERRENO_Y = 500;
const int MAX_ASCENSO_SALTO_Y = 200;

class Personaje 
{
private:
	Afichmation *sprite;
	bool teclaSaltoPresionada = false;
	bool enAscenso = false;
	bool saltoEnProceso = true;
	bool sentidoDerecha = false;
public:
	Personaje(Texture &tex);
	void ControlarDesplazamiento();	
	void ControlarSalto(Event *evento);
	void Dibujar(RenderWindow* w);	
	void Actualizar();		
	Sprite get_sprite();	
};
