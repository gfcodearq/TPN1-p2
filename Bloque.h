#ifndef BLOQUE_H
#define BLOQUE_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Bloque {
private:
	Sprite *s;
	Texture *t;
	Text text;
	Font fuente;
	int valor;
public:
	Bloque(int pX, int pY, int valorAleatorio) {
		valor = valorAleatorio;
		t = new Texture();
		t->loadFromFile("Recursos\\imagenes\\bloque_pared.png");
		s = new Sprite(*t);
		s->setPosition(pX, pY);
		s->setScale(1.5,1.5);
		fuente.loadFromFile("Recursos\\fuentes\\smbfont.ttf");	
		text.setFont(fuente);
		text.setString(to_string(valor));
		text.setPosition(pX+25,pY+15);
	}
	
	void DrawBloque(RenderWindow *w) {		
		w->draw(*s);
		w->draw(text);
	}
	
	FloatRect ObtenerColisionador() {
		return s->getGlobalBounds();
	}	
	
	int ObtenerValorBloque() {
		return valor;
	}
	
	void SetColor(Color c) {
		text.setColor(c);	
	}
	

	void SetValor(int NewValor)
	{
		text.setString(to_string(NewValor));
	}
	
};
#endif
