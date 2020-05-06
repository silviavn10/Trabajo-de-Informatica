#pragma once
//#include "glut.h"
#include "Vector2D.h"

class Suelo
{
public:
	Suelo();
	virtual ~Suelo();
	void Dibuja();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float x1 = -10.0f, float y1 = 1.25f, float x2 = 10.0f, float y2 = 1.25f); //Cambiar valores
	float distancia(Vector2D punto, Vector2D* direccion=0);
	friend class Interaccion;

private:
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	Vector2D limite1;
	Vector2D limite2;
};

