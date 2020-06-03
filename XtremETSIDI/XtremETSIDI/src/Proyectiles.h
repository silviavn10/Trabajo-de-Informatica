#pragma once
#include "Vector2D.h"


class Proyectiles //CLASE PADRE
{

protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	float posicion_z;

public:
	Proyectiles() {}
	virtual ~Proyectiles() {}
	virtual void mueve(float t);
	void setVel(float vx, float vy);
	void setPosX(float x);
	void SetPosZ(float z);
	float getPosX();
	float getPosY();
	float getPosZ();
	virtual void Dibuja() = 0 {}  // Funcion virtual pura

};
