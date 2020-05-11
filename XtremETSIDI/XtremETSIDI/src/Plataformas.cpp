#include "Plataformas.h"
#include"glut.h"

Plataformas::Plataformas()
{
	lado = 1.50f;
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
	limite1.x = posicion.x - (lado / 2);
	limite1.y = posicion.y + (lado / 2);
	limite2.x = posicion.x + (lado / 2);
	limite2.y = posicion.y + (lado / 2);
}
float Plataformas::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).Unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0)
		*direccion = dir.Unitario();
	return distancia;
}