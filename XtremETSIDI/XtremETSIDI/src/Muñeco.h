#pragma once 
#include "Vector2D.h"
#include "Plataformas.h"
#include "Suelo.h"
#include"Vida.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Muñeco
{
public:
	Muñeco();
	//Muñeco(float altura);
    ~Muñeco();
	void Dibuja();
	void Mueve(float);
	void SetVel(float vx, float vy);
	int SetSexo(unsigned char key);
	void SetPersonaje(void);
	void  TeclaEspecial(unsigned char key);
	int SetCarrera(unsigned char key);
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
	friend class Interaccion;
	friend class Nivel;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Plataformas Plataforma;
	//Vida Vida;
	Suelo Suelo;
	float altura;
	int jugador;
	int sexo;// 1:varon, 0:hembra
	int carrera;

	SpriteSequence sprite_vq, sprite_fq, sprite_vd, sprite_fd, sprite_ve, sprite_fe, sprite_vm, sprite_fm,
		sprite_va, sprite_fa;
	SpriteSequence* activo;
};
