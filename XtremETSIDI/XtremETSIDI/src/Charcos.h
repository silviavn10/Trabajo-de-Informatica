#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Charcos
{
public:
	Charcos();
	~Charcos();
	Charcos(float x);
	virtual void Dibuja();
	void SetPos(float ix, float iy);
	float GetPosX();

protected:
	float lado1;
	Vector2D posicion;
	SpriteSequence sprite;

};

