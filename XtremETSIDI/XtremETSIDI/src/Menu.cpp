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

void MenuXtremETSIDI::Tecla(unsigned char key)
{
	if ((estado == START) || (estado == MENU) || (estado == ESCOGE_CARRERA) || (estado == ESCOGE_A) || (estado == ESCOGE_E) || (estado == ESCOGE_M) ||
		(estado == ESCOGE_D) || (estado == ESCOGE_Q) || (estado == ESCOGE_SEXO) || (estado == ESCOGE_F) || (estado == ESCOGE_V) ||
		(estado == CONTROLES) || (estado == GAMEOVER) || (estado == FIN) || (estado == CARATULA) || (estado == M_PRINCIPAL) ||
		(estado == COMENZAR) || (estado == SALIR) || (estado == CARTA) || (estado == SUERTE) || (estado == VICTORIA)) //FALTAN NIVELES Y PANTALLA DE NIVEl
	{
		if (key == 27) // ESCAPE
		{
			exit(0);
		}
	}

	if (estado == START) //La máquina de estados se encuentra en el INICIO del juego
	{
		if (key == 13) // ENTER , Si se pulsa la tecla ENTER se inicializa el MENÚ y su correspondiente música
		{
			espacio.inicializa_N1();
			key = '0'; // Para que no se pase el menú
			estado = MENU;
			Musica();
		}

		//PARA PASAR A LOS DISTINTOS NIVELES PULSANDO TECLAS NUMÉRICAS EN VEZ DE TENER QUE SUPERAR CADA NIVEL
		if (key == '1')
		{
			espacio.inicializa_N1();
			estado = JUEGO_N1;
			musica();
		}

		if (key == '2')
		{
			espacio.inicializa_N2();
			estado = JUEGO_N2;
			musica();
		}

		if (key == '3')
		{
			espacio.inicializa_N3();
			estado = JUEGO_N3;
			musica();
		}

		if (key == '4')
		{
			espacio2.inicializa();
			estado = JUEGO2;
			musica();
		}
	}

	if (estado == MENU) //La máquina de estados se encuentra en el MENU del juego
	{
		if (key == 13) // ENTER, Si se pulsa la tecla ENTER se inicializa el menu para escoger nave
		{
			estado = ESCOGE;
			key = '0';
		}

		else if ((key == 'c') || (key == 'C')) //Si estando en el MENU, se pulsa la tecla c se inicializa el menú de los controles
		{
			estado = CONTROLES;
		}

		else if (key == 27) // ESCAPE,  Si se pulsa ESCAPE se abandona el juego
		{
			exit(0);
		}
	}

	if (estado == CORTINILLA1)
	{
		if (key == 13) // ENTER
		{
			estado = CORTINILLA2;
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == CORTINILLA2)
	{
		if (key == 13) // ENTER
		{
			estado = CORTINILLA3;
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == CORTINILLA3)
	{
		if (key == 13) // ENTER
		{
			espacio.inicializa_N1();
			estado = JUEGO_N1;
			musica();
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == ESCOGE)  //La máquina de estados se encuentra en el menú ESCOGE del juego
	{
		if ((key == 'a') || (key == 'A')) //Si se pulsa la tecla a se escoge la astronauta chica con su correspondiente nave y la imagen saluda
		{
			estado = ESCOGE_A;
			espacio.setA();
			espacio.setAC(); //Activa la cortinilla del astronauta a
		}
		else if ((key == 'b') || (key == 'B')) //Si se pulsa la tecla b se escoge el astronauta chico con su correspondiente nave y la imagen saluda
		{
			estado = ESCOGE_B;
			espacio.setB();
			espacio.setBC(); //Activa la cortinilla del astronauta b
		}
	}

	if ((estado == ESCOGE_A) || (estado == ESCOGE_B))
	{
		if ((key == 'a') || (key == 'A'))
		{
			estado = ESCOGE_A;
		}
		else if ((key == 'b') || (key == 'B'))
		{
			estado = ESCOGE_B;
		}
		else if (key == 13) // ENTER ,Tanto si se ha escogido el astronauta a o el b, cuando se presiona ENTER aparece la historia del juego
		{
			estado = CORTINILLA1;
			musica();
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if ((estado == JUEGO_N1) || (estado == JUEGO_N2) || (estado == JUEGO_N3)) //En los 3 primeros niveles se activa la función de mover la nave por teclado en la clase espacio
	{
		espacio.tecla(key);
	}

	if (estado == JUEGO2) //En el úlitmo nivel se activa la función de mover la nave por teclado en la clase espacio2
	{
		espacio2.tecla(key);
	}

	if (estado == CONTROLES) //La máquina de estados se encuentra en el menú de los controles
	{
		if (key == 8) // <-- , Si se presiona la tecla <-- se vuelve al MENU  anterior
		{
			estado = MENU;
		}

		else if (key == 27) // ESCAPE, Si se presiona ESCAPE se abandona el juego
		{
			exit(0);
		}
	}


	if (estado == LEVELUP1) //Se alcanza este estado cuando se ha superado el primer nivel 
	{
		if (key == 13) // Si se presiona ENTER aparece la historia del segundo nivel del juego con su música
		{
			espacio.inicializa_N2();
			estado = JUEGO_N2;
			musica();
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == LEVELUP2) // Se alcanza este estado cuando se ha superado el segundo nivel 
	{
		if (key == 13)  // Si se presiona ENTER aparece la historia del tercer nivel del juego con su música
		{
			espacio.inicializa_N3();
			estado = JUEGO_N3;
			musica();
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == LEVELUP3) // Se alcanza este estado cuando se ha superado el tercer nivel 
	{
		if (key == 13) //Si se presiona ENTER aparece la historia del último nivel del juego con su música
		{
			estado = CORTINILLA4;
			musica();
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == CORTINILLA4) // LEVELUP, En este estado aparece en pantalla la historia del último nivel
	{
		if (key == 13) // ENTER, Si se presiona ENTER se pasa al último nivel
		{
			espacio2.inicializa();
			estado = JUEGO2;
			musica();
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == VICTORIA) //Cuando se gana el juego aparece una pantalla de victoria
	{
		if (key == 13) //Si se presiona ENTER se pasa a la pantalla de FIN
		{
			estado = FIN;
			musica();
			key = '0'; // Para que no se pase la cortinilla
		}
	}

	if (estado == FIN) //Al final del todo, aparece una pantalla de FIN
	{
		if (key == 13) //Si se presiona ENTER se cierra la pantalla del juego
		{
			exit(0);
		}
	}

	if (estado == GAMEOVER)  //Cuando la máquina está en el estado GAMEOVER
	{
		if (key == 13) // ENTER
		{
			estado = MENU;
			musica();
			key = 0; // Para que no se salte el menú
		}

		else if (key == 27) // ESCAPE
		{
			exit(0);
		}
	}
}
