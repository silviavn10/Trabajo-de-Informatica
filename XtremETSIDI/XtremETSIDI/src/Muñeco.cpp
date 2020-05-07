#include "Mu�eco.h"
#include <math.h>
#include <iostream>
#include "glut.h"

using namespace std;

Mu�eco::Mu�eco() :sprite_vq("bin/imagenes/mu�eco_vq.png", 2), sprite_fq("bin/imagenes/mu�eco_fq.png", 2),
sprite_vd("bin/imagenes/mu�eco_vd.png", 2), sprite_fd("bin/imagenes/mu�eco_fd.png", 2),
sprite_ve("bin/imagenes/mu�eco_ve.png", 2), sprite_fe("bin/imagenes/mu�eco_fe.png", 2),
sprite_vm("bin/imagenes/mu�eco_vm.png", 2), sprite_fm("bin/imagenes/mu�eco_fm.png", 2),
sprite_va("bin/imagenes/mu�eco_va.png", 2), sprite_fa("bin/imagenes/mu�eco_fa.png", 2)

{
	//VALORES AUN POR DEFINIR
	posicion.x = 0;  //Posici�n inicial del mu�eco en el eje horizontal (centro)
	posicion.y = 2.5;  //Posici�n inicial del mu�eco en el eje vertical (suelo)
	altura = 1.8f;  //Tama�o del mu�eco (por definir)
	velocidad.x = 0.5;  //Velocidad en el eje horizontal
	velocidad.y = 0;//Velocidad en el eje vertical
	aceleracion.y = -20.0f; //Gravedad para que caiga
	
	sprite_vq.setCenter(0.9, 0.9);  //Centro del sprite para el mu�eco vq 
	sprite_vq.setSize(1.8, 1.8);  //Tama�o del sprite para el mu�eco vq
	sprite_fq.setCenter(0.9, 0.9);  //Centro del sprite para el mu�eco fq
	sprite_fq.setSize(1.8, 1.8);  //Tama�o del sprite para el mu�eco fq
	sprite_vd.setCenter(0.9, 0.9);
	sprite_vd.setSize(1.8, 1.8);
	sprite_fd.setCenter(0.9, 0.9);
	sprite_fd.setSize(1.8, 1.8);
	sprite_ve.setCenter(0.9, 0.9);
	sprite_ve.setSize(1.8, 1.8);
	sprite_fe.setCenter(0.9, 0.9);
	sprite_fe.setSize(1.8, 1.8);
	sprite_vm.setCenter(0.9, 0.9);
	sprite_vm.setSize(1.8, 1.8);
	sprite_fm.setCenter(0.9, 0.9);
	sprite_fm.setSize(1.8, 1.8);
	sprite_va.setCenter(0.9, 0.9);
	sprite_va.setSize(1.8, 1.8);
	sprite_fa.setCenter(0.9, 0.9);
	sprite_fa.setSize(2.3, 2.3);

	//No sabemos si hay que ponerlo aqui tambien o no 
	setvq();  //Funcion para activar el vq
	setfq();  //Funcion para activar el fq
	setvd();
	setfd();
	setve();
	setfe();
	setvm();
	setfm();
	setva();
	setfa();
}

Mu�eco::~Mu�eco()
{
}

void Mu�eco::Mueve(float t) //Funcion para que el mu�eco tenga movimiento
{
	activo->loop(); //Funcion interna de los sprites
	posicion = posicion + velocidad * t + aceleracion*(0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Mu�eco::SetSexo(int x)
{
	sexo = x;
	cout << "sexo:" << sexo;
}
void Mu�eco::SetCarrera(int x)
{
	carrera = x;
	cout << "carrera:" << carrera;
}

void Mu�eco::Dibuja()
{	
	if (sexo == 0) //Escogemos chico
	{
		switch (carrera)
		{
		case 0://Escogemos quimica
			setvq();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5); 
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 1: //Dise�o
			setvd();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 2: //Electrica
			setve();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 3: //Mecanica
			setvm();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 4: //Electronica
			setva();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;
		}
	}

	if (sexo == 1) //Escogemos chica
	{
		switch (carrera)
		{
		case 0://Escogemos quimica
			setfq();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 1: //Dise�o
			setfd();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 2: //Electrica
			setfe();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 3: //Mecanica
			setfm();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 4: //Electronica
			setfa();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;
		}
	}
}

/*void Mu�eco::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	activo->draw(); //Se dibuja el mu�eco vq, es una funcion interna de los sprites
	glPopMatrix();
}*/

void Mu�eco::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Mu�eco::SetVel(Vector2D vel)
{
	velocidad = vel;
}

/*float Mu�eco::SetSalto(float h, float v0 = 0.0, float g = 9.8)
{
	float t = (-v0 + sqrt(v0 * v0 + 2 * g * h)) / g; //ecuacion de la parabola para saltar
	return v0 + g * t;
}
*/


void Mu�eco::TeclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		SetVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		SetVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		for (int i = 0; i < MAX_PLATAFORMAS; i++) {
			if (-0.1 < (getPosY() - (plataformas.GetLimiteY2())) < 0.1) setVelY(15.0f);
		}
		if (-0.1 < (getPosY() - (plataformas.GetLimiteY2())) < 0.1) setVelY(15.0f);
		if ((getPosY() - suelo.GetSueloLimiteY2()) < 0.05) {
			setVelY(15.0f);
		}
		break;
	}
}
