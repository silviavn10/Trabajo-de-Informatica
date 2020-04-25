/*#pragma once
#include "Vector2D.h"
#include "Menu.h"

class Muñeco
{
public:
	Muñeco();
	virtual ~Muñeco();
	void Dibuja();
	void Mueve(float);
	Vector2D GetPos();
	void SetVel(float vx, float vy);
	float GetAltura();
	int sexo();

private:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	float altura;
	int sexo;
	unsigned char carrera;
	friend class Interaccion;
};
*/