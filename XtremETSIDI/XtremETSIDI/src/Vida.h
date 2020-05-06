#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"


class Vida {
public: 
	Vida();
	~Vida();
	void Dibuja();
	Vector2D posicion;
	float getRadio() { return radio; }
	friend class Interaccion;

protected:
	float lado;
};


