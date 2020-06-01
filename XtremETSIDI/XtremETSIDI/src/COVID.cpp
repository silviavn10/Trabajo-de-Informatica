#include "COVID.h"

COVID::COVID() :sprite("bin/imagenes/COVID.png", 1) //Constructor del COVID
{
	velocidad.x = 3.5;  //Velocidad en el eje horizontal
	posicion.x = -8;
	posicion.y = 2.0f;
	sprite.setCenter(7.5, 7.5);
	sprite.setSize(6.5, 6.5);
}
COVID::~COVID() //Destructor
{

}
COVID::COVID(float x, float y) :sprite("bin/imagenes/COVID.png", 1)
{
	posicion.x = x;
	posicion.y = y;
	sprite.setCenter(7.5, 7.5);
	sprite.setSize(6.5, 6.5);
}

void COVID::Dibuja() //Función para dibujar la probeta
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.55);  
	sprite.draw();  
	glPopMatrix();
}

void COVID::mueve()
{
	Proyectiles::mueve(0.025f);
}
