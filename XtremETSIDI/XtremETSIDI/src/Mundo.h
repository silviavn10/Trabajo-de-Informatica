#pragma once
#include"Nivel.h"
#include "NivelCOVID.h"
#include "Muñeco.h"
#include "Vida.h"
#include "ETSIDI.h"
#include "Interaccion.h"
#include "OpenGL.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class MundoXtremETSIDI
{
	int aux = 0;
	float x_ojo = 0.0;
public:

	MundoXtremETSIDI();
	~MundoXtremETSIDI();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void Musica();
	Nivel nivel1, nivel2;
	NivelCOVID nivel3;
	Vida vida1;
	float ojo;

protected:

	int guardanivel;

	enum Estado //Se crea una enumeración con los posibles estados que va a adoptar la máquina de estados
	{
		START, MENU, CONTROLES, ESCOGE_SEXO, ESCOGE_CARRERAF, ESCOGE_CARRERAV, CARTA, SUERTE,
		NIVEL1, NIVEL2, NIVEL3, JULIO, VICTORIA, GAMEOVER, FIN
	};
	Estado estado; //Se define una variable del tipo de la enumeración anterior
};
