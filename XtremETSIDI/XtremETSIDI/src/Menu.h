#pragma once


class MenuXtremETSIDI
{
public:
	//Métodos
	MenuXtremETSIDI();
	~MenuXtremETSIDI();
	/*void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();*/
	void Dibuja();
	//void Musica();

protected:
	//Miembros
	//Espacio espacio;

	enum Estado //Se crea una enumeración con los posibles estados que va a adoptar la máquina de estados
	{
		START, MENU, ESCOGE_CARRERA, ESCOGE_A, ESCOGE_E, ESCOGE_M, ESCOGE_D, ESCOGE_Q, ESCOGE_SEXO, ESCOGE_F, ESCOGE_V,
		CONTROLES, //JUEGO_N1, JUEGO_N2, JUEGO_N3, JUEGO2,
		GAMEOVER, CARATULA, M_PRINCIPAL, COMENZAR, SALIR, CARTA, SUERTE, //LEVELUP1, LEVELUP2, LEVELUP3,
		VICTORIA, FIN
	};
	Estado estado; //Se define una variable del tipo de la enumeración anterior
};
