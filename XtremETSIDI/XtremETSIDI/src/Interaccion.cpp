#include "Interaccion.h"
#include <math.h>

Interaccion::Interaccion() //Constructor
{
}

Interaccion::~Interaccion() //Destructor
{
}
void Interaccion::Colision(Muñeco& m, Plataformas p)
{
	
	float xlim1 = p.limite1.x;//punto abajo izq
	float xlim2 = p.limite1.x+p.lado;//punto abajo derecha
	float ylim1 = p.limite1.y;//punto arriba izq
	float ylim2 = p.limite1.y + p.lado;//punto arriba dercha
	if (m.posicion.x + 1.0 > xlim1 && m.posicion.y + m.altura >= ylim1) { //comprueba que la posicion x sea menor que el limite izq de la plataforma
	                                                                    	//y que la posicion y sea mayor que el limite de abajo de la plataforam
		if (m.posicion.x < xlim2 && m.posicion.y + 1 <= ylim2)//comprueba que el muñeco sigue en la parte izq de la plataforma 
		{	                                                 //y que la posicion en y es menor que el limite y de la plataforma (no está todavia encima)
			if (m.posicion.y == 2.5 || (m.posicion.y > 2.5 && m.posicion.y + m.altura < ylim2))//si el muñeco esta en el suelo o en una altura entre los limites de la plataforma 
				m.posicion.x = xlim1 - 1.0;// se establece la posicion del muñeco justo antes de la plataforma 
		}
	}
	if (m.posicion.x-1.0 < xlim2 && m.posicion.y + 1 <= ylim2){//igual pero en el lado derecho
		if (m.posicion.y + m.altura >= ylim1 && m.posicion.x > xlim1)
			if (m.posicion.y == 2.5 || (m.posicion.y > 2.5 && m.posicion.y + m.altura < ylim2))
					m.posicion.x = xlim2 + 1.0;
			}
	if ((m.posicion.x + 1.0 > xlim1 && m.posicion.x - 1.0 < xlim2) && m.posicion.y +m.altura>ylim1  )//comprueba si esta entre los limites superiores de la plataforma (arriba de la plataforma)
		if (m.posicion.y + 0.7 < ylim2 ) {//comprueba que la posicion en y sea menor al limite superior
			m.posicion.y = (ylim2 - 0.7);// toma esa altura como suelo de la plataforma para el muñeco
			m.aux = 1;
		}
	
	if ((m.posicion.x + 1.0 > xlim1&& m.posicion.x - 1.0 < xlim2) && m.posicion.y + m.altura < ylim1)
	{
		Vector2D dir;

		float dif = p.distancia(m.posicion, p, &dir) - (m.altura + 1.0);
		if (dif <= 0.0f)
		{
			Vector2D v_inicial = m.velocidad;
			m.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
			m.posicion = m.posicion - dir * dif;

		}
	}

}
/*void Interaccion::rebote(Plataformas p, Muñeco m)
{

	Vector2D dir;
	
	float dif = (m.posicion.y + 0.7) - p.limite1.x;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = m.velocidad;
		m.velocidad = v_inicial - dir * 2.0 * (v_inicial * dir);
		m.posicion = m.posicion - dir * dif;
		
	}

}*/

