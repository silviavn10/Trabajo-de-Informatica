#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence; //Vamos a usar sprites

class Creditos
{
public:
	friend class Interaccion;
	Creditos();
	~Creditos();
	Creditos(float x, float y);
	void Mueve(float t);
	void Dibuja();
	void Distancia(Creditos c1, Creditos c2);
	void setcreditos() { activo = &SpriteCreditos; }
	
private:
	float distancia;
	float posicion_z;
	Vector2D velocidad;
	Vector2D posicion;
	Vector2D aceleracion;
	Vector2D limite1;
	float radio;
	SpriteSequence SpriteCreditos;
	SpriteSequence* activo;
};

