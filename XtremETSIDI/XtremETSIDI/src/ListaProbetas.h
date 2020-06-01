#pragma once
#define MAX_PROBETAS 24
#include"Plataformas.h"
#include "Probeta.h"
#include "Muñeco.h"
class ListaProbetas
{
public:
	ListaProbetas();
	virtual ~ListaProbetas();
	bool Agregar(Probeta* d);
	void DestruirContenido();
	void Dibuja();
	void Eliminar(Probeta* m);
	void Eliminar(int index);
	int getNumero() { return numero; } //Para acceder al numero de elementos creados en la lista
	Probeta* operator[] (int index);
	
private:
	Probeta* lista[MAX_PROBETAS];
	int numero;
};

