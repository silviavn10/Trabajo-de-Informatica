#include "Puntuacion.h"
#include "Interaccion.h"

Puntuacion::Puntuacion() //Constructor
{
	inicio = 0;
	for (int i = 0; i < MAX_BONUS; i++) lista[i] = 0;  //No se m�s de 100 cr�ditos
}


Puntuacion::~Puntuacion() //Destructor
{

}

