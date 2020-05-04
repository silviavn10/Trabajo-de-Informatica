#pragma once
#include "Vector2D.h"
#include <glut.h>
#define MAX_PLATAFORMAS 15//pENDIENTE DE REVISAR
class Plataformas
{
public:
	Plataformas();
	virtual ~Plataformas();
	void Dibuja();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
private:
	float lado;
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	Vector2D posicion;
};

