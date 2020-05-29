#include "CharcoCOVID.h"

/*CharcoCOVID::CharcoCOVID() :spriteCOVID("bin/imagenes/charcoverde.png", 1)
{
	lado1 = 3.0f;//lados del charco
	lado2 = 0.2f;//(este en el fondo no se si sobra)
	spriteCOVID.setCenter(1, 1);//Centro sprite
	spriteCOVID.setSize(2, 1);//Tamaño sprite
}*/
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
/*
void CharcoCOVID::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}
float CharcoCOVID::GetPosX()
{
	return posicion.x;
}*/
