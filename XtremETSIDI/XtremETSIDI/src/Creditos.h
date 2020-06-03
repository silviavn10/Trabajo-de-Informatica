#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence; 

class Creditos
{
	float distancia;
	float posicion_z;
	Vector2D velocidad;
	Vector2D posicion;
	Vector2D aceleracion;
	Vector2D limite1;
	SpriteSequence SpriteCreditos;
	SpriteSequence* activo;

public:

	Creditos(float x, float y);
	~Creditos() {}
	void Mueve(float t);
	void Dibuja();
	void setcreditos() { activo = &SpriteCreditos; }
	friend class Interaccion;

};

