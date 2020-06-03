#pragma once
#define MAX_REGLAS 24
#include"Plataformas.h"
#include "Reglas.h"

class ListaReglas
{
	Reglas* lista[MAX_REGLAS];
	int numero;

public:
	ListaReglas();
	~ListaReglas();
	bool Agregar(Reglas* d);
	void DestruirContenido();
	void Dibuja();
	int getNumero() { return numero; } //Para acceder al numero de elementos creados en la lista
	Reglas* operator[] (int index);

};