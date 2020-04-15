#pragma once


class Menu
{
public:
	//Métodos
	Menu();
	~Menu();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void musica();

protected:
	//Miembros
	

	enum Estado //Se crea una enumeración con los posibles estados que va a adoptar la máquina de estados
	{
		START, MENU, ESCOGE, ESCOGE_A, ESCOGE_B, CONTROLES, JUEGO_N1, JUEGO_N2, JUEGO_N3, JUEGO2,
		GAMEOVER, CORTINILLA1, CORTINILLA2, CORTINILLA3, CORTINILLA4, LEVELUP1, LEVELUP2, LEVELUP3,
		VICTORIA, FIN
	};
	Estado estado; //Se define una variable del tipo de la enumeración anterior
};