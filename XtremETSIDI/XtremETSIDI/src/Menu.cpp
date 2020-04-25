#include "Menu.h"
#include "ETSIDI.h"
#include <iostream>
 
MenuXtremETSIDI::MenuXtremETSIDI()  //Construyo el Menu
{
	estado = START; //Comienza el juego y estamos en START

	ETSIDI::playMusica("bso/intro.mp3", true); //Al empezar el juego se activa la múscia de inicio
}

MenuXtremETSIDI::~MenuXtremETSIDI() //Destructor
{
	
}

void MenuXtremETSIDI::Dibuja() //Para dibujar en pantalla los distintos estados
{
	if (estado == START)  //Estado de INICIO
	{
		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/start.jpg").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.1, 0, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.1, 0, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.1, 9, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.1, 9, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

/*void MenuXtremETSIDI::Tecla(unsigned char key)
{
	if ((estado == START) || (estado == MENU) || (estado == ESCOGE_CARRERA) || (estado == ESCOGE_A) || (estado == ESCOGE_E) || (estado == ESCOGE_M) ||
		(estado == ESCOGE_D) || (estado == ESCOGE_Q) || (estado == ESCOGE_SEXO) || (estado == ESCOGE_F) || (estado == ESCOGE_V) ||
		(estado == CONTROLES) || (estado == GAMEOVER) || (estado == FIN) || (estado == CARATULA) || (estado == M_PRINCIPAL) ||
		(estado == COMENZAR) || (estado == SALIR) || (estado == CARTA) || (estado == SUERTE) || (estado == VICTORIA)) //FALTAN NIVELES Y PANTALLA DE NIVEl
}*/