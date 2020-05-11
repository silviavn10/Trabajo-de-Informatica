#pragma once
#include"Nivel.h"
#include "Mu�eco.h"
#include "ETSIDI.h"


class MundoXtremETSIDI
{
	int aux=0;
	float x_ojo=0.0;
public:

	//M�todos
	MundoXtremETSIDI();
	~MundoXtremETSIDI();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void Musica();
	Mu�eco mu�eco;
	Nivel nivel1;
	
protected:
	//Miembros

	enum Estado //Se crea una enumeraci�n con los posibles estados que va a adoptar la m�quina de estados
	{
		START, MENU, CONTROLES, ESCOGE_SEXO, ESCOGE_CARRERAF, ESCOGE_CARRERAV, CARTA, SUERTE,
		NIVEL1, VICTORIA, GAMEOVER, FIN/* JUEGO_N2, JUEGO_N3, JUEGO2,
		GAMEOVER, SALIR,  //LEVELUP1, LEVELUP2, LEVELUP3,
		VICTORIA, FIN*/
	};
	Estado estado; //Se define una variable del tipo de la enumeraci�n anterior
};
