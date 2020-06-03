#include "Mundo.h"
#include "glut.h"


// MUNDO ES EL COORDINADOR DEL JUEGO

// DESDE MUNDO SE LLAMA A LOS DISTINTOS NIVELES


MundoXtremETSIDI::MundoXtremETSIDI()  //Construyo el Menu
{
	estado = START;                                  //Comienza el juego y estamos en START
	ETSIDI::playMusica("bin/bso/intro.mp3", true);   //Al empezar el juego se activa la múscia de inicio
	aux = 0;
	guardanivel = 0;
	ojo = 0;

}

MundoXtremETSIDI::~MundoXtremETSIDI() //Destructor
{

}

void MundoXtremETSIDI::Dibuja()              //Para dibujar en pantalla los distintos estados
{
	if (estado != NIVEL1&& estado !=FIN)     //si no estas en nivel 1 se cambia la posicion del ojo a 0.0
		gluLookAt(0.0, 4.5, 13,              // Posición del ojo si esta en el menu
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
		nivel1.ValorVida(2);
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
		ojo = nivel1.muñeco.getPosX();   // recoge la posicion x del muñeco en la variable ojo MIRAR BIEN
		if (ojo <= 0) ojo = 0;
		gluLookAt(ojo, 4.5, 13,          // Posición del ojo si esta jugando
			ojo, 4.5, 0.0,
			0.0, 1.0, 0.0);
		
		nivel1.Dibuja();
		vida1.GetMov(ojo);

		if (nivel1.SetVida() == 2)        // Vida en la convocatoria ordinaria
			vida1.Dibuja();

		if (nivel1.SetVida() == 1) {      // Vida en la convocatoria de julio
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/julio.mp3", true);
			guardanivel = 1;
			estado = JULIO;
		}

		if (nivel1.muñeco.getPosX() == nivel1.muñeco.getfin()) //Si el muñeco llega al final del nivel pasa al siguiente
		{
			nivel2.Inicializa2();
			switch (nivel1.muñeco.getguardamuñeco()) {         //Dibuja el muñeco escogido en primer nivel
			case 0:
				nivel2.setvq();
				break;
			case 1:
				nivel2.setfq();
				break;
			case 2:
				nivel2.setvd();
				break;
			case 3:
				nivel2.setfd();
				break;
			case 4:
				nivel2.setve();
				break;
			case 5:
				nivel2.setfe();
				break;
			case 6:
				nivel2.setvm();
				break;
			case 7:
				nivel2.setfm();
				break;
			case 8:
				nivel2.setva();
				break;
			case 9:
				nivel2.setfa();
				break;
			}
			estado = NIVEL2;
			Musica();
		}
	
		break;

	case NIVEL2: 
		ojo = nivel2.muñeco.getPosX();
		if (ojo <= 0) ojo = 0;
		gluLookAt(ojo, 0, 0.01,  
			ojo, 0, 0.0,
			0.0, 1.0, 0.0);

		nivel2.Dibuja();
		vida1.GetMov(ojo);

		if (nivel2.SetVida() == 2)                   // Vida en la convocatoria ordinaria
			vida1.Dibuja();

		if (nivel2.SetVida() == 1)                   // Vida en la convocatoria de julio
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/julio.mp3", true);
			guardanivel = 2;
			estado = JULIO;
		}
	
		if (nivel2.muñeco.getPosX() == nivel2.muñeco.getfin())  //Si el muñeco llega a la posicion final pasa al siguiente nivel
		{
			nivel3.Inicializa();
			nivel3.Inicializa();
			switch (nivel1.muñeco.getguardamuñeco()) {           //Se dubuja el muñeco escogido en el primer nivel
			case 0:
				nivel3.setvq();
				break;
			case 1:
				nivel3.setfq();
				break;
			case 2:
				nivel3.setvd();
				break;
			case 3:
				nivel3.setfd();
				break;
			case 4:
				nivel3.setve();
				break;
			case 5:
				nivel3.setfe();
				break;
			case 6:
				nivel3.setvm();
				break;
			case 7:
				nivel3.setfm();
				break;
			case 8:
				nivel3.setva();
				break;
			case 9:
				nivel3.setfa();
				break;
			}
			
			estado = NIVEL3;
			
			Musica();
		}
		break;

	case NIVEL3: 
		ojo = nivel3.muñeco.getPosX(); 
		if (ojo <= 0) ojo = 0;
		gluLookAt(ojo, 0, 0.01,   
			ojo, 0, 0.0,
			0.0, 1.0, 0.0);

		nivel3.Dibuja();
		vida1.GetMov(ojo);

		if (nivel3.SetVida() == 2)                   // Vida en la convocatoria ordinaria
			vida1.Dibuja();
		if (nivel3.SetVida() == 1) {                 // Vida en la convocatoria de julio
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/julio.mp3", true);
			guardanivel = 3;
			estado = JULIO;
		}
		
		if (nivel3.muñeco.getPosX() == nivel3.muñeco.getfin())  //Si llega a la posicion final pasa al estado de VICTORIA
		{
			estado = VICTORIA;
			Musica();
		}
		break;

	case JULIO:
		if (guardanivel == 1) {                                        //Convocarotia de julio si estabamos en el nivel 1
			ojo = nivel1.muñeco.getPosX();
			gluLookAt(ojo, 0, 0.01,
				ojo, 0, 0.0,
				0.0, 1.0, 0.0);
			nivel1.Dibuja();
			vida1.GetMov(ojo);

			if (nivel1.SetVida() == 1)                                  //Vida en convocatoria de julio
				vida1.Dibuja2();

			if (nivel1.SetVida() == 0) {                                //Si te matan en la convocaoria de julio pierdes el juego
				estado = GAMEOVER;
				ETSIDI::stopMusica();
				ETSIDI::playMusica("bin/bso/gameover.mp3", true);
			}

			if (nivel1.muñeco.getPosX() == nivel1.muñeco.getfin())       //Si el muñeco llega al final del nivel pasa al siguiente
			{
				nivel2.Inicializa2();
				switch (nivel1.muñeco.getguardamuñeco()) {               //Dibuja el muñeco escogido en primer nivel
				case 0:
					nivel2.setvq();
					break;
				case 1:
					nivel2.setfq();
					break;
				case 2:
					nivel2.setvd();
					break;
				case 3:
					nivel2.setfd();
					break;
				case 4:
					nivel2.setve();
					break;
				case 5:
					nivel2.setfe();
					break;
				case 6:
					nivel2.setvm();
					break;
				case 7:
					nivel2.setfm();
					break;
				case 8:
					nivel2.setva();
					break;
				case 9:
					nivel2.setfa();
					break;
				}
				estado = NIVEL2;
				Musica();
			}
		}
		if (guardanivel == 2) {                                        //Convocarotia de julio si estabamos en el nivel 2
			ojo = nivel2.muñeco.getPosX();
			gluLookAt(ojo, 0, 0.01,
				ojo, 0, 0.0,
				0.0, 1.0, 0.0);

			nivel2.Dibuja();
			vida1.GetMov(ojo);

			if (nivel2.SetVida() == 1)                                  //Vida en convocatoria de julio
				vida1.Dibuja2();

			if (nivel2.SetVida() == 0) {                                //Si te matan en la convocaoria de julio pierdes el juego
				estado = GAMEOVER;
				ETSIDI::stopMusica();
				ETSIDI::playMusica("bin/bso/gameover.mp3", true);
			}
			if (nivel2.muñeco.getPosX() == nivel2.muñeco.getfin())      //Si el muñeco llega al final del nivel pasa al siguiente
			{
				nivel3.Inicializa();
				switch (nivel1.muñeco.getguardamuñeco()) {              //Dibuja el muñeco escogido en primer nivel
				case 0:
					nivel3.setvq();
					break;
				case 1:
					nivel3.setfq();
					break;
				case 2:
					nivel3.setvd();
					break;
				case 3:
					nivel3.setfd();
					break;
				case 4:
					nivel3.setve();
					break;
				case 5:
					nivel3.setfe();
					break;
				case 6:
					nivel3.setvm();
					break;
				case 7:
					nivel3.setfm();
					break;
				case 8:
					nivel3.setva();
					break;
				case 9:
					nivel3.setfa();
					break;
				}
				estado = NIVEL3;

				Musica();
			}
		}
		if (guardanivel == 3) {                                        //Convocarotia de julio si estabamos en el nivel 3
			ojo = nivel3.muñeco.getPosX();
			gluLookAt(ojo, 0, 0.01,
				ojo, 0, 0.0,
				0.0, 1.0, 0.0);
			nivel3.Dibuja();
			vida1.GetMov(ojo);

			if (nivel3.SetVida() == 1)                                  //Vida en convocatoria de julio
				vida1.Dibuja2();

			if (nivel3.SetVida() == 0) {                                //Si te matan en la convocaoria de julio pierdes el juego
				estado = GAMEOVER;
				ETSIDI::stopMusica();
				ETSIDI::playMusica("bin/bso/gameover.mp3", true);
			}

			if (nivel3.muñeco.getPosX() == nivel3.muñeco.getfin())       //Si el muñeco llega al final del nivel pasa al estado VICTORIA
			{
				estado = VICTORIA;
				Musica();
			}
		}

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
	
		gluLookAt(0.0, 8 , 10,   // Posición del ojo si esta en el menu
			0.0, 4.5, 0.0,
			0.0, 1.0, 0.0);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/creditosfin.png").id); //foto fin del juego
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
		if (key == 27)              //Pulsa esc para salir
			exit(0);
		if (key == 13) {            //Pulsa el enter para continuar
			nivel1.Inicializa();
			Musica();
			key = '0';
			estado = MENU;          
		}
		if (key == '1')             //Para pasar DIRECTAMENTE al nivel 1 
		{
			nivel1.Inicializa();
			key = '0';
			estado = NIVEL1;
			nivel1.setvq();         //Al saltarse la parte de eleccion inicial se escoge por defecto el muñeco chico-quimica
			Musica();
		}
		if (key == '2')             //Para pasar DIRECTAMENTE al nivel 2 
		{
			nivel2.Inicializa2();
			key = '0';
			estado = NIVEL2;
			nivel2.setvq();         //Al saltarse la parte de eleccion inicial se escoge por defecto el muñeco chico-quimica
			Musica();
		}
		if (key == '3')             //Para pasar DIRECTAMENTE al nivel 3
		{
			nivel3.Inicializa();
			key = '0';
			estado = NIVEL3;
			nivel3.setvq();         //Al saltarse la parte de eleccion inicial se escoge por defecto el muñeco chico-quimica
			Musica();
		}
		break;
	case MENU:
		if (key == 27)              //Pulsa esc para salir
			exit(0);
		if (key == 'C' || key == 'c')
			estado = CONTROLES;
		if (key == 13)              //comenzar juego
			estado = ESCOGE_SEXO;
		break;

	case CONTROLES:
		if (key == 27)              //Pulsa esc para volver al MENU
			estado = MENU;
		break;

	case ESCOGE_SEXO:
		if (key == 27)              //Pulsa esc para volver al MENU
			estado = MENU;
		else {
			if (nivel1.muñeco.SetSexo(key) == 1 && key != 13)        //Se escoge chico
				estado = ESCOGE_CARRERAV;
			else if (nivel1.muñeco.SetSexo(key) == 0 && key != 13)   //Se escoge chica
				estado = ESCOGE_CARRERAF;
		}
		break;

	case ESCOGE_CARRERAF:           //Se ha escogido chica y se tiene que escoger carrera
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

	case ESCOGE_CARRERAV:           //Se ha escogido chico y se tiene que escoger carrera
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
		if (key == 27)              //Pulsa esc para volver al MENU
		{
			estado = MENU;
			Musica();
		}
		if (key == 13)              //Pulsa enter para pasar a la siguiente pantalla
			estado = SUERTE;
		break;

	case SUERTE:
		if (key == 27)              //Pulsa esc para volver al MENU
		{
			estado = MENU;
			Musica();
		}

		if (key == 13)              //Pulsa enter para empezar a jugar
		{
			nivel1.Inicializa();
			estado = NIVEL1;
			Musica();
		}
		break;

	case NIVEL1:
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			aux++;
			Musica();
		}
		if (key == 50)              // Para pasar DIRECTAMENTE al nivel 2 se puede pulsar "2"
		{
			nivel2.Inicializa2();
			key = '0';

			switch (nivel1.muñeco.getguardamuñeco()) {  //Se guarda la eleccion de muñeco hecha en el nivel 1 y se inicializa para el 2
			case 0:
				nivel2.setvq();
				break;
			case 1:
				nivel2.setfq();
				break;
			case 2:
				nivel2.setvd();
				break;
			case 3:
				nivel2.setfd();
				break;
			case 4:
				nivel2.setve();
				break;
			case 5:
				nivel2.setfe();
				break;
			case 6:
				nivel2.setvm();
				break;
			case 7:
				nivel2.setfm();
				break;
			case 8:
				nivel2.setva();
				break;
			case 9:
				nivel2.setfa();
				break;
			}
			Musica();
			estado = NIVEL2;
		}
		break;

	case NIVEL2:
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			aux++;
			Musica();
		}
		if (key == '3')              // Para pasar DIRECTAMENTE al nivel 3 se puede pulsar "3"
		{
			nivel3.Inicializa();
			estado = NIVEL3;
			key = '0';
			switch (nivel1.muñeco.getguardamuñeco()) {//Se guarda la eleccion de muñeco hecha en el nivel 1 y se inicializa para el 3
			case 0:
				nivel3.setvq();
				break;
			case 1:
				nivel3.setfq();
				break;
			case 2:
				nivel3.setvd();
				break;
			case 3:
				nivel3.setfd();
				break;
			case 4:
				nivel3.setve();
				break;
			case 5:
				nivel3.setfe();
				break;
			case 6:
				nivel3.setvm();
				break;
			case 7:
				nivel3.setfm();
				break;
			case 8:
				nivel3.setva();
				break;
			case 9:
				nivel3.setfa();
				break;
			}
			Musica();
		}
		break;

	case NIVEL3:
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			aux++;
			Musica();
		}
		break;

	case JULIO:
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			aux++;
			Musica();
		}
		if (key == 50)              // Para pasar DIRECTAMENTE al nivel 2 se puede pulsar "2"
		{
			if (guardanivel == 1) {

				ETSIDI::stopMusica();
				ETSIDI::playMusica("bin/bso/nivel1.mp3", true);
				nivel2.Inicializa2();
				key = '0';
				switch (nivel1.muñeco.getguardamuñeco()) { //Se guarda la eleccion de muñeco hecha en el nivel 1 y se inicializa para el 2
				case 0:
					nivel2.setvq();
					break;
				case 1:
					nivel2.setfq();
					break;
				case 2:
					nivel2.setvd();
					break;
				case 3:
					nivel2.setfd();
					break;
				case 4:
					nivel2.setve();
					break;
				case 5:
					nivel2.setfe();
					break;
				case 6:
					nivel2.setvm();
					break;
				case 7:
					nivel2.setfm();
					break;
				case 8:
					nivel2.setva();
					break;
				case 9:
					nivel2.setfa();
					break;
				}
				Musica();
				estado = NIVEL2;
			}
		}

		if (key == 51)              // Para pasar DIRECTAMENTE al nivel 3 se puede pulsar "3"
		{
			if (guardanivel == 2) {
				ETSIDI::stopMusica();
				ETSIDI::playMusica("bin/bso/corona.mp3", true);
				nivel3.Inicializa();
				key = '0';
				switch (nivel1.muñeco.getguardamuñeco()) {//Se guarda la eleccion de muñeco hecha en el nivel 1 y se inicializa para el 3
				case 0:
					nivel3.setvq();
					break;
				case 1:
					nivel3.setfq();
					break;
				case 2:
					nivel3.setvd();
					break;
				case 3:
					nivel3.setfd();
					break;
				case 4:
					nivel3.setve();
					break;
				case 5:
					nivel3.setfe();
					break;
				case 6:
					nivel3.setvm();
					break;
				case 7:
					nivel3.setfm();
					break;
				case 8:
					nivel3.setva();
					break;
				case 9:
					nivel3.setfa();
					break;
				}
				Musica();
				estado = NIVEL3;
			}


		}
		break;

	case GAMEOVER:
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			Musica();
		}
		if (key == 13)              //Pulsa enter para salir del juego
		{
			exit(0);
			Musica();
		}
		break;

	case VICTORIA:
		if (key == 27)              //Pulsa esc para ir al estado FIN
		{
			estado = FIN;
			Musica();
		}
		if (key == 13)              //Pulsa enter para ir al estado FIN
		{
			estado = FIN;
			Musica();
		}
		break;

	case FIN:
		if (key == 27)              //Pulsa esc para salir del juego
		{
			exit(0);
			Musica();
		}
		if (key == 13)              //Pulsa enter para salir del juego
		{
			exit(0);
			Musica();
		}
		break;
	}
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

		if (nivel1.SetVida() == 2)
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/nivel1.mp3", true);
		}
		break;

	case NIVEL2:

		ETSIDI::stopMusica();
		if (nivel2.SetVida() == 2) { ETSIDI::playMusica("bin/bso/nivel1.mp3", true); }
		if (nivel2.SetVida() == 1) {
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/julio.mp3", true);
		}
		break;

	case NIVEL3:
		ETSIDI::stopMusica();
		if (nivel3.SetVida() == 2) { ETSIDI::playMusica("bin/bso/corona.mp3", true); }
		if (nivel3.SetVida() == 1) {
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/julio.mp3", true);
		}
		break;

	case VICTORIA:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("bin/bso/victoria.mpeg", true);
		break;
	}

}

