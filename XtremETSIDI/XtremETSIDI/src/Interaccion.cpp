#include "Interaccion.h"
#include <math.h>

Interaccion::Interaccion() //Constructor
{
}

Interaccion::~Interaccion() //Destructor
{
}

//FALTA definir mu�eco
bool Interaccion::choque (Creditos c, Mu�eco& m)
{
    
    float dif1 = c.posicion.x - m.posicion.x; //MIRAR RANGO PORQUE EL BICHO ES M�S GRANDE QUE EL MU�ECO
    float dif2 = c.posicion.y - m.posicion.y;
    if (dif1 <= 0 && dif2 <= 0)
        return true;
    else return false;
}
