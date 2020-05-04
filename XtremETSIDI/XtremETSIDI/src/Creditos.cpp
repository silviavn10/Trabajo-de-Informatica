#include "Creditos.h"
#include "ETSIDI.h"
#include "glut.h"


Creditos::Creditos() : SpriteCreditos("imagenes/credito.png", 8) //Constructor
{
	radio = 2.7f; //FALTAN VALORES BUENOS. Radio de la imagen del bonus
	velocidad.x = -15;  //FALTAN VALORES BUENOS. Velocidad horizontal del bonus
	velocidad.y = 0; //FALTAN VALORES BUENOS. Velocidad vertical del bonus
	posicion.x = 8;
	posicion.y = 4.5f;
}

Creditos::~Creditos() //Destructor
{

}

Creditos::Creditos(float rad, float x, float y, float vx, float vy) : SpriteCreditos("imagenes/credito.png", 8) 
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;

	SpriteCreditos.setCenter(0.5, 0.5);  //Centro del sprite para la vida
	SpriteCreditos.setSize(1, 1);  //Tamaño del sprite para la vida
}
