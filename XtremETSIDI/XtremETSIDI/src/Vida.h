#pragma once
#include "ETSIDI.h"

class Vida {

	float Mov;

public:
	Vida();
	~Vida();
	void Dibuja();
	void Dibuja2();
	float GetMov(float x);
	friend class Interaccion;

};


