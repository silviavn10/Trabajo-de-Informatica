#include "Charcos.h"

Charcos::Charcos() :sprite("bin/imagenes/COVID.png", 1)
{
	lado1 = 3.0f;//lados del charco
	lado2 = 0.2f;//(este en el fondo no se si sobra)
	sprite.setCenter(1.0, 0.2);//Centro sprite
	sprite.setSize(3.0, 0.2);//Tamaño sprite
}

Charcos::~Charcos()
{

}
Charcos::Charcos(float x) :sprite("bin/imagenes/COVID.png", 1)
{
	posicion.x = x;
	posicion.y = 1.75f;
	sprite.setCenter(1.0, 0.2);//Centro sprite
	sprite.setSize(3.0, 0.2);//Tamaño sprite
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