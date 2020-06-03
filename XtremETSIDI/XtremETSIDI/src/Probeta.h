#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class Probeta : public Proyectiles //DERIVA DE PROYECTILES
{
	SpriteSequence sprite;

public:

	Probeta(float x, float y);
	~Probeta();
	void mueve(float t);
	void Dibuja();
	friend class Interaccion; //Probeta es una clase amiga de Interaccion

};



