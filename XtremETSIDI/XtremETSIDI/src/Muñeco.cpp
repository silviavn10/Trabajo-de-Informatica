#include "Muñeco.h"
#include <math.h>
#include "glut.h"
#include "ETSIDI.h"

Muñeco::~Muñeco()
{
}

Muñeco::Muñeco() :sprite_vq("bin/imagenes/sprite_vq.png", 3), sprite_fq("bin/imagenes/sprite_fq.png", 3), 
sprite_vd("bin/imagenes/sprite_vd.png", 3), sprite_fd("bin/imagenes/sprite_fd.png", 3),
sprite_ve("bin/imagenes/sprite_ve.png", 3), sprite_fe("bin/imagenes/sprite_fe.png", 3),
sprite_vm("bin/imagenes/sprite_vm.png", 3), sprite_fm("bin/imagenes/sprite_fm.png", 3),
sprite_va("bin/imagenes/sprite_va.png", 3), sprite_fa("bin/imagenes/sprite_fa.png", 3)

{
	posicion.x = 0;  //Posición inicial del muñeco en el eje horizontal (centro)
	posicion.y = 0;  //Posición inicial del muñeco en el eje vertical (suelo)
	altura = 1.8f;  //Tamaño del muñeco (por definir)

	sprite_vq.setCenter(0.9, 0.9);  //Centro del sprite para el muñeco vq 
	sprite_vq.setSize(1.8, 1.8);  //Tamaño del sprite para el muñeco vq
	sprite_fq.setCenter(0.9, 0.9);  //Centro del sprite para el muñeco fq
	sprite_fq.setSize(1.8, 1.8);  //Tamaño del sprite para el muñeco fq
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
	sprite_fa.setSize(1.8, 1.8);  

	//No sabemos si hay que ponerlo aqui tambien o no 
	/*setvq();  //Funcion para activar el vq
	setfq();  //Funcion para activar el fq
	setvd();
	setfd();
	setve();
	setfe();
	setvm();
	setfm();
	setva();
	setfa();
	*/
}

void Muñeco::Mueve(float t) //Funcion para que el muñeco tenga movimiento
{
	activo->loop(); //Funcion interna de los sprites
	posicion = posicion + velocidad * t + aceleracion*(0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void Muñeco::Dibuja()
{
	if (sexo == 0) //Escogemos chico
	{
		switch (carrera)
		{
		case 0://Escogemos quimica
			setvq();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5); 
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 1: //Diseño
			setvd();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 2: //Electrica
			setve();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 3: //Mecanica
			setvm();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 4: //Electronica
			setva();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
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
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 1: //Diseño
			setfd();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 2: //Electrica
			setfe();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 3: //Mecanica
			setfm();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;

		case 4: //Electronica
			setfa();
			glPushMatrix();
			glTranslatef(posicion.x, posicion.y, 0.5);
			activo->draw(); //Se dibuja el muñeco vq, es una funcion interna de los sprites
			glPopMatrix();
			break;
		}
	}
}

void Muñeco::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Muñeco::SetAceleracion(float ax, float ay)
{
	aceleracion.x = ax;
	aceleracion.y = ay;
}

float Muñeco::SetSalto(float h, float v0 = 0.0, float g = 9.8)
{
	float t = (-v0 + sqrt(v0 * v0 + 2 * g * h)) / g; //ecuacion de la parabola para saltar
	return v0 + g * t;
}

void Muñeco::SetSexo(int x) 
{
	sexo = x;
}
void Muñeco::SetCarrera(int x)
{
	carrera = x;
}

void Muñeco::TeclaEspecial(unsigned char key)
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
		SetAceleracion()

	}
}

Vector2D Muñeco::GetPos() {}
float Muñeco::GetAltura() {}