#include "Vida.h"
#include "Vector2D.h"
#include "ETSIDI.h"
#include "glut.h"


Vida::Vida() //Constructor
{
	
}

Vida::~Vida() //Destructor
{

}

void Vida::Dibuja(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	gluLookAt(0, 4.5, 13,   // Posición del ojo
		0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
		0.0, 1.0, 0.0);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Corazon.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	//Llamar dos veces en el menú con las coordenadas 

	glTexCoord2d(x1, y1);		glVertex3f(-9.1, 0, -0.1);
	glTexCoord2d(x2, y2);		glVertex3f(9.1, 0, -0.1);
	glTexCoord2d(x3, y3);		glVertex3f(9.1, 9, -0.1);
	glTexCoord2d(x4, y4);		glVertex3f(-9.1, 9, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}


