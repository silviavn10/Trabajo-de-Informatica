#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class Reglas : public Proyectiles //DERIVA DE PROYECTILES
{
	friend class Interaccion; 

public:
	
	Reglas();
	~Reglas();
	Reglas(float x, float y);
	void Dibuja();
	void setRadio(float r);
	float getRadio() { return radio; } 
	void mueve();
private:
	SpriteSequence sprite;
	float radio;
	
};