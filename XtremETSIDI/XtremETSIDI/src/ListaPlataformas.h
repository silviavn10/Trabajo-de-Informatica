#pragma once
#include "Plataformas.h"
#include "Mu�eco.h"
#include "PlataformaMovil.h"
#define MAX_PLATAFORMAS 25
#define MAX_PLATAFORMASMOVILES 25

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
	Plataformas* Colision(Mu�eco m);
	//int getNumero() { return numero; }
	Plataformas* operator[] (int index);
	void Colision(Mu�eco& h, Plataformas* Lista);
	void Color(unsigned char r, unsigned char v, unsigned char a);
	void Mueve(float t);
	friend class Nivel;
	friend class NivelCOVID;
protected:
	Plataformas** lista;// hay que crear un plataforma* que apunte a la direccion de memoria que te devuelce la creacion de memoria din�mica. 
						//el segundo puntero es para que lista sea un vector
	int numero;
};