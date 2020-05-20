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
	void Dibuja();
	void SetPos(float ix, float iy);
	float GetPosX();

protected:
	float lado1, lado2;
	Vector2D posicion;
private:
	SpriteSequence sprite;
};

