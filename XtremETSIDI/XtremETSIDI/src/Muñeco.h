#pragma once
#include "Vector2D.h"
class Mu�eco
{
public:
	Mu�eco();
	virtual ~Mu�eco();
	void Dibuja();
	void Mueve(float);
	Vector2D GetPos();
	void SetVel(float vx, float vy);
	float GetAltura();
private:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	float altura;
	friend class Interaccion;
};

