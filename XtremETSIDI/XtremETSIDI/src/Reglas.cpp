#include "Reglas.h"
#include "Probeta.h"

Reglas::Reglas() :sprite("bin/imagenes/COVID.png", 5) //Constructor de la probeta
{
	radio = 2.5f;  //Radio de la probeta
	velocidad.x = 0;  //Velocidad en el sentido negativo del eje horizontal
	//velocidad.y = 8.0f;  //Velocidad nula en el eje vertical CON PONER LA ACELERACION EN LA Y NEGATIVA ES SUFICIENTE
	aceleracion.y = -3.0f;
	posicion.x = 15;
	posicion.y = 7.0f;
	sprite.setCenter(1, 3);
	sprite.setSize(1, 3);
	//setprobetas();
}
Reglas::~Reglas() //Destructor
{

}
Reglas::Reglas(float x, float y) :sprite("bin/imagenes/COVID.png", 5)
{
	posicion.x = x;
	posicion.y = y;
	sprite.setCenter(1, 3);
	sprite.setSize(1, 3);
}

void Reglas::Dibuja() //Función para dibujar la probeta
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion_z);  //Funcion de la libreria glut para trasladar a la probeta las posiciones indicadas
	sprite.draw();  //Se dibuja la probeta, es una funcion interna de los sprites
	glPopMatrix();
	//FALTA QUE LA PROBETA VAYA CAMBIANDO DE DIBUJO CUANDO CAIGA
}
void Reglas::setRadio(float r)  //Funcion para inicializar al radio de la probeta, ya que es un atributo protected
{
	if (r < 0.1F)  //Se asegura de que el radio no pueda ser menor de 0.1, poniendo este valor si lo fuera
		r = 0.1F;
	radio = r;
}
