#pragma once
#include"Nivel.h"
#include "NivelCOVID.h"
#include "Vida.h"
#include "ETSIDI.h"
#include "Interaccion.h"

// MUNDO ES EL COORDINADOR DEL JUEGO

// DESDE MUNDO SE LLAMA A LOS DISTINTOS NIVELES

class MundoXtremETSIDI
{
	enum Estado //Se crea una enumeraci�n con los posibles estados que va a adoptar la m�quina de estados
	{
		START, MENU, CONTROLES, ESCOGE_SEXO, ESCOGE_CARRERAF, ESCOGE_CARRERAV, CARTA, SUERTE,
		NIVEL1, NIVEL2, NIVEL3, JULIO, VICTORIA, GAMEOVER, FIN
	};

	Estado estado; //Se define una variable del tipo de la enumeraci�n anterior
	int aux;
	int guardanivel;
	float ojo;
	Nivel nivel1, nivel2;
	NivelCOVID nivel3;
	Vida vida1;

public:

	MundoXtremETSIDI();
	~MundoXtremETSIDI();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
	void Musica();
	
};
