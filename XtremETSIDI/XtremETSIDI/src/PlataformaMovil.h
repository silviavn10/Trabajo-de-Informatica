#pragma once
#include "Plataformas.h"
class PlataformaMovil : public Plataformas
{
	public:
		PlataformaMovil();
		~PlataformaMovil();
		PlataformaMovil(float lad, float x, float y) { SetLado(lad); SetPosX(x); SetPosY(y); velocidad.x = 8; aceleracion.x = -5.8; }
		PlataformaMovil(float lad, float x, float y, float vy) { SetLado(lad); SetPosX(x); SetPosY(y); velocidad.y = vy; aceleracion.y = -3.8; }
		void Mueve(float t);
		void SetColor(unsigned char r, unsigned char v, unsigned char a);
		int cambio=1;
		int l = 0;
		int SetCambio(int c);
	
private:
	Vector2D aceleracion,velocidad,pos,lim1,lim2;
	Vector2D LimiteDeMov1, LimiteDeMov2;
};

