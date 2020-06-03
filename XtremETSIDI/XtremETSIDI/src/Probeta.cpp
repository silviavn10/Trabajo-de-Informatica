#include "Probeta.h"


Probeta::Probeta(float x, float y) :sprite("bin/imagenes/probeta.png", 5)
{
	posicion.x = x;
	posicion.y = y;
	posicion_z = 0.5;
	velocidad.x = 0; 
	aceleracion.y = -2.3f;
	sprite.setCenter(1, 3);
	sprite.setSize(1, 3);
}
Probeta::~Probeta() //Destructor
{

}

void Probeta::Dibuja() //Función para dibujar la probeta
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion_z);  //Funcion de la libreria glut para trasladar a la probeta las posiciones indicadas
	sprite.draw();  //Se dibuja la probeta, es una funcion interna de los sprites
	glPopMatrix();
}

void Probeta::mueve(float t)
{
	Proyectiles::mueve(t);
	sprite.loop();
}