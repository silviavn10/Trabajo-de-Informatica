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
	void SetPos(float x1, float y1, float x2, float y2);
	float Distancia(Vector2D punto, Vector2D* direccion = 0);
	float GetLimiteY2() { return limite2.y; };
	friend class Interaccion;

private:
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	Vector2D limite1;
	Vector2D limite2;
};

