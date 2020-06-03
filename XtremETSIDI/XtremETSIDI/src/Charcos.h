#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Charcos
{
protected:
	Vector2D posicion;
	SpriteSequence sprite;

public:
	Charcos();
	Charcos(float x);
	~Charcos();
	virtual void Dibuja();
	void SetPos(float ix, float iy);
	float GetPosX();

};

