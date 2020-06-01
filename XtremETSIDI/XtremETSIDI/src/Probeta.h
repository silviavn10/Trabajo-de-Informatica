#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class Probeta : public Proyectiles //DERIVA DE PROYECTILES
{
	friend class Interaccion; //Interaccion es una clase amiga de Meteorito

public:
	Probeta();
	~Probeta();
	Probeta(float x, float y);
	void Dibuja();
	void setRadio(float r);
	float getRadio() { return radio; }  
	void Probeta::mueve();
private:
	SpriteSequence sprite;
	float radio;
	
};



