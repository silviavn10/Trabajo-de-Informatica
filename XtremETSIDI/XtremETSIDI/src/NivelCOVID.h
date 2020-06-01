#pragma once
#include "Vector2D.h"
#include "Mu�eco.h"
#include "ListaPlataformas.h"
#include "ListaCreditos.h"
#include "ListaCharcos.h"
#include "COVID.h"
#include"Interaccion.h"

class NivelCOVID
{
public:
	NivelCOVID();
	virtual ~NivelCOVID();
	void Inicializa();
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Mueve();
	Vector2D GetPos();
	int GetContador() { return contador; };
	int SetVida() { return setvida; };
	ListaPlataformas ListaPlataformas;
	ListaCreditos ListaCreditos;
	ListaCharcos ListaCharcos;
	COVID COVID;
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
};

