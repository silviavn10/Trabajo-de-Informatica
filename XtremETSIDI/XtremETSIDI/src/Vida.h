#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"


class Vida {
public:
	Vida();
	~Vida();
	void Dibuja();
	void Dibuja2();
	friend class Interaccion;
	float GetMov(float x);

private:
	float Mov;
};


