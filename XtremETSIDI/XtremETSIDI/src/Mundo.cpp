#include "Mundo.h"
#include "glut.h"
#include "ETSIDI.h"


MundoXtremETSIDI::MundoXtremETSIDI()  //Construyo el Menu
{
	estado = START; //Comienza el juego y estamos en START
	//ETSIDI::playMusica("bin/bso/intro.mp3", true); //Al empezar el juego se activa la múscia de inicio
	nivel1.Inicializa(suelo, creditos, proyectil, vida1);//inicializa los valores de plataforma, plataforma2.....

}

MundoXtremETSIDI::~MundoXtremETSIDI() //Destructor
{
}


void MundoXtremETSIDI::Dibuja() //Para dibujar en pantalla los distintos estados
{
	if (estado != NIVEL1) //si no estas en nivel 1 se cambia la posicion del ojo a 0.0
		gluLookAt(0.0, 4.5, 13,   // Posición del ojo si esta en el menu
			0.0, 4.5, 0.0,
			0.0, 1.0, 0.0);
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
		ojo = nivel1.muñeco.posicion.x; // recoge la posicion x del muñeco en la variable ojo MIRAR BIEN
		if (ojo <= 0) ojo = 0;
		gluLookAt(ojo, 4.5, 13,   // Posición del ojo si esta jugando
			ojo, 4.5, 0.0,
			0.0, 1.0, 0.0);
		//muñeco.Dibuja();
		nivel1.Dibuja();
		//plataforma.Dibuja();
		//plataforma2.Dibuja();
		//suelo.Dibuja();
		//Creditos.Dibuja(); EN CREDITO AUN NO HEMOS PUESTO LA FUNCIÓN DIBUJA
		vida1.GetMov(ojo);
		vida1.Dibuja();
		OpenGL::Print("CREDITOS: 0", 300, 60, 0, 0, 0); //HAY QUE HACER UN CONTADOR

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
	
		estado = NIVEL1; //Andrea luego quitalo
		nivel1.setvq();
	
						
						//estado = MENU;

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
			if (nivel1.muñeco.SetSexo(key) == 1 && key != 13)
				estado = ESCOGE_CARRERAV;
			else if (nivel1.muñeco.SetSexo(key) == 0 && key != 13)
				estado = ESCOGE_CARRERAF;
		}
		break;

	case ESCOGE_CARRERAF: //Hacer ifs en otras pantallas (flags) con valores
		if (key == 27)
			estado = ESCOGE_SEXO;
		else {
			if (nivel1.muñeco.SetCarrera(key) && aux == 0 && key != 13)
				estado = CARTA;
			else if (nivel1.muñeco.SetCarrera(key) && key != 13)
				estado = NIVEL1;  // en el caso de que ya se haya pasado por el estado NIVEL1 anteriormente 
								 //y vuelve al menu, no pasaría por los estados CARTA ni SUERTE
		}
		Musica();
		break;

	case ESCOGE_CARRERAV:
		if (key == 27)
			estado = ESCOGE_SEXO;
		else {
			if (nivel1.muñeco.SetCarrera(key) && aux == 0 && key != 13)
				estado = CARTA;
			else if (nivel1.muñeco.SetCarrera(key) && key != 13)
				estado = NIVEL1;   // en el caso de que ya se haya pasado por el estado NIVEL1 anteriormente 
								  //y vuelve al menu, no pasaría por los estados CARTA ni SUERTE
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
			//estado = MENU;
			aux++;
			exit(0);
			//Musica();
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

	//muñeco.TeclaEspecial(key);
	nivel1.TeclaEspecial(key);
}

void MundoXtremETSIDI::Mueve()
{
	//muñeco.Mueve(0.025f);
	//Interaccion::Colision(plataforma, muñeco);
	//Interaccion::Colision(plataforma2, muñeco); //hacer interaccion por cada plataforma
	nivel1.Mueve();

}