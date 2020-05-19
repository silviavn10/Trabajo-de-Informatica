#include "Probeta.h"

Probeta::Probeta() :sprite("bin/imagenes/COVID.png", 1) //Constructor de la probeta
{
	radio = 2.5f;  //Radio de la probeta
	velocidad.x = 0;  //Velocidad en el sentido negativo del eje horizontal
	//velocidad.y = 8.0f;  //Velocidad nula en el eje vertical CON PONER LA ACELERACION EN LA Y NEGATIVA ES SUFICIENTE
	aceleracion.y = -3.0f;
	posicion.x = 15;
	posicion.y = 7.0f;
	sprite.setCenter(0.5, 0.5);
	sprite.setSize(1, 1);
}


Probeta::~Probeta() //Destructor
{

}

Probeta::Probeta(float x, float y) :sprite("bin/imagenes/COVID.png", 1)
{
	posicion.x = x;
	posicion.y = y;
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

/*void Probeta::Mueve(float t)  //Funcion para que la probeta tenga movimiento
{
	Proyectiles::mueve(t);  //La probeta deriva de proyectiles, por lo que para generar movimiento accede a la funcion mueve de la clase base
	//sprite.loop();
}*/
void Probeta::setPos(float x, float y)  //Función para definir la posición del objeto en el eje horizontal y en el vertical
{
	Proyectiles::setPos(x, y);
	//posicion.x = x;
	//posicion.y = y;
}

float Probeta::getPosX()
{
	return posicion.x;
}