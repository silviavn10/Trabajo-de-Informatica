#include "COVID.h"

COVID::COVID() :sprite("bin/imagenes/COVID.png", 1) 
{
	posicion_z = 0.55;
	velocidad.x = 3.5; 
	posicion.x = -8;
	posicion.y = 8.5;
	sprite.setCenter(7.5, 7.5);
	sprite.setSize(6.5, 6.5);

}
COVID::~COVID() //Destructor
{

}

void COVID::Dibuja() //Función para dibujar el COVID
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion_z);  
	sprite.draw();  
	glPopMatrix();
}

void COVID::mueve(float t)
{
	posicion = posicion + velocidad * t; //movimiento rectilineo uniforme
}
