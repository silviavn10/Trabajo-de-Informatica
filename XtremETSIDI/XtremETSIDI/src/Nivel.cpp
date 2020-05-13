#include "Nivel.h"
#include "ETSIDI.h"
#include "glut.h"

Nivel::Nivel()
{
	//DE MOMENTO NADA
}
Nivel:: ~Nivel()
{

}

void Nivel::Mueve()
{

	//Proyectil.Mueve() falta por hacer
	//AQUI FALTAN TODAS LAS INTERACCIONES
}

void Nivel::Inicializa()
{
	Plataforma.SetColor(148, 26, 28);
	Plataforma.SetPos(2, 3);//Hay que poner mas plataformas y mirar su posicion
	//Plataforma.SetVel(5, 15); DE MOMENTO NO SE MUEVEN
	//x_ojo = 0;
	//y_ojo = 7.5;
	//z_ojo = 30;
	//Creditos.SetPos(5.0f, 5.0f);
	//Proyectil.SetPos(-5.0f, 0.0f);
	//Suelo.SetPos();
	//Vida.SetPos(2, 6);

}

void Nivel::Dibuja()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/nivel1.png").id); //foto pasillo

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(180, -0.25, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(180, 9.25, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	Plataforma.Dibuja();
	Suelo.Dibuja();
	//Caja.Dibuja();
	//Creditos.Dibuja(); EN CREDITO AUN NO HEMOS PUESTO LA FUNCIÓN DIBUJA
}

void Nivel::TeclaEspecial(unsigned char key)
{


}