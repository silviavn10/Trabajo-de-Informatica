#pragma once
#include "Creditos.h"
#define MAX_CREDITOS 100

class ListaCreditos
{
	Creditos** lista;
	int numero;

public:
	ListaCreditos();
	~ListaCreditos();
	void Dibuja();
	void DestruirContenido();
	void Mueve(float t);
	int getNumero() { return numero; };
	bool Agregar(Creditos* c);
	bool ListaCreditos::operator += (Creditos* c);
	Creditos* operator[] (int index);
	friend class Nivel;

};
