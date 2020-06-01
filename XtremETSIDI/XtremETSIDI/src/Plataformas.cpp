#include "Plataformas.h"
#include"glut.h"

Plataformas::Plataformas()
{

}
Plataformas::Plataformas(float lad, float x, float y)
{
	lado = lad;
	posicion.x = x;
	posicion.y = y;
	
}
Plataformas:: ~Plataformas()
{

}
void Plataformas::Dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidCube(lado);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
void Plataformas::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}

void Plataformas::SetPos(float x1, float y1, float x2, float y2)
{

	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
float Plataformas::distancia(Vector2D punto, Plataformas p, Vector2D* direccion)
{
	Vector2D u = (punto - p.limite1);
	Vector2D v = (p.limite2 - p.limite1).Unitario();
	float longitud = (p.limite1 - p.limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - p.limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0)
		*direccion = dir.Unitario();
	return distancia;
}
