#pragma once
#include "Vector2D.h"

class Plataformas
{
protected:
	Vector2D posicion;
	Vector2D limite1;
	Vector2D limite2;
	float lado;

public:

	Plataformas();
	Plataformas(float lad, float x = 0.0f, float y = 0.0f);
	~Plataformas();
	void Dibuja();
	void SetPos(float x1, float y1, float x2, float y2);
	void SetLado(float l) { lado = l; }
	void SetPos(Vector2D pos) { posicion = pos; }
	void SetLimite1(Vector2D lim) { limite1 = lim; }
	void SetLimite2(Vector2D lim) { limite2 = lim; }
	void SetPosX(float x) { posicion.x = x; }
	void SetPosY(float y) { posicion.y = y; }
	void virtual Mueve(float t) {}
	void virtual SetColor(unsigned char r, unsigned char v, unsigned char a);
	float distancia(Vector2D punto, Plataformas p, Vector2D* direccion = 0);
	float GetLimiteY2() { return limite2.y; };
	float GetLimiteY1() { return limite1.y; };
	float GetLimiteX2() { return limite2.x; };
	float GetLimiteX1() { return limite1.x; };
	float GetLado() { return lado; }
	float GetPosX() { return posicion.x; }
	float GetPosY() { return posicion.y; }
	Vector2D GetPos() { return posicion; }
	Vector2D GetLimite1() { return limite1; }
	Vector2D GetLimite2() { return limite2; }
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
};

