#pragma once
#include"Nivel.h"
#include "NivelCOVID.h"
#include "Muñeco.h"
#include "Vida.h"
#include "ETSIDI.h"
#include "Interaccion.h"
#include "OpenGL.h"

class MundoXtremETSIDI
{
	int aux = 0;
	float x_ojo = 0.0;
public:

	//Métodos
	MundoXtremETSIDI();
	~MundoXtremETSIDI();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void Musica();
	Nivel nivel1, nivel2;
	NivelCOVID nivel3;
	//Plataformas plataforma, plataforma2;
	//
	Suelo suelo;
	Creditos creditos;
	Vida vida1;
	Proyectiles proyectil;
	float ojo;

protected:
	//Miembros

	enum Estado //Se crea una enumeración con los posibles estados que va a adoptar la máquina de estados
	{
		START, MENU, CONTROLES, ESCOGE_SEXO, ESCOGE_CARRERAF, ESCOGE_CARRERAV, CARTA, SUERTE,
		NIVEL1, NIVEL2, NIVEL3, VICTORIA, GAMEOVER, FIN/* JUEGO_N3, JUEGO2,
		GAMEOVER, SALIR,  //LEVELUP1, LEVELUP2, LEVELUP3,
		VICTORIA, FIN*/
	};
	Estado estado; //Se define una variable del tipo de la enumeración anterior
};
