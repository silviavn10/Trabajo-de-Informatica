#include "Mundo.h"
#include "glut.h"
#include "ETSIDI.h"


MundoXtremETSIDI::MundoXtremETSIDI()  //Construyo el Menu
{
	estado = START; //Comienza el juego y estamos en START

	ETSIDI::playMusica("bin/bso/intro.mp3", true); //Al empezar el juego se activa la m�scia de inicio

}

MundoXtremETSIDI::~MundoXtremETSIDI() //Destructor
{
}


void MundoXtremETSIDI::Dibuja() //Para dibujar en pantalla los distintos estados
{
	if (mu�eco.posicion.x >= 0)
	{
		gluLookAt(mu�eco.posicion.x, 4.5, 13,   // Posici�n del ojo
			mu�eco.posicion.x, 4.5, 0.0,      // Hacia qu� punto mira  (0,0,0) 
			0.0, 1.0, 0.0);
	}
	else
	{
		gluLookAt(0.0, 4.5, 13,   // Posici�n del ojo
			0.0, 4.5, 0.0,      // Hacia qu� punto mira  (0,0,0) 
			0.0, 1.0, 0.0);
	}

	switch (estado) {

	case START:  //Estado de INICIO
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
		mu�eco.posicion.x = 0.0;

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
	
		mu�eco.Dibuja();
		nivel1.Dibuja();
		
		break;

	case VICTORIA: //Has ganado
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

void MundoXtremETSIDI::Tecla(unsigned char key)
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
		else {
			if (mu�eco.SetSexo(key)==1 && key!=13 )
				estado = ESCOGE_CARRERAV;
			else if (mu�eco.SetSexo(key) == 0 && key != 13) estado = ESCOGE_CARRERAF;
		}
		break;

	case ESCOGE_CARRERAF: //Hacer ifs en otras pantallas (flags) con valores
		if (key == 27)
			estado = ESCOGE_SEXO;
		else {
			if (mu�eco.SetCarrera(key)&& aux==0 && key != 13)
				estado = CARTA;
			else if (mu�eco.SetCarrera(key) && key != 13)estado = NIVEL1;
		}
		Musica();
		break;

	case ESCOGE_CARRERAV:  
		if (key == 27)
			estado = ESCOGE_SEXO;
		else {
			if(mu�eco.SetCarrera(key) && aux == 0 && key != 13)
				estado = CARTA;
		else if (mu�eco.SetCarrera(key) && key != 13)estado = NIVEL1;
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
			nivel1.Inicializa();
			Musica();
		}
		break;

	case NIVEL1:

		if (key == 27)
		{
			estado = MENU;
			aux++;
			Musica();
		}
		break;
	}


	/*
		 || (estado == GAMEOVER) || (estado == FIN) || (estado == M_PRINCIPAL) ||
		 || (estado == VICTORIA) //FALTAN NIVELES Y PANTALLA DE NIVEl*/
}

void MundoXtremETSIDI::Musica()
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

void MundoXtremETSIDI::TeclaEspecial(unsigned char key)
{
	mu�eco.TeclaEspecial(key);
}

void MundoXtremETSIDI::Mueve()
{
	
	mu�eco.Mueve(0.025f);
}