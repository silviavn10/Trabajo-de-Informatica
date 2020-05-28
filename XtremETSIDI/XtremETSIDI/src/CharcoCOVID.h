#pragma once
#include "Vector2D.h"
#include "Charcos.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class CharcoCOVID  : public Charcos		//Hereda de charcos 
{
public:
	CharcoCOVID();
	~CharcoCOVID();
	CharcoCOVID(float x);
	void Dibuja();
	//void SetPos(float ix, float iy);
	//float GetPosX();

private:
	float lado1, lado2;
	Vector2D posicion;
	SpriteSequence sprite;

};
