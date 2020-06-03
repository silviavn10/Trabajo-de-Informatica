#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class COVID : public Proyectiles //DERIVA DE PROYECTILES
{
	SpriteSequence sprite;

public:

	COVID();
	~COVID();
	void Dibuja();
	void mueve(float t);
	friend class Interaccion;

};

