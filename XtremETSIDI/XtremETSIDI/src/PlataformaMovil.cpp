#include "PlataformaMovil.h"
PlataformaMovil::PlataformaMovil()
{
	velocidad.x = 3;
	velocidad.y = 0;
	
}
PlataformaMovil::~PlataformaMovil()
{

}


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
	pos= GetPos() + velocidad * t + aceleracion * (0.5f * t * t);
	SetPos(pos);
	velocidad = velocidad + aceleracion * t;
	
	if (velocidad.x < -8) {
		velocidad.x = 8;
	}

	if (velocidad.y < -7) {
		velocidad.y = 7;
	}

	lim1 = GetLimite1() + velocidad * t + aceleracion * (0.5f * t * t);
	lim2 = GetLimite2() + velocidad * t + aceleracion * (0.5f * t * t);
	SetLimite1(lim1);
	SetLimite2(lim2);
	//-----------------------------------------------------------------------------------------------------------------------HACER LIMITE
	SetColor(0, 0, 0);
	
}

