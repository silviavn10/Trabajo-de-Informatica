#pragma once
#include "Vector2D.h"
#include "Mu�eco.h"
#include "ListaPlataformas.h"
#include "ListaCreditos.h"
#include "ListaCharcos.h"
#include "COVID.h"
#include "CharcoCOVID.h"
#include"Interaccion.h"

class NivelCOVID
{
	float l1;
	float l2;
	float l3;
	float l4;
	bool aux, aux1, aux2, aux3;
	int setvida = 2;
	int puntos;
	ListaPlataformas ListaPlataformas;
	ListaCreditos ListaCreditos;
	ListaCharcos ListaCharcos;
	COVID COVID;

public:
	NivelCOVID();
	virtual ~NivelCOVID();
	void Inicializa();
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Mueve();
	int SetVida() { return setvida; };
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
	Mu�eco mu�eco;

};

