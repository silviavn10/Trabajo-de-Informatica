#pragma once
#include "Suelo.h"

class Caja
{
	friend class Interaccion;
public:
	void Dibuja();
	Caja();
	virtual ~Caja();
private:
	Suelo suelo;
	Suelo techo;
	Suelo pared_izq;
	Suelo pared_dcha;

};
