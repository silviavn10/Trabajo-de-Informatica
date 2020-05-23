#pragma once
#include "Vector2D.h"
#include "Mu�eco.h"
#include "Suelo.h"
#include"Proyectiles.h"
#include "ListaPlataformas.h"
#include "ListaCreditos.h"
#include "ListaProbetas.h"
#include "ListaCharcos.h"
#include"Interaccion.h"

class Nivel
{
public:
	Nivel();
	~Nivel();
	void Inicializa();
	void Inicializa2();
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Mueve();
	Vector2D GetPos();
	int GetContador() { return contador; };
	//void SetVel(float vx, float vy);
	int SetVida() { return setvida; };
	ListaPlataformas ListaPlataformas;
	ListaCreditos ListaCreditos;
	ListaProbetas ListaProbetas;
	ListaCharcos ListaCharcos;
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
	bool aux, aux1, aux2, aux3;
	int contador = 0;
	int setvida = 2;
	int nivel;
	//ETSIDI::Sprite Creditos;
	//Proyectiles Proyectiles;//Cuando la hagamos

	//float y_ojo;
	//float z_ojo;
};


