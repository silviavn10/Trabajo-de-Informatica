/*#include "Probeta.h"
#include "glut.h"

Probeta::Probeta() :sprite("bin/imagenes/probeta.png", 5) //Constructor de la probeta
{
	radio = 0.5f;  //Radio de la probeta
	velocidad.x = 0;  //Velocidad en el eje horizontal
	velocidad.y = -10;  //Velocidad en el eje vertical
	//posicion.x = 8;
	//posicion.y = 4.5f;
	sprite.setCenter(0.10, 0.05);
	sprite.setSize(0.34, 0.1);
}

Probeta::~Probeta() //Destructor
{

}

/*Probeta::Probeta(float rad, float x, float y, float vx, float vy) :sprite("bin/imagenes/probeta.png", 5)//Constructor con sus parámetros
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	sprite.setCenter(0.10, 0.05);
	sprite.setSize(0.34, 0.1);
}


void Probeta::Dibuja() //Función para dibujar la probeta
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);  //Funcion de la libreria glut para trasladar a la probeta las posiciones indicadas
	activo->draw(); //Se dibuja la probeta, es una funcion interna de los sprites
	glPopMatrix();
}


void Probeta::setRadio(float r)  //Funcion para inicializar al radio de la probeta, ya que es un atributo protected
{
	if (r < 0.1F)  //Se asegura de que el radio no pueda ser menor de 0.1, poniendo este valor si lo fuera
		r = 0.1F;
	radio = r;
}

void Probeta::SetPos(float ix, float iy)  //Función para determinar la posición del misil nuevo
{
	Proyectiles::SetPos(ix, iy);  //Se llama a la función de determinar la posición en el ObjetoMovil
	origen = posicion;
} 

void Probeta::Mueve(float t)  //Funcion para que la probeta tenga movimiento
{
	Proyectiles::mueve(t);  //La probeta deriva de proyectiles, por lo que para generar movimiento accede a la funcion mueve de la clase base
	sprite.loop();
}
*/
