#include "Muñeco.h"
#include <math.h>
#include <iostream>
#include "glut.h"
using namespace std;

Muñeco::Muñeco() :sprite_vq("bin/imagenes/muñeco_vq.png", 2), sprite_fq("bin/imagenes/muñeco_fq.png", 2),
sprite_vd("bin/imagenes/muñeco_vd.png", 2), sprite_fd("bin/imagenes/muñeco_fd.png", 2),
sprite_ve("bin/imagenes/muñeco_ve.png", 2), sprite_fe("bin/imagenes/muñeco_fe.png", 2),
sprite_vm("bin/imagenes/muñeco_vm.png", 2), sprite_fm("bin/imagenes/muñeco_fm.png", 2),
sprite_va("bin/imagenes/muñeco_va.png", 2), sprite_fa("bin/imagenes/muñeco_fa.png", 2)

{

	//VALORES AUN POR DEFINIR
	posicion.x = 0;  //Posición inicial del muñeco en el eje horizontal (centro)
	posicion.y = 2.5;  //Posición inicial del muñeco en el eje vertical (suelo)
	altura = 1.5;  //Tamaño del muñeco (por definir)
	aceleracion.y = -9.8f; //Gravedad para que caiga
	sprite_vq.setCenter(0.9, 0.9);  //Centro del sprite para el muñeco vq 
	sprite_vq.setSize(2.3, 2.3);  //Tamaño del sprite para el muñeco vq
	sprite_fq.setCenter(0.9, 0.9);  //Centro del sprite para el muñeco fq
	sprite_fq.setSize(2.3, 2.3);  //Tamaño del sprite para el muñeco fq
	sprite_vd.setCenter(0.9, 0.9);
	sprite_vd.setSize(2.3, 2.3);
	sprite_fd.setCenter(0.9, 0.9);
	sprite_fd.setSize(2.3, 2.3);
	sprite_ve.setCenter(0.9, 0.9);
	sprite_ve.setSize(2.3, 2.3);
	sprite_fe.setCenter(0.9, 0.9);
	sprite_fe.setSize(2.3, 2.3);
	sprite_vm.setCenter(0.9, 0.9);
	sprite_vm.setSize(2.3, 2.3);
	sprite_fm.setCenter(0.9, 0.9);
	sprite_fm.setSize(2.3, 2.3);
	sprite_va.setCenter(0.9, 0.9);
	sprite_va.setSize(2.3, 2.3);
	sprite_fa.setCenter(0.9, 0.9);
	sprite_fa.setSize(2.3, 2.3);


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
	setfa();*/
}

Muñeco::~Muñeco()
{
}

void Muñeco::Mueve(float t) //Funcion para que el muñeco tenga movimiento
{

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.x <= -8) posicion.x = -8; //si la posicion x es <=-8 (izq del todo) se limita la posicion
	if (posicion.y <= 2.5) posicion.y = 2.5; //si la posicion y es menor que 2.5(suelo) se limita
	if (posicion.y >= 7) posicion.y = 7; //si la posicion y es mayor que 7(techo) se limita
	if (posicion.x >= 179)
	{
		posicion.x = 179;
		velocidad.x = 0;
	}
	//activo->loop(); //Funcion interna de los sprites
	
}

int Muñeco::SetSexo(unsigned char key)
{
	sexo = 2;
	if (key == 'F' || key == 'f')
		sexo = 0;

	if (key == 'V' || key == 'v')
		sexo = 1;
	cout << sexo << endl;
	return sexo;
}
int Muñeco::SetCarrera(unsigned char key)
{
	carrera = 5;
	if (key == 'Q' || key == 'q')
		carrera = 0;

	if (key == 'D' || key == 'd')
		carrera = 1;

	if (key == 'E' || key == 'e')
		carrera = 2;

	if (key == 'M' || key == 'm')
		carrera = 3;

	if (key == 'A' || key == 'a')
		carrera = 4;

	Muñeco::SetPersonaje();
	cout << carrera << endl;

	if (carrera == 5)
		return 0;
	else return 1;
}
void Muñeco::SetPersonaje() {
	switch (carrera)
	{
	case 0://Escogemos quimica
		if (sexo == 1)  setvq();
		else setfq();
		break;

	case 1: //Diseño
		if (sexo == 1)  setvd();
		else setfd();
		break;

	case 2: //Electrica
		if (sexo == 1)  setve();
		else setfe();

		break;

	case 3: //Mecanica
		if (sexo == 1)  setvm();
		else setfm();

		break;

	case 4: //Electronica
		if (sexo == 1)  setva();
		else setfa();
		break;
	}
}
void Muñeco::Dibuja()
{

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (velocidad.x > 0.035)activo->flip(false, false);
	if (velocidad.x < -0.035)activo->flip(true, false);
	if ((velocidad.x < 0.035) && (velocidad.x > -0.035))
		activo->setState(0);
	else if (activo->getState() == 0)
		activo->setState(1, false);
	activo->draw();

	glPopMatrix();

}
void Muñeco::TeclaEspecial(unsigned char key) {
	
	switch (key)
	{
	case GLUT_KEY_LEFT:
		
		Muñeco::SetVel(-5.0f, 0.0f);
		
		break;
	case GLUT_KEY_RIGHT:
		Muñeco::SetVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:
		if(Muñeco::getDistancia()) //para saber si puede saltar o no (solo puede saltar si esta en el suelo o en la plataforma)
			Muñeco::SetVel(0.0f, 7.0f);//se mete si es true
		break;


	/*case GLUT_KEY_DOWN:
		Muñeco::SetVel(0.0f, -5.0f);
		break;*/
	}
}
void Muñeco::SetVel(float vx, float vy)
{

	velocidad.x = vx;
	velocidad.y = vy;

}
bool  Muñeco::getDistancia(void)
{
	if (Muñeco::posicion.y == 2.5 || aux == 1) {//si el muñeco esta en el suelo o encima de una plataforma
		aux = 0;//interaccion
		return true;
	}
	return false;
}



