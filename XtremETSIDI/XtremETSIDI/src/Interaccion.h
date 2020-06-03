#pragma once
#include "Creditos.h"
#include "Plataformas.h"
#include "Proyectiles.h"
#include "Mu�eco.h"
#include "Charcos.h"
#include "COVID.h"


class Interaccion
{
public:
	
	Interaccion() {}
	~Interaccion() {}
	static void Colision(Mu�eco& h, Plataformas plataforma);
	static bool Colision(Mu�eco& m, Creditos& c);
	static bool Colision(Mu�eco& m, Charcos& c);
	static bool Colision(Mu�eco& m, Proyectiles& pr);
	static bool Colision(Mu�eco& m, COVID& c);
	
};
