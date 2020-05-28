#pragma once
#include "CharcoCOVID.h"
#include "Interaccion.h"
#define MAX_C 9

class ListaCharcoCOVID
{
public:
	ListaCharcoCOVID();
	~ListaCharcoCOVID();
	bool Agregar(CharcoCOVID* c);
	void Dibuja();
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(CharcoCOVID* c);
	CharcoCOVID* operator [](int i);
	friend class NivelCOVID;
private:
	CharcoCOVID* lista[MAX_C];
	int numero;
};
