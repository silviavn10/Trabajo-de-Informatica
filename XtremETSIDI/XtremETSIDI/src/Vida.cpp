#include "Vida.h"
#include "glut.h"

Vida::Vida() //Constructor
{
	radio = 0.6f;
}

Vida::~Vida() //Destructor
{

}

void Vida::Dibuja()
{
	gluLookAt(0, 4.5, 13,   // Posición del ojo
		0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
		0.0, 1.0, 0.0);
	//CAMBIAR LAS COORDENADAS
	
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/vida.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	

	glTexCoord2d(0, 1);		glVertex3f(-5, -0.25, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(5, -0.25, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(5, 9.25, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-5, 9.25, -0.1);
	glEnd();
	
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
void Vida::SetPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}
	
