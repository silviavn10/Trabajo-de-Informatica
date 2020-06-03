#include "Creditos.h"

Creditos::Creditos(float x, float y) : SpriteCreditos("bin/imagenes/credito.png", 1) 
{
	posicion.x = x;
	posicion.y = y;
	velocidad.y = 2.0f;                  
	posicion_z = 0.5;
	limite1.y = posicion.y;
	aceleracion.y = -9.8f;
	SpriteCreditos.setCenter(1, 0.8);      
	SpriteCreditos.setSize(1, 0.8);       
	setcreditos();
}

void Creditos::Mueve(float t) //Funcion para que el crédito tenga movimiento
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


