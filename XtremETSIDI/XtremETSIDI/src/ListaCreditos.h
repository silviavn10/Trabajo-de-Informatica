#pragma once
#include "Creditos.h"
#include "Muñeco.h"
#define MAX_CREDITOS 200

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
	Creditos* Colision(Muñeco m);
	void Mueve(float t);
	bool ListaCreditos::operator += (Creditos* c);
	//int getNumero() { return numero; }
	Creditos* operator[] (int index);
	int numero;
	friend class Nivel;

private:
	Creditos* *lista;
};
