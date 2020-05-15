#include "Probeta.h"

Probeta::Probeta() :sprite("bin/imagenes/SpriteMeteorito.png", 1) //Constructor de la probeta
{
	radio = 2.5f;  //Radio de la probeta
	velocidad.x = -15;  //Velocidad en el sentido negativo del eje horizontal
	velocidad.y = 0;  //Velocidad nula en el eje vertical
	posicion.x = 8;
	posicion.y = 4.5f;
}


Probeta::~Probeta() //Destructor
{

}


Probeta::Probeta(float rad, float x, float y, float vx, float vy) :sprite("bin/imagenes/SpriteMeteorito.png", 1)//Constructor con sus parámetros
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	sprite.setCenter(0.5, 0.5);
	sprite.setSize(1, 1);
}


void Probeta::Dibuja() //Función para dibujar la probeta
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);  //Funcion de la libreria glut para trasladar a la probeta las posiciones indicadas
	sprite.draw();  //Se dibuja la probeta, es una funcion interna de los sprites
	glPopMatrix();
}


void Probeta::setRadio(float r)  //Funcion para inicializar al radio de la probeta, ya que es un atributo protected
{
	if (r < 0.1F)  //Se asegura de que el radio no pueda ser menor de 0.1, poniendo este valor si lo fuera
		r = 0.1F;
	radio = r;
}

void Probeta::Mueve(float t)  //Funcion para que la probeta tenga movimiento
{
	Proyectiles::mueve(t);  //La probeta deriva de proyectiles, por lo que para generar movimiento accede a la funcion mueve de la clase base
	sprite.loop();
}