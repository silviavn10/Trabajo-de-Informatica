#pragma once
#include "Vector2D.h"
#include "Muñeco.h"
#include "Creditos.h"
#include "Suelo.h"
#include"Proyectiles.h"
#include "ListaPlataformas.h"
#include"Interaccion.h"

class Nivel
{
public:
	Nivel();
	~Nivel();
	void Inicializa(Suelo &s, Creditos &c, Proyectiles &pro, Vida &v);
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Mueve(Muñeco & muñeco);
	Vector2D GetPos();
	//void SetVel(float vx, float vy);
	ListaPlataformas ListaPlataformas;
	//Creditos Creditos;

	//Proyectiles Proyectiles;//Cuando la hagamos

	//float y_ojo;
	//float z_ojo;
};

