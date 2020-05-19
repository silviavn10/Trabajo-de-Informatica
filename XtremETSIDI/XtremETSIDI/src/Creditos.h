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
	//Creditos(float rad, float x = 0, float y = 0, float vx = 0, float vy = 0);
	//float distancia(Vector2D punto, Vector2D* direccion = 0);
	Creditos(float x, float y);
	void Mueve(float t);
	void Dibuja();
	float posicion_z;
	void Distancia(Creditos c1, Creditos c2);
	float distancia;
	Vector2D velocidad;
	Vector2D posicion;
	Vector2D aceleracion;
	Vector2D limite1;
	//Vector2D limite2;
	float radio;
	SpriteSequence SpriteCreditos;
	SpriteSequence* activo;
	void setcreditos() { activo = &SpriteCreditos; }
};

