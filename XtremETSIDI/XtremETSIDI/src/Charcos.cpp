#include "Charcos.h"

Charcos::Charcos() :sprite("bin/imagenes/CHARCO.png", 1)
{
	lado1 = 3.0f;//lados del charco
	lado2 = 0.2f;//(este en el fondo no se si sobra)
	sprite.setCenter(3, 1);//Centro sprite
	sprite.setSize(3, 1);//Tama�o sprite
}

Charcos::~Charcos()
{

}
Charcos::Charcos(float x) :sprite("bin/imagenes/CHARCO.png", 1)
{
	posicion.x = x;
	posicion.y = 2.5f;
	sprite.setCenter(3, 1);//Centro sprite
	sprite.setSize(3, 1);//Tama�o sprite
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