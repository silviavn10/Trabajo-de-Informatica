#include "Nivel1.h"
#include "ETSIDI.h"
#include "glut.h"

Nivel1::Nivel1()
{
	//DE MOMENTO NADA
}
Nivel1:: ~Nivel1() 
{

}

void Nivel1::Mueve()
{
	mu�eco.Mueve(0.025f);
	//Proyectil.Mueve() falta por hacer
	//AQUI FALTAN TODAS LAS INTERACCIONES
}
 
void Nivel1::Inicializa()
{
	Plataforma.SetColor(148, 26, 28);
	Plataforma.SetPos(2, 3);//Hay que poner mas plataformas y mirar su posicion
	//Plataforma.SetVel(5, 15); DE MOMENTO NO SE MUEVEN
	//x_ojo = 0;
	//y_ojo = 7.5;
	//z_ojo = 30;
	//Creditos.SetPos(5.0f, 5.0f);
	//Proyectil.SetPos(-5.0f, 0.0f);
	Suelo.SetPos();
	Vida.SetPos(2,6);
}

void Nivel1::Dibuja()
{
	gluLookAt(0, 4.5, 13,   // Posici�n del ojo
		0.0, 4.5, 0.0,      // Hacia qu� punto mira  (0,0,0) 
		0.0, 1.0, 0.0);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/nivel1.png").id); //foto pasillo

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);


	glTexCoord2d(0, 1);		glVertex3f(-95, -0.25, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(95, -0.25, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(95, 9.25, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-95, 9.25, -0.1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	
	
	mu�eco.Dibuja();
	Plataforma.Dibuja();
	Suelo.Dibuja();
	Vida.Dibuja();
	//Creditos.Dibuja(); EN CREDITO AUN NO HEMOS PUESTO LA FUNCI�N DIBUJA
}

void Nivel1::TeclaEspecial(unsigned char key)
{
		switch (key)
		{
		case GLUT_KEY_LEFT:
			mu�eco.SetVel(-5.0f, 0.0f);
			break;
		case GLUT_KEY_RIGHT:
			mu�eco.SetVel(5.0f, 0.0f);
			break;
		case GLUT_KEY_UP:
			for (int i = 0; i < MAX_PLATAFORMAS; i++) {
				if (-0.1 < (mu�eco.getPosY() - (Plataforma.GetLimiteY2())) < 0.1) mu�eco.setVelY(15.0f);
			}
			if (-0.1 < (mu�eco.getPosY() - (Plataforma.GetLimiteY2())) < 0.1) mu�eco.setVelY(15.0f);
			if ((mu�eco.getPosY() - Suelo.GetSueloLimiteY2()) < 0.05) {
				mu�eco.setVelY(15.0f);
			}
			break;
		}
}
