#pragma once
#include"Vector2D.h"
#include "Proyectiles.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;


class Probeta : public Proyectiles //DERIVA DE PROYECTILES
{
	friend class Interaccion; //Interaccion es una clase amiga de Meteorito

public:
	//Métodos
	Probeta();
	Probeta(float rad, float x = 0, float y = 0, float vx = 0, float vy = 0);
	virtual ~Probeta();
	void Mueve(float t);
	void Dibuja();
	void setRadio(float r);
	float getRadio() { return radio; }  //Función para obtener el valor del radio, ya que es un atributo protected


protected:
	//Atributos
	float radio;


private:
	SpriteSequence sprite;
};


