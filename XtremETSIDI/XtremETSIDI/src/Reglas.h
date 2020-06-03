#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class Reglas : public Proyectiles //DERIVA DE PROYECTILES
{
	SpriteSequence sprite;

public:

	Reglas(float x, float y);
	~Reglas();
	void Dibuja();
	void mueve (float t);
	friend class Interaccion;
		
};