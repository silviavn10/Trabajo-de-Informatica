#pragma once
#include "Vector2D.h"
#include "Charcos.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class CharcoCOVID  : public Charcos		//Hereda de charcos 
{
public:
	~CharcoCOVID();
	CharcoCOVID(float x);
	void Dibuja();
private:
	SpriteSequence spriteCOVID;

};
