#include "PlataformaMovil.h"

PlataformaMovil::PlataformaMovil()
{
	velocidad.x = 3;
	velocidad.y = 0;
	cambio = 1;
	l = 0;
	
}

PlataformaMovil::PlataformaMovil(float lad, float x, float y)
{
	SetLado(lad);
	SetPosX(x);
	SetPosY(y);
	velocidad.x = 8;
	aceleracion.x = -5.8;
	cambio = 1;
	l = 0; 
}

PlataformaMovil::PlataformaMovil(float lad, float x, float y, float vy)
{
	SetLado(lad);
	SetPosX(x);
	SetPosY(y);
	cambio = 1;
	l = 0;
	velocidad.y = vy; 
	aceleracion.y = -3.8;
}

PlataformaMovil::~PlataformaMovil()
{

}
void PlataformaMovil::SetColor(unsigned char r, unsigned char v, unsigned char a) {   //REDEFINICION DE LA FUNCION
	
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
	posicion = GetPos() + velocidad * t + aceleracion * (0.5f * t * t);
	SetPos(posicion);
	velocidad = velocidad + aceleracion * t;
	
	if (velocidad.x < -8) {
		velocidad.x = 8;
	}

	if (velocidad.y < -7) {
		velocidad.y = 7;
	}

	limite1 = GetLimite1() + velocidad * t + aceleracion * (0.5f * t * t);
	limite2 = GetLimite2() + velocidad * t + aceleracion * (0.5f * t * t);
	SetLimite1(limite1);
	SetLimite2(limite2);
	SetColor(0, 0, 0);
	
}

