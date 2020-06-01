#pragma once
#define MAX_REGLAS 24
#include"Plataformas.h"
#include "Reglas.h"
#include "Muñeco.h"
class ListaReglas
{
public:
	ListaReglas();
	virtual ~ListaReglas();
	bool Agregar(Reglas* d);
	void DestruirContenido();
	void Dibuja();
	void Eliminar(Reglas* m);
	void Eliminar(int index);
	int getNumero() { return numero; } //Para acceder al numero de elementos creados en la lista
	Reglas* operator[] (int index);

private:
	Reglas* lista[MAX_REGLAS];
	int numero;
};