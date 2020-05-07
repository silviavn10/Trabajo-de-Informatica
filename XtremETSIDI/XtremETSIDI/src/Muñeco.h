#pragma once 
#include "Vector2D.h"
#include "Suelo.h"
#include "Menu.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Muñeco
{
public:
	Muñeco(); 
	//Muñeco(float rad, float x = 0, float y = 0, float vx = 0, float vy = 0);
	virtual ~Muñeco();
	void Dibuja();
	void Mueve(float);
	void TeclaEspecial(unsigned char key);
	void SetVel(float vx, float vy);
	void SetVel(Vector2D vel);
	void SetSexo(int x);
	void SetCarrera(int x);
	friend class Interaccion;
	friend class Menu;
	float getAltura() { return altura; }
	float getPosX(void) { return posicion.x; };
	float getPosY(void) { return posicion.y; };
	float getVelY(void) { return velocidad.y; };
	void setVelY(float vy) { velocidad.y = vy; };
	void setPosY(float y) { posicion.y = y; };
	void setGravedad(float g) { aceleracion.y = g; };
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
	Plataformas plataformas;
	Suelo suelo;
	float altura;
	int sexo;
	int carrera;
	SpriteSequence sprite_vq, sprite_fq, sprite_vd, sprite_fd, sprite_ve, sprite_fe, sprite_vm, sprite_fm,
		sprite_va, sprite_fa;
	SpriteSequence* activo;
};
