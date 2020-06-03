#pragma once
#include "Plataformas.h"
#include "Muñeco.h"
#include "PlataformaMovil.h"
#include "Interaccion.h"
#define MAX_PLATAFORMAS 35
#define MAX_PLATAFORMASMOVILES 30

class ListaPlataformas
{
	Plataformas** lista;
	int numero;

public:
	ListaPlataformas();
	~ListaPlataformas() {}
	void Dibuja();
	void DestruirContenido();
	void Colision(Muñeco& h);
	void Color(unsigned char r, unsigned char v, unsigned char a);
	void Mueve(float t);
	int getNumero() { return numero; };
	bool Agregar(Plataformas* p);
	bool ListaPlataformas::operator += (Plataformas* p);
	Plataformas* operator[] (int index);
	friend class Nivel;
	friend class NivelCOVID;

	
};