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

Mu�eco::~Mu�eco()
{
}

void Mu�eco::Mueve(float t) //Funcion para que el mu�eco tenga movimiento
{
	
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	
	//activo->loop(); //Funcion interna de los sprites
	
}

int Mu�eco::SetSexo(unsigned char key)
{
	sexo = 2;
	if (key == 'F' || key == 'f')
			sexo = 0;
				
	if (key == 'V' || key == 'v')
		sexo = 1;
	cout << sexo<< endl;
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
	cout << carrera<<endl;
	
	if(carrera==5)
		return 0;
	else return 1;
}
void Mu�eco::SetPersonaje() {
	switch (carrera)
	{
	case 0://Escogemos quimica
		if (sexo == 1)  setvq();
		else setfq();
		break;

	case 1: //Dise�o
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
void Mu�eco::Dibuja()
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
void Mu�eco::TeclaEspecial(unsigned char key) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Mu�eco::SetVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		Mu�eco::SetVel(5.0f, 0.0f);
		break;
	case GLUT_KEY_UP:

		for (int i = 0; i < MAX_PLATAFORMAS; i++) {
			if (-0.1 < (Mu�eco::getPosY() - (Plataforma.GetLimiteY2())) < 0.1) Mu�eco::setVelY(15.0f);
		}
		if (-0.1 < (Mu�eco::getPosY() - (Plataforma.GetLimiteY2())) < 0.1) Mu�eco::setVelY(15.0f);
		if ((Mu�eco::getPosY() - Suelo.GetSueloLimiteY2()) < 0.05) {
			Mu�eco::setVelY(15.0f);
		}
		break;
	}
}

void Mu�eco::SetVel(float vx, float vy)
{
		velocidad.x = vx;
		velocidad.y = vy;
	
}

/*float Mu�eco::SetSalto(float h, float v0 = 0.0, float g = 9.8)
{
	float t = (-v0 + sqrt(v0 * v0 + 2 * g * h)) / g; //ecuacion de la parabola para saltar
	return v0 + g * t;
}
*/

