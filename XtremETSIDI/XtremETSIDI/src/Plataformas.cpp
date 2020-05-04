#include "Plataformas.h"

Plataformas::Plataformas()
{
	lado = 0.1f;//Pendiente de cambio
	//rojo = 148;
	//verde = 26;
	//azul = 28;
}
Plataformas:: ~Plataformas() 
{

}
void Plataformas::Dibuja() 
{
	glColor3ub(rojo, verde, azul);
	//glRotatef(30, 1, 1, 1); //CAMBIAR POR SI SALE DE LADO
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCube(lado);
	glTranslatef(-posicion.x, -posicion.y, 0);
}


void Plataformas::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}

void Plataformas::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}