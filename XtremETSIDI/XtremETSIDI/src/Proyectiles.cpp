#include "Proyectiles.h"

Proyectiles::Proyectiles() 
{
	aceleracion.x = 0;
	aceleracion.y = 0;
	velocidad.x = 0;
	velocidad.y = -2.0f;

}
Proyectiles:: ~Proyectiles()
{

}

void Proyectiles::mueve(float t)  //Funcion para definir el movimiento de los proyectiles
{
	posicion = posicion + velocidad * t + aceleracion*(0.5f * t * t);  
	velocidad = velocidad + aceleracion * t;  
}

Vector2D Proyectiles::getPos()  //Función para obtener la posición del objeto, ya que es un atributo protected
{
	return posicion;
}

void Proyectiles::setVel(float vx, float vy)  //Función para definir la velocidad de movimiento, porque es un atributo protected
{
	velocidad.x = vx;  //Velocidad en el eje horizontal
	velocidad.y = vy;  //Velocidad en el eje vertical
}

void Proyectiles::setVel(Vector2D vel)  //Función para definir un vector con las coordenads de la velocidad del objeto en el eje horizontal y en el vertical
{
	velocidad = vel;
}

void Proyectiles::setPos(float x, float y)  //Función para definir la posición del objeto en el eje horizontal y en el vertical
{
	posicion.x = x;
	posicion.y = y;
}

void Proyectiles::setPos(Vector2D pos)  //Función para definir un vector con las coordenads de la posición del objeto en el eje horizontal y en el vertical
{
	posicion = pos;
}