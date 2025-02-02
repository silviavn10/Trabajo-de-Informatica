#include "Vida.h"
#include "glut.h"

Vida::Vida() //Constructor
{
}

Vida::~Vida() //Destructor
{

}

float Vida::GetMov(float x) //Funcion para obtener los valores de mu�eco.posicion.x a traves del mundo.cpp
{
	Mov = x;
	if (Mov < 0)
		return Mov = 0;
	return Mov;
}

void Vida::Dibuja() //Vida ordinaria
{

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/vidaordinaria.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(Mov - 8.5, 8, 0.1);
	glTexCoord2d(1, 1);		glVertex3f(Mov - 6.5, 8, 0.1);
	glTexCoord2d(1, 0);		glVertex3f(Mov - 6.5, 9, 0.1);
	glTexCoord2d(0, 0);		glVertex3f(Mov - 8.5, 9, 0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
	
}

void Vida::Dibuja2() //Vida de julio
{

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/vidajulio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(Mov - 8.5, 8, 0.1);
	glTexCoord2d(1, 1);		glVertex3f(Mov - 6.5, 8, 0.1);
	glTexCoord2d(1, 0);		glVertex3f(Mov - 6.5, 9, 0.1);
	glTexCoord2d(0, 0);		glVertex3f(Mov - 8.5, 9, 0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


}
