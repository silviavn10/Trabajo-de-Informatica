#pragma once
#include "Creditos.h"
#include "Plataformas.h"
#include "Proyectiles.h"
#include "Muñeco.h"
#include "Charcos.h"
#include "CharcoCOVID.h"
#include "COVID.h"


class Interaccion
{
public:
	
	Interaccion();
	~Interaccion();
	static void Colision(Muñeco& h, Plataformas plataforma);
	static bool Colision(Muñeco& m, Creditos& c);
	static bool Colision(Muñeco& m, Charcos& c);
	static bool Colision(Muñeco& m, CharcoCOVID& c);
	static bool Colision(Muñeco& m, Proyectiles& pr);
	static bool Colision(Plataformas& p, Proyectiles& pr);
	static bool Colision(Muñeco& m, COVID& c);
	

};
