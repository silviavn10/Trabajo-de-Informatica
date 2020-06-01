#include "COVID.h"

COVID::COVID() :sprite("bin/imagenes/COVID.png", 1) //Constructor del COVID
{
	velocidad.x = 4.25;  //Velocidad en el eje horizontal
	posicion.x = -8;
	posicion.y = 2.0f;
	sprite.setCenter(7.5, 7.5);
	sprite.setSize(6.5, 6.5);
}
COVID::~COVID() //Destructor
{

}
COVID::COVID(float x, float y) :sprite("bin/imagenes/COVID.png", 1)
{
	posicion.x = x;
	posicion.y = y;
	sprite.setCenter(7.5, 7.5);
	sprite.setSize(6.5, 6.5);
}

void COVID::Dibuja() //Función para dibujar la probeta
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.55);  //Funcion de la libreria glut para trasladar a la probeta las posiciones indicadas
	sprite.draw();  //Se dibuja la probeta, es una funcion interna de los sprites
	glPopMatrix();
	//FALTA QUE LA PROBETA VAYA CAMBIANDO DE DIBUJO CUANDO CAIGA
}
void COVID::setRadio(float r)  //Funcion para inicializar al radio de la probeta, ya que es un atributo protected
{
	if (r < 0.1F)  //Se asegura de que el radio no pueda ser menor de 0.1, poniendo este valor si lo fuera
		r = 0.1F;
	radio = r;
}
void COVID::mueve()
{
	Proyectiles::mueve(0.025f);
	//sprite.loop();
}
