#pragma once
#include "Vector2D.h"
#include "Charcos.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class CharcoCOVID  : public Charcos		//Hereda de charcos 
{
	SpriteSequence spriteCOVID;

public:
	~CharcoCOVID();
	CharcoCOVID(float x);
	void Dibuja();

};
