#pragma once
#include "Plataformas.h"
class PlataformaMovil : public Plataformas
{
	Vector2D aceleracion, velocidad;
	Vector2D posicion;
	Vector2D limite1;
	Vector2D limite2;
	float lado;
	int cambio;
	int l;

	public:
		PlataformaMovil();
		PlataformaMovil(float lad, float x, float y);
		PlataformaMovil(float lad, float x, float y, float vy);
		~PlataformaMovil();
		void Mueve(float t);
		void SetColor(unsigned char r, unsigned char v, unsigned char a);
		int SetCambio(int c);
	
};

