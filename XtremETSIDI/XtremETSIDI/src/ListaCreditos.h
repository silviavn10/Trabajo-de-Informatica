#pragma once
#include "Creditos.h"
#include "Muñeco.h"
#define MAX_CREDITOS 50

class ListaCreditos
{
public:
	ListaCreditos();
	~ListaCreditos();
	void Dibuja();
	void Eliminar(Creditos* c);
	void Eliminar(int index);
	void DestruirContenido();
	int getNumero() { return numero; };
	bool Agregar(Creditos* c);
	void Mueve(float t);
	bool ListaCreditos::operator += (Creditos* c);
	Creditos* operator[] (int index);
	friend class Nivel;

private:
	Creditos* *lista;
	int numero;
};
