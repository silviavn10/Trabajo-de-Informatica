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
	//void Mueve(float t);
	void Dibuja();
	void Eliminar(Reglas* m);
	void Eliminar(int index);

	//void Colision(Imag imag);
	int getNumero() { return numero; } //Para acceder al numero de elementos creados en la lista
	Reglas* operator[] (int index);
	//void Colision(Caja c);
private:
	Reglas* lista[MAX_REGLAS];
	int numero;
};