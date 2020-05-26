#include "PlataformaMovil.h"
PlataformaMovil::PlataformaMovil()
{
	velocidad.x = 3;
	velocidad.y = 0;
	//posicion.x = 6;
	//posicion.y = 3;
	//lado = 1.5f;
	//limite1.x = 4;
	//limite2.x = 8;
	
}
PlataformaMovil::~PlataformaMovil()
{

}
/*
void PlataformaMovil::SetVel(float v) {
	velocidad.x = v;
}*/

/*void PlataformaMovil:: SetLimitesMoviles(float x1, float x2)
{
	LimiteDeMov1.x = x1;
	LimiteDeMov2.x = x2;
}*/

void PlataformaMovil::SetColor(unsigned char r, unsigned char v, unsigned char a) { //-------------------------------------------------------REDEFINICION DE LA FUNCION
	
	if (cambio == 2) {
		rojo = r + 67;
		verde = v + 6;
		azul = a + 6;
	}
	if (cambio == 1) {
		rojo = r + 72;
		verde = v + 7;
		azul = a + 30;
	}

	if (l == 12) {
		cambio += SetCambio(cambio);
		l=0;
	}
	if (l < 12)
		l++;
}

int PlataformaMovil::SetCambio(int c) {
	
	if (c == 1)
		return 1;
	if (c == 2)
		return -1;
	
	
}

void PlataformaMovil::Mueve(float t) 
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	
	if (velocidad.x < -8) {
		velocidad.x = 8;
	}

	if (velocidad.y < -7) {
		velocidad.y = 7;
	}

	limite1 = limite1 + velocidad * t + aceleracion * (0.5f * t * t);
	limite2 = limite2 + velocidad * t + aceleracion * (0.5f * t * t);

	//-----------------------------------------------------------------------------------------------------------------------HACER LIMITE
	SetColor(0, 0, 0);
	
}

