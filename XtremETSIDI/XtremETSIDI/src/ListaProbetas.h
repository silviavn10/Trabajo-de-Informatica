#pragma once
#define MAX_PROBETAS 24
#include"Plataformas.h"
#include "Probeta.h"

class ListaProbetas
{
	Probeta* lista[MAX_PROBETAS];
	int numero;

public:
	ListaProbetas();
	~ListaProbetas();
	bool Agregar(Probeta* d);
	void DestruirContenido();
	void Dibuja();
	int getNumero() { return numero; } //Para acceder al numero de elementos creados en la lista
	Probeta* operator[] (int index);
	
};

