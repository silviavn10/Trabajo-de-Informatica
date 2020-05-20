#pragma once
#include "Vector2D.h"


class Proyectiles //CLASE PADRE
{
public:
	Proyectiles();
	virtual ~Proyectiles();
	virtual void mueve(float t);
	Vector2D getPos();
	void setVel(float vx, float vy);
	void setVel(Vector2D vel);
	void setPos(float x, float y);
	void setPos(Vector2D pos);
	float getPosX();

protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	int NUM_MAX;
};
