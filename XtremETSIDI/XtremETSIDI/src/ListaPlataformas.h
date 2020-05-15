#pragma once
#include "Plataformas.h"
#include "Muñeco.h"
#define MAX_PLATAFORMAS 10

class ListaPlataformas
{
	public:
	ListaPlataformas();
	~ListaPlataformas();
	void Dibuja();
	void Eliminar(Plataformas* p);
	void Eliminar(int index);
	void DestruirContenido();
	int getNumero() { return numero; };
	bool Agregar(Plataformas* p);
	Plataformas* Colision(Muñeco m);

	//int getNumero() { return numero; }
	Plataformas* operator[] (int index);

private:
	Plataformas* lista[MAX_PLATAFORMAS];
	int numero;
};
