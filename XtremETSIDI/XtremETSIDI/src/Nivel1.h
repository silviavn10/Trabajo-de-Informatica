#pragma once
#include "Plataformas.h"
#include "Vector2D.h"

class Nivel1
{
public:
	Nivel1();
	virtual ~Nivel1();
	void Dibuja();
	void Mueve(float);
	Vector2D GetPos();
	void SetVel(float vx, float vy);

private: 

};

