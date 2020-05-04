#include "Nivel1.h"


Nivel1::Nivel1()
{
	//DE MOMENTO NADA
}
Nivel1:: ~Nivel1() 
{

}

void Nivel1::Mueve(float)
{
	Muñeco.Mueve(0.025f);
	//Proyectil.Mueve() falta por hacer
	//AQUI FALTAN TODAS LAS INTERACCIONES
}
 
void Nivel1::Inicializa()
{
	Plataforma.SetColor(148, 26, 28);
	Plataforma.SetPos(2, 4);//Hay que poner mas plataformas y mirar su posicion
	//Plataforma.SetVel(5, 15); DE MOMENTO NO SE MUEVEN
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	//Creditos.SetPos(5.0f, 5.0f);
	//Proyectil.SetPos(-5.0f, 0.0f);
}

void Nivel1::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,
		0.0, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	Vida.Dibuja();
	Muñeco.Dibuja();
	Plataforma.Dibuja();
	//Creditos.Dibuja(); EN CREDITO AUN NO HEMOS PUESTO LA FUNCIÓN DIBUJA
}