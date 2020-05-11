/*#include "Interaccion.h"
#include <math.h>

Interaccion::Interaccion() //Constructor
{
}

Interaccion::~Interaccion() //Destructor
{
}
bool Interaccion::Colision(Proyectiles pr, Suelo s)
{
	Vector2D pos = h.GetPos(); //la posicion de la base del hombre
	pos.y += h.GetAltura() / 2.0f; //posicion del centro
	float distancia = (e.posicion - pos).modulo();
	if (distancia < e.radio)
		return true;
	return false;
}
bool Interaccion::Colision(Disparo d, Pared p)
{
	Vector2D pos = d.GetPos();
	float dist = p.distancia(pos);
	if (dist < d.GetRadio())
		return true;
	return false;
}
//FALTA definir muñeco
bool Interaccion::Colision(Creditos c, Muñeco& m)
{

	float dif1 = c.posicion.x - m.posicion.x; //MIRAR RANGO PORQUE EL BICHO ES MÁS GRANDE QUE EL MUÑECO
	float dif2 = c.posicion.y - m.posicion.y;
	if (dif1 <= 0 && dif2 <= 0)
		return true;
	else return false;
}
*/
