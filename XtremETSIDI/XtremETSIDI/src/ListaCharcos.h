#pragma once
#include "Charcos.h"
#include "Interaccion.h"
#define MAX_C 9

class ListaCharcos
{
	Charcos* lista[MAX_C];
	int numero;

public:
	ListaCharcos();
	~ListaCharcos() {}
	bool Agregar(Charcos *c);
	void Dibuja();
	void DestruirContenido();
	Charcos* operator [](int i);

};

