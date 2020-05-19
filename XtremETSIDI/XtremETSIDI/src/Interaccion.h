#pragma once
#include "Creditos.h"
#include "Plataformas.h"
#include "Suelo.h"
#include "Proyectiles.h"
#include "Muñeco.h"

class Interaccion
{
public:
	
	Interaccion();
	~Interaccion();
	//static bool Colision (Creditos& c, Muñeco& m); //Definir muñeco
	static void Colision(Muñeco& h, Plataformas plataforma);
	static void Colision(Muñeco& m, Creditos& c);
	//static bool Colision(Plataformas& p, Proyectiles& pr);
	//static bool Colision(Proyectiles& pr, Muñeco& m);
	//static bool Colision(Suelo& s, Muñeco& m);
	//static bool Colision(Proyectiles& pr, Suelo& s);
	//static void rebote(Plataformas p, Muñeco m);
	

	//FALTAN MUCHAS INTERACCIONES
};
