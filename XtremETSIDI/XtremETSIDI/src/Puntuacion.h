#pragma once
#define MAX_BONUS 100
#include "Creditos.h"

class Puntuacion
{
public:
	Puntuacion();
	~Puntuacion();

	

private:
	Creditos* lista[MAX_BONUS];
	int inicio;  
};

