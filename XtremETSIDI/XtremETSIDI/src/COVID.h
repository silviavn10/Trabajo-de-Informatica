#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class COVID : public Proyectiles //DERIVA DE PROYECTILES
{
	friend class Interaccion; //Interaccion es una clase amiga de Meteorito

public:
	COVID();
	~COVID();
	COVID(float x, float y);
	void Dibuja();
	void mueve();
private:
	SpriteSequence sprite;

};

