#pragma once
#include "Vector2D.h"
//#include "glut.h"
#define MAX_PLATAFORMAS 15//pENDIENTE DE REVISAR
class Plataformas
{
public:
	Plataformas();
   ~Plataformas();
	void Dibuja();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	float GetLimiteY2() { return limite2.y; };

private:
	float lado;
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	Vector2D posicion;
	Vector2D limite1;
	Vector2D limite2;
};

