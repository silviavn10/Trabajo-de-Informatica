#pragma once
#include "Vector2D.h"
#include "Muñeco.h"
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
	bool aux, aux1, aux2, aux3;
	int contador = 0;
	int setvida = 2;
};

