#include "Menu.h"
#include "ETSIDI.h"
#include <iostream>


 Menu::Menu()  //Construyo el Menu
{
	estado = START; 

	ETSIDI::playMusica("bso/intro.mp3", true); //Al empezar el juego se activa la múscia de inicio
}

