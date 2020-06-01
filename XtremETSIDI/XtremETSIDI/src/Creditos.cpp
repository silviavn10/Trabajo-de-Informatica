#include "Creditos.h"
#include "ETSIDI.h"

Creditos::Creditos(float x, float y) : SpriteCreditos("bin/imagenes/credito.png", 1) //Constructor
{
	posicion.x = x;
	posicion.y = y;
	radio = 1.5f; //Radio de la imagen del bonus
	velocidad.y = 2.0f; //Velocidad vertical del bonus
	posicion_z = 0.5;
	limite1.y = posicion.y;
	aceleracion.y = -9.8f;
	SpriteCreditos.setCenter(1, 0.8);  //Centro del sprite para el mu�eco vq 
	SpriteCreditos.setSize(1, 0.8);  //Tama�o del sprite para el mu�eco vq
	setcreditos();
}
Creditos::~Creditos() //Destructor
{

}
void Creditos::Mueve(float t) //Funcion para que el cr�dito tenga movimiento
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.y < limite1.y) {
		posicion.y = limite1.y;
		velocidad.y = 2;
	}
}

void Creditos::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion_z);
	activo->draw();
	glPopMatrix();
}
void Creditos::Distancia(Creditos c1, Creditos c2) {

	distancia = c1.posicion.x - c2.posicion.x;
	if (distancia < 0) { distancia = distancia * (-1); }
}

