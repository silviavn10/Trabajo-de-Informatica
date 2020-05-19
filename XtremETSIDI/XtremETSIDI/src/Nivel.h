#pragma once
#include "Vector2D.h"
#include "Muñeco.h"
#include "Suelo.h"
#include"Proyectiles.h"
#include "ListaPlataformas.h"
#include "ListaCreditos.h"
#include"Interaccion.h"

class Nivel
{
public:
	Nivel();
	~Nivel();
	void Inicializa(Suelo &s, Creditos &c, Proyectiles &pro, Vida &v);
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Mueve();
	Vector2D GetPos();
	//void SetVel(float vx, float vy);
	ListaPlataformas ListaPlataformas;
	ListaCreditos ListaCreditos;
	Muñeco muñeco;
	void setvq() { muñeco.setvq(); }
	void setfq() { muñeco.setfq(); }
	void setvd() { muñeco.setvd(); }
	void setfd() { muñeco.setfd(); }
	void setve() { muñeco.setve(); }
	void setfe() { muñeco.setfe(); }
	void setvm() { muñeco.setvm(); }
	void setfm() { muñeco.setfm(); }
	void setva() { muñeco.setva(); }
	void setfa() { muñeco.setfa(); }

private:
	float l1;
	float l2;
	float l3;
	float l4;
	//Proyectiles Proyectiles;//Cuando la hagamos

	//float y_ojo;
	//float z_ojo;
};

