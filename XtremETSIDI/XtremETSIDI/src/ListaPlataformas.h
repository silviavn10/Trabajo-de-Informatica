#pragma once
#include "Plataformas.h"
#include "Mu�eco.h"
#define MAX_PLATAFORMAS 10

class ListaPlataformas
{
	public:
	ListaPlataformas();
	~ListaPlataformas();
	void Dibuja();
	void Eliminar(Plataformas* p);
	void Eliminar(int index);
	void DestruirContenido();
	int getNumero() { return numero; };
	bool Agregar(Plataformas* p);
	bool ListaPlataformas::operator += (Plataformas* p);
	friend class Nivel;
	Plataformas* Colision(Mu�eco m);

	//int getNumero() { return numero; }
	Plataformas* operator[] (int index);

private:
	Plataformas** lista;// hay que crear un plataforma* que apunte a la direccion de memoria que te devuelce la creacion de memoria din�mica. 
						//el segundo puntero es para que lista sea un vector
	int numero;
};
