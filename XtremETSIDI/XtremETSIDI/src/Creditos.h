#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence; //Vamos a usar sprites

class Creditos
{
public:
	friend class Interaccion;
	Creditos();
	Creditos(float rad, float x = 0, float y = 0, float vx = 0, float vy = 0);
	~Creditos();

protected:
};

