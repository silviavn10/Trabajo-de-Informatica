#pragma once
#include "Vector2D.h"
#include "Muñeco.h"
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
	int nivel;
	//ETSIDI::Sprite Creditos;
	//Proyectiles Proyectiles;//Cuando la hagamos

	//float y_ojo;
	//float z_ojo;
};


