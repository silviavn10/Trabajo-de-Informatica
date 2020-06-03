#pragma once 
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Muñeco
{
	int guardamuñeco;
	float altura;
	int jugador;
	int sexo;   // 1:chico, 0:chica
	int fin;
	int carrera;
	int aux;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	SpriteSequence sprite_vq, sprite_fq, sprite_vd, sprite_fd, sprite_ve, sprite_fe, sprite_vm, sprite_fm, sprite_va, sprite_fa;
	SpriteSequence* activo;

public:
	Muñeco();
	~Muñeco() {}
	void Dibuja();
	void Mueve(float);
	void SetVel(float vx, float vy);
	void SetPos(float x, float y);
	void setVelY(float vy) { velocidad.y = vy; };
	void setPosY(float y) { posicion.y = y; };
	void setGravedad(float g) { aceleracion.y = g; };
	void setguardamuñeco(int x) { guardamuñeco = x; }
	void SetPersonaje(void);
	void  TeclaEspecial(unsigned char key);
	float getAltura() { return altura; }
	float getPosX(void) { return posicion.x; };
	float getPosY(void) { return posicion.y; };
	float getVelY(void) { return velocidad.y; };
	int SetSexo(unsigned char key);
	int SetCarrera(unsigned char key);
	int getguardamuñeco() { return guardamuñeco; }
	int getfin() { return fin; }
	bool getDistancia(void);

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

	friend class Interaccion;

};
