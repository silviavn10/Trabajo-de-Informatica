#pragma once
#include "Vector2D.h"
#include "Muñeco.h"
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


