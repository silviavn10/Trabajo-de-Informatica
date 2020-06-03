#include "Reglas.h"
#include "Probeta.h"


Reglas::Reglas(float x, float y) :sprite("bin/imagenes/reglas.png", 5)
{

	velocidad.x = 0;  
	aceleracion.y = -2.3f;
	posicion.x = x;
	posicion.y = y;
	posicion_z = 0.5;
	sprite.setCenter(1, 3);
	sprite.setSize(1, 3);
}
Reglas::~Reglas() //Destructor
{

}

void Reglas::Dibuja() 
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion_z);  
	sprite.draw();  
	glPopMatrix();
}

void Reglas::mueve(float t)
{
	Proyectiles::mueve(t);
	sprite.loop();
}