#include "Charcos.h"

Charcos::Charcos() :sprite("bin/imagenes/charcoblanco.png", 1)
{
	sprite.setCenter(1, 1);
	sprite.setSize(2, 1);
}
Charcos::~Charcos()
{

}
Charcos::Charcos(float x) :sprite("bin/imagenes/charcoblanco.png", 1)
{
	posicion.x = x;
	posicion.y = 2.3f;
	sprite.setCenter(1, 1);
	sprite.setSize(2, 1);
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