#include "Puntuacion.h"
#include "Interaccion.h"

Puntuacion::Puntuacion() //Constructor
{
	inicio = 0;
	for (int i = 0; i < MAX_BONUS; i++) lista[i] = 0;  //No se más de 100 créditos
}


Puntuacion::~Puntuacion() //Destructor
{

}

