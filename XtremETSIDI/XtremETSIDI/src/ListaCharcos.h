#pragma once
#include "Charcos.h"
#include "Interaccion.h"
#define MAX_C 9

class ListaCharcos
{
public:
	ListaCharcos();
	~ListaCharcos();
	bool Agregar(Charcos *c);
	void Dibuja();
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(Charcos *c);
	Charcos* operator [](int i);
private:
	Charcos* lista[MAX_C];
	int numero;
};

