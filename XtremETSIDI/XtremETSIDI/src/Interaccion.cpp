#include "Interaccion.h"
#include <math.h>

Interaccion::Interaccion() //Constructor
{
}

Interaccion::~Interaccion() //Destructor
{
}

//FALTA definir muñeco
bool Interaccion::choque (Creditos c, Muñeco& m)
{
    
    float dif1 = c.posicion.x - m.posicion.x; //MIRAR RANGO PORQUE EL BICHO ES MÁS GRANDE QUE EL MUÑECO
    float dif2 = c.posicion.y - m.posicion.y;
    if (dif1 <= 0 && dif2 <= 0)
        return true;
    else return false;
}