void MundoXtremETSIDI::TeclaEspecial(unsigned char key)
{
	nivel1.TeclaEspecial(key);
	nivel2.TeclaEspecial(key);
	nivel3.TeclaEspecial(key);
}

void MundoXtremETSIDI::Mueve()
{
	if (estado == NIVEL1)       //El juego está en el primer nivel
	{
		nivel1.Mueve();         //Se llama a la función mueve de espacio para controlar los distintos objetos que aparecen en pantalla
	}

	if (estado == NIVEL2)       //El juego está en el segundo nivel
	{
		nivel2.Mueve();         
	}

	if (estado == NIVEL3)       //El juego está en el tercer nivel
	{
		nivel3.Mueve();         
	}
	if (estado == JULIO)        //El juego está en la convocatoria de julio
	{
		if(guardanivel==1)      //Si estaba en el nivel 1 e llama a la función mueve DEL NIVEL 1 para controlar los distintos objetos que aparecen en pantalla
		   nivel1.Mueve();         

		if (guardanivel == 2)   //Si estaba en el nivel 2 e llama a la función mueve DEL NIVEL 2 para controlar los distintos objetos que aparecen en pantalla
			nivel2.Mueve();

		if (guardanivel == 3)   //Si estaba en el nivel 3 e llama a la función mueve DEL NIVEL 3 para controlar los distintos objetos que aparecen en pantalla
			nivel3.Mueve();
	}
}


