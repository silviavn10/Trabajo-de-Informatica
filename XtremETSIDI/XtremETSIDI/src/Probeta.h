#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class Probeta : public Proyectiles //DERIVA DE PROYECTILES
{
	friend class Interaccion; //Interaccion es una clase amiga de Meteorito

public:
	//M�todos
	Probeta();
	//Probeta(float rad, float x = 0, float y = 0, float vx = 0, float vy = 0);
	~Probeta();
	Probeta(float x, float y);
	//void Mueve(float t);
	void Dibuja();
	//float getPosX();
	//void setPos(float x, float y);
	void setRadio(float r);
	float getRadio() { return radio; }  //Funci�n para obtener el valor del radio, ya que es un atributo protected
private:
	SpriteSequence sprite;
	float radio;
};



