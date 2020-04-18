#include "Creditos.h"
#include "glut.h"

Creditos::Creditos() : sprite_c("imagenes/credito.png", 8) //Constructor
{
	radio = 2.7f; //Radio de la imagen del bonus
	velocidad.x = -15;  //Velocidad horizontal del bonus
	velocidad.y = 0; //Velocidad vertical del bonus
	posicion.x = 8;
	posicion.y = 4.5f;
}

Creditos::~Creditos() //Destructor
{

}

Creditos::Creditos(float rad, float x, float y, float vx, float vy) :sprite_c("imagenes/credito.png", 8) 
	
}