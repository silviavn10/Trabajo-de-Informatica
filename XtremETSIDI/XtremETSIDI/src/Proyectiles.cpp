#include "Proyectiles.h"


void Proyectiles::mueve(float t)  //Funcion para definir el movimiento de los proyectiles
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.y <= 2.8) {
		posicion_z = -0.5; //cuando llegan al suelo se paran y desaparecen
		velocidad.y = 0;
		posicion.y = -5;
		aceleracion.y = 0;
	}
	
}

void Proyectiles::setVel(float vx, float vy)  //Función para definir la velocidad de movimiento, porque es un atributo protected
{
	velocidad.x = vx;  //Velocidad en el eje horizontal
	velocidad.y = vy;  //Velocidad en el eje vertical
}

float Proyectiles::getPosX()
{
	return posicion.x;
}
float Proyectiles::getPosY()
{
	return posicion.y;
}
float Proyectiles::getPosZ()
{
	return posicion_z;
}
void Proyectiles::SetPosZ(float z)
{
	posicion_z = z;
}
void Proyectiles::setPosX(float x)
{
	posicion.x = x;
}