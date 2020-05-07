#pragma once
#include"Nivel1.h"
#include "Muñeco.h"
#include "ETSIDI.h"


class MenuXtremETSIDI
{
public:
	//Métodos
	MenuXtremETSIDI();
	~MenuXtremETSIDI();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	//void Mueve();
	void Dibuja();
	void Musica();
	
private:
	friend class Muñeco;
	Muñeco muñeco;
	Nivel1 nivel1;

protected:
	//Miembros

	enum Estado //Se crea una enumeración con los posibles estados que va a adoptar la máquina de estados
	{
		START, MENU, CONTROLES, ESCOGE_SEXO, ESCOGE_CARRERAF, ESCOGE_CARRERAV, CARTA, SUERTE,
		NIVEL1, VICTORIA, GAMEOVER, FIN/* JUEGO_N2, JUEGO_N3, JUEGO2,
		GAMEOVER, SALIR,  //LEVELUP1, LEVELUP2, LEVELUP3,
		VICTORIA, FIN*/
	};
	Estado estado; //Se define una variable del tipo de la enumeración anterior
};
