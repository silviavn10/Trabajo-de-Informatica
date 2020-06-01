#include "Reglas.h"
#include "Probeta.h"

Reglas::Reglas() :sprite("bin/imagenes/reglas.png", 5) 
{
	radio = 2.5f; 
	velocidad.x = 0;  //Velocidad en el sentido negativo del eje horizontal
	aceleracion.y = -3.0f;
	posicion.x = 15;
	posicion.y = 7.0f;
	sprite.setCenter(1, 3);
	sprite.setSize(1, 3);
}
Reglas::~Reglas() //Destructor
{

}
Reglas::Reglas(float x, float y) :sprite("bin/imagenes/reglas.png", 5)
{
	posicion.x = x;
	posicion.y = y;
	sprite.setCenter(1, 3);
	sprite.setSize(1, 3);
}

void Reglas::Dibuja() 
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion_z);  //Funcion de la libreria glut para trasladar a la probeta las posiciones indicadas
	sprite.draw();  
	glPopMatrix();
}
void Reglas::setRadio(float r)  
{
	if (r < 0.1F)  
		r = 0.1F;
	radio = r;
}
void Reglas::mueve()
{
	Proyectiles::mueve(0.025f);
	sprite.loop();
}