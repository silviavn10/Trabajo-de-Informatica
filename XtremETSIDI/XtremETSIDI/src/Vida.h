#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"


class Vida {
public:
	Vida();
	~Vida();
	void Dibuja();
	void Dibuja2();
	//float getRadio() { return radio; }
	//void SetPos(float x1, float y1);
	friend class Interaccion;
	float Mov;
	float GetMov(float x);

protected:
	//float radio;
	//Vector2D posicion;
};


