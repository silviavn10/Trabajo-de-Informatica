#pragma once
#include "Plataformas.h"
#include "Vector2D.h"
#include "Muñeco.h"
#include "Creditos.h"
#include "Vida.h"
#include "Interaccion.h"
class Nivel1
{
public:
	Nivel1();
	virtual ~Nivel1();
	void Inicializa();
	void Dibuja();
	void Mueve(float);
	Vector2D GetPos();
	void SetVel(float vx, float vy);
	
	

private: 
	Plataformas Plataforma;
	Muñeco Muñeco;
	Creditos Creditos;
	//Proyectiles Proyectiles//Cuando la hagamos
	Vida Vida;
	Interaccion Interaccion;
	float x_ojo;
	float y_ojo;
	float z_ojo;
};

