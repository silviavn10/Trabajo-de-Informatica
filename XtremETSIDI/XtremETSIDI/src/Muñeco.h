#pragma once
#include "Vector2D.h"
#include "Menu.h"

using ETSIDI::SpriteSequence;

class Muñeco
{
public:
	Muñeco();
	virtual ~Muñeco();
	void Dibuja();
	void Mueve(float);
	void TeclaEspecial(unsigned char key);
	Vector2D GetPos();
	void SetVel(float vx, float vy);
	float GetAltura();
	void SetSexo(int x);
	void SetCarrera(int x);
	void SetAceleracion(float ax, float ay);
	float SetSalto(float h, float v0 = 0.0, float g = 9.8);
	friend class Interaccion;
	friend class Menu;
	void setvq() { activo = &sprite_vq; }
	void setfq() { activo = &sprite_fq; }
	void setvd() { activo = &sprite_vd; }
	void setfd() { activo = &sprite_fd; }
	void setve() { activo = &sprite_ve; }
	void setfe() { activo = &sprite_fe; }
	void setvm() { activo = &sprite_vm; }
	void setfm() { activo = &sprite_fm; }
	void setva() { activo = &sprite_va; }
	void setfa() { activo = &sprite_fa; }


private:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	float altura;
	int sexo;
	int carrera;
	SpriteSequence sprite_vq, sprite_fq, sprite_vd, sprite_fd, sprite_ve, sprite_fe, sprite_vm, sprite_fm,
		sprite_va, sprite_fa;
	SpriteSequence* activo;
};
