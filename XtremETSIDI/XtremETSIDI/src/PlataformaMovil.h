#pragma once
#include "Plataformas.h"
class PlataformaMovil : public Plataformas
{
	public:
		PlataformaMovil();
		~PlataformaMovil();
		//PlataformaMovil(float lad, float x, float y) : Plataformas(lad, x, y) { velocidad.x = 1; }
		PlataformaMovil(float lad, float x, float y) { lado = lad; posicion.x = x; posicion.y = y; velocidad.x = 8; aceleracion.x = -5.8; }
		PlataformaMovil(float lad, float x, float y, float vy) { lado = lad; posicion.x = x; posicion.y = y; velocidad.y = vy; aceleracion.y = -3.8; }
		//PlataformaMovil(float lad, float x, float y);
		void Mueve(float t);
		//void Mueve(float);
		//void SetLimitesMoviles(float x1, float x2);
		void SetColor(unsigned char r, unsigned char v, unsigned char a);
		int cambio=1;
		int l = 0;
		int SetCambio(int c);
		//void SetVel(float v);
private:
	Vector2D aceleracion;
	Vector2D velocidad;
	Vector2D LimiteDeMov1, LimiteDeMov2;
};

