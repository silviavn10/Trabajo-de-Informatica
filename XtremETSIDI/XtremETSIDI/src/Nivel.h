#pragma once
#include "Vector2D.h"
#include "Mu�eco.h"
#include"Proyectiles.h"
#include "ListaPlataformas.h"
#include "ListaCreditos.h"
#include "ListaProbetas.h"
#include "ListaReglas.h"
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
	int GetContador() { return puntos; }
	int SetVida() { return setvida; }
	void ValorVida(int x) { setvida = x; }
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
	void ActDatos(int puntos);

private:
	float l1;
	float l2;
	float l3;
	float l4;
	bool aux, aux1, aux2, aux3;
	int puntos;
	int setvida;
	int nivel;
	ListaPlataformas ListaPlataformas;
	ListaCreditos ListaCreditos;
	ListaProbetas ListaProbetas;
	ListaCharcos ListaCharcos;
	ListaReglas ListaReglas;
	
};


