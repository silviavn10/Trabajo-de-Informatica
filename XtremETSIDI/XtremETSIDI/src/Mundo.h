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

public:

	MundoXtremETSIDI();
	~MundoXtremETSIDI();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void Musica();

private:
	int aux = 0;
	int guardanivel= 0;
	Nivel nivel1, nivel2;
	NivelCOVID nivel3;
	Vida vida1;
	float ojo=0;

	enum Estado //Se crea una enumeración con los posibles estados que va a adoptar la máquina de estados
	{
		START, MENU, CONTROLES, ESCOGE_SEXO, ESCOGE_CARRERAF, ESCOGE_CARRERAV, CARTA, SUERTE,
		NIVEL1, NIVEL2, NIVEL3, JULIO, VICTORIA, GAMEOVER, FIN
	};
	Estado estado; //Se define una variable del tipo de la enumeración anterior
};
