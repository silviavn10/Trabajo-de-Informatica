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
	//activo = NULL;
	posicion.x = 0;  //Posici�n inicial del mu�eco en el eje horizontal (centro)
	posicion.y = 2.5;  //Posici�n inicial del mu�eco en el eje vertical (suelo)
	altura = 1.5;  //Tama�o del mu�eco (por definir)
	aceleracion.y = -9.8f; //Gravedad para que caiga
	sprite_vq.setCenter(0.9, 0.9);  //Centro del sprite para el mu�eco vq 
	sprite_vq.setSize(2.3, 2.3);  //Tama�o del sprite para el mu�eco vq
	sprite_fq.setCenter(0.9, 0.9);  //Centro del sprite para el mu�eco fq
	sprite_fq.setSize(2.3, 2.3);  //Tama�o del sprite para el mu�eco fq
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
 
}

Mu�eco::~Mu�eco()
{
}

void Mu�eco::Mueve(float t) //Funcion para que el mu�eco tenga movimiento
{

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.x <= -8) posicion.x = -8; //si la posicion x es <=-8 (izq del todo) se limita la posicion
	if (posicion.y <= 2.5) 
	{
		posicion.y = 2.5; //si la posicion y es menor que 2.5(suelo) se limita
		velocidad.y = 0; 
	}
	if (posicion.y >= 7) posicion.y = 7; //si la posicion y es mayor que 7(techo) se limita
	if (posicion.x >= fin)
	{
		posicion.x = fin;
		velocidad.x = 0;
	}
	cout << velocidad.x << " " << velocidad.y<<endl;
	cout << aceleracion.y << endl;
	sprite_vq.loop();
	sprite_fq.loop();
	sprite_vd.loop();
	sprite_fd.loop();
	sprite_ve.loop();
	sprite_fe.loop();
	sprite_vm.loop();
	sprite_fm.loop();
	sprite_va.loop();
	sprite_fa.loop();

}

int Mu�eco::SetSexo(unsigned char key)
{
	sexo = 2;
	if (key == 'F' || key == 'f')
		sexo = 0;

	if (key == 'V' || key == 'v')
		sexo = 1;
	cout << sexo << endl;
	return sexo;
}
int Mu�eco::SetCarrera(unsigned char key)
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

	Mu�eco::SetPersonaje();
	cout << carrera << endl;

	if (carrera == 5)
		return 0;
	else return 1;
}
void Mu�eco::SetPersonaje() {
	switch (carrera)
	{
	case 0://Escogemos quimica
		if (sexo == 1) {
			setvq();
			setguardamu�eco(0);
		}
		else {
			setfq();
			setguardamu�eco(1);
		}
		break;

	case 1: //Dise�o
		if (sexo == 1) {
			setvd();
			setguardamu�eco(2);
		}
		else {
			setfd();
			setguardamu�eco(3);
		}
		break;

	case 2: //Electrica
		if (sexo == 1) {
			setve();
			setguardamu�eco(4);
		}
		else {
			setfe();
			setguardamu�eco(5);
		}

		break;

	case 3: //Mecanica
		if (sexo == 1) {
			setvm();
			setguardamu�eco(6);
		}
		else {
			setfm();
			setguardamu�eco(7);
		}

		break;

	case 4: //Electronica
		if (sexo == 1) {
			setva();
			setguardamu�eco(8);
		}
		else {
			setfa();
			setguardamu�eco(9);
		}
		break;
	}
}
void Mu�eco::Dibuja()
{

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (velocidad.x > 0.06)activo->flip(false, false);
	if (velocidad.x < -0.06)activo->flip(true, false);
	activo->draw();

	glPopMatrix();

}
void Mu�eco::TeclaEspecial(unsigned char key) {

	switch (key)
	{
		//Modificar los atributos 
	case GLUT_KEY_LEFT:
		SetVel(-5.0f, 0.0f);
		if (velocidad.y != 0)
			SetVel(5.0f, -7.0f);
		break;
	case GLUT_KEY_RIGHT:
		SetVel(5.0f, 0.0f);
		if (velocidad.y != 0)
			SetVel(5.0f, -7.0f);
		break;
	case GLUT_KEY_UP:
		if (getDistancia()) //para saber si puede saltar o no (solo puede saltar si esta en el suelo o en la plataforma)
			SetVel(0.0f, 7.0f);//se mete si es true
		break;

	}
}
void Mu�eco::SetVel(float vx, float vy)
{

	velocidad.x = vx;
	velocidad.y = vy;

}
bool  Mu�eco::getDistancia(void)
{
	if (Mu�eco::posicion.y == 2.5 || aux == 1) {//si el mu�eco esta en el suelo o encima de una plataforma
		aux = 0;//interaccion
		return true;
	}
	return false;
}

void Mu�eco::SetPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
