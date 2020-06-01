#include "Charcos.h"

Charcos::Charcos() :sprite("bin/imagenes/charcoblanco.png", 1)
{
	lado1 = 3.0f;//lados del charco
	sprite.setCenter(1, 1);//Centro sprite
	sprite.setSize(2, 1);//Tamaño sprite
}
Charcos::~Charcos()
{

}
Charcos::Charcos(float x) :sprite("bin/imagenes/charcoblanco.png", 1)
{
	posicion.x = x;
	posicion.y = 2.3f;
	sprite.setCenter(1, 1);//Centro sprite
	sprite.setSize(2, 1);//Tamaño sprite
}
void Charcos::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	sprite.draw();
	glPopMatrix();
}
void Charcos::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}
float Charcos::GetPosX()
{
	return posicion.x;
}