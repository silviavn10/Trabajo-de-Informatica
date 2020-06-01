#include "CharcoCOVID.h"

CharcoCOVID::~CharcoCOVID()
{

}
CharcoCOVID::CharcoCOVID(float x) :spriteCOVID("bin/imagenes/charcoverde.png", 1)
{
	posicion.x = x;
	posicion.y = 2.3f;
	spriteCOVID.setCenter(1, 1);//Centro sprite
	spriteCOVID.setSize(2, 1);//Tamaño sprite
}
void CharcoCOVID::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	spriteCOVID.draw();
	glPopMatrix();
}
