#pragma once
#include "Vector2D.h"
#include "Mu�eco.h"
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
	Mu�eco mu�eco;
	void setvq() { mu�eco.setvq(); }
	void setfq() { mu�eco.setfq(); }
	void setvd() { mu�eco.setvd(); }
	void setfd() { mu�eco.setfd(); }
	void setve() { mu�eco.setve(); }
	void setfe() { mu�eco.setfe(); }
	void setvm() { mu�eco.setvm(); }
	void setfm() { mu�eco.setfm(); }
	void setva() { mu�eco.setva(); }
	void setfa() { mu�eco.setfa(); }

private:
	float l1;
	float l2;
	float l3;
	float l4;
	//Proyectiles Proyectiles;//Cuando la hagamos

	//float y_ojo;
	//float z_ojo;
};

