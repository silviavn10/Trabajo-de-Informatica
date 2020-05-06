#include "Menu.h"
#include "ETSIDI.h"
//#include "Muñeco.h"
#include <iostream>
#include "glut.h"
 
MenuXtremETSIDI::MenuXtremETSIDI()  //Construyo el Menu
{
	estado = START; //Comienza el juego y estamos en START

	ETSIDI::playMusica("bin/bso/intro.mp3", true); //Al empezar el juego se activa la múscia de inicio
	
}

MenuXtremETSIDI::~MenuXtremETSIDI() //Destructor
{
}

//Muñeco muñeco;

void MenuXtremETSIDI::Dibuja() //Para dibujar en pantalla los distintos estados
{
	switch (estado) {

	case START:  //Estado de INICIO

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/start.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case MENU: //Menu princupal (comenzar, controles, salir)

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/menu.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;


	case CONTROLES:

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/controles.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case ESCOGE_SEXO: //escoger chico o chica

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/escoge_sexo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case ESCOGE_CARRERAF: //escoge la chica

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/escoge_f.png").id); //foto chicas 5 carreras
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	
	case ESCOGE_CARRERAV: //escoge chico

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/escoge_v.png").id); //foto chico 5 carreras
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case CARTA: //Presentacion a la politecnica

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/carta.png").id); //foto correo
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		
		break;
	
	case SUERTE: //Deseamos animo

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/suerte.png").id); //foto animo
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case NIVEL1: //Comenzamos el juego

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/nivel1.png").id); //foto animo
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case VICTORIA: //Has ganado

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/victoria.png").id); //foto victoria
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case GAMEOVER: //Has perdido

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/gameover.png").id); //foto derrrota
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;

	case FIN: //Acabado

		gluLookAt(0, 4.5, 13,   // Posición del ojo
			0.0, 4.5, 0.0,      // Hacia qué punto mira  (0,0,0) 
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fin.png").id); //foto fin del juego
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);


		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(9.7, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(9.7, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	}

}

void MenuXtremETSIDI::Tecla(unsigned char key)
{
	switch (estado)
	{
	case START:
		if (key == 27)
			exit(0);
		if (key == 13)  //Pulsa el enter para continuar
			estado = MENU;
		break;

	case MENU:
		if (key == 27)
			exit(0);
		if (key == 'C' || key == 'c')
			estado = CONTROLES;
		if (key == 13)   //comenzar juego
			estado = ESCOGE_SEXO;
		break;

	case CONTROLES:
		if (key == 27)
			estado = MENU;
		break;

	case ESCOGE_SEXO:
		if (key == 27)
			estado = MENU;
		if (key == 'F' || key == 'f')
		{
			estado = ESCOGE_CARRERAF;
			//muñeco.SetSexo(0);
		}
		if (key == 'V' || key == 'v')
		{
			estado = ESCOGE_CARRERAV;
			//muñeco.SetSexo(1);
		}
		break;

	case ESCOGE_CARRERAF: //Hacer ifs en otras pantallas (flags) con valores
		if (key == 27)
			estado = ESCOGE_SEXO;
		if (key == 'Q' || key == 'q')
		{
			estado = CARTA;
			//muñeco.SetCarrera(0);
		}
		if (key == 'D' || key == 'd')
		{
			estado = CARTA;
			//muñeco.SetCarrera(1);
		}	
		if (key == 'E' || key == 'e')
		{
			estado = CARTA;
			//muñeco.SetCarrera(2);
		}
		if (key == 'M' || key == 'm')
		{
			estado = CARTA;
			//muñeco.SetCarrera(3);
		}	
		if (key == 'A' || key == 'a')
		{
			estado = CARTA;
			//muñeco.SetCarrera(4);
		}
			
		Musica();
		break;

	case ESCOGE_CARRERAV: //Hacer ifs en otras pantallas (flags) con valores 
		if (key == 27)
			estado = ESCOGE_SEXO;
		if (key == 'Q' || key == 'q')
		{
			estado = CARTA;
			//muñeco.SetCarrera(0);
		}	
		if (key == 'D' || key == 'd')
		{
			estado = CARTA;
			//muñeco.SetCarrera(1);
		}	
		if (key == 'E' || key == 'e')
		{
			estado = CARTA;
			//muñeco.SetCarrera(2);
		}	
		if (key == 'M' || key == 'm')
		{
			estado = CARTA;
			//muñeco.SetCarrera(3);
		}	
		if (key == 'A' || key == 'a')
		{
			estado = CARTA;
			//muñeco.SetCarrera(4);
		}
		
		Musica();
		break;

	case CARTA:
		if (key == 27)
		{
			estado = MENU;
			Musica();
		}
		if (key == 13)
			estado = SUERTE;
		break;

	case SUERTE:
		if (key == 27)
		{
			estado = MENU;
			Musica();
		}
		if (key == 13)
		{
			estado = NIVEL1;
			Musica();
		}
		break;

	case NIVEL1:
		if (key == 27)
		{
			estado = MENU;
			Musica();
		}
		break;
	}


	/*   
		 || (estado == GAMEOVER) || (estado == FIN) || (estado == M_PRINCIPAL) ||
		 || (estado == VICTORIA) //FALTAN NIVELES Y PANTALLA DE NIVEl*/
}

void MenuXtremETSIDI::Musica()
{
	switch (estado)
	{
		case CARTA:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/carta.mp3", true);
		break;
		
		case MENU:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/intro.mp3", true);
		break;

		case NIVEL1:
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/nivel1.mp3", true);
			break;
	}
	
}

/*void MenuXtremETSIDI::TeclaEspecial(unsigned char key)
{

}
*/