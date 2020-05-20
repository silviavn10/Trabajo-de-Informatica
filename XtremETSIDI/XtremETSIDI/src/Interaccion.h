#pragma once
#include "Creditos.h"
#include "Plataformas.h"
#include "Suelo.h"
#include "Proyectiles.h"
#include "Mu�eco.h"
#include "Charcos.h"

class Interaccion
{
public:
	
	Interaccion();
	~Interaccion();
	//static bool Colision (Creditos& c, Mu�eco& m); //Definir mu�eco
	static void Colision(Mu�eco& h, Plataformas plataforma);
	static bool Colision(Mu�eco& m, Creditos& c);
	static bool Colision(Mu�eco& m, Charcos& c);
	//static bool Colision(Plataformas& p, Proyectiles& pr);
	//static bool Colision(Proyectiles& pr, Mu�eco& m);
	//static bool Colision(Suelo& s, Mu�eco& m);
	//static bool Colision(Proyectiles& pr, Suelo& s);
	//static void rebote(Plataformas p, Mu�eco m);
	

	//FALTAN MUCHAS INTERACCIONES

};
