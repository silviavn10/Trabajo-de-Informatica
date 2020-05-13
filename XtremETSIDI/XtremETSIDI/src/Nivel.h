#include "Muñeco.h"
//#include "Creditos.h"
#include "Vida.h"
//#include "Interaccion.h"
#include "Suelo.h"
//#include "Caja.h"

class Nivel
{
public:
	Nivel();
	~Nivel();
	void Inicializa();
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Mueve();
	Vector2D GetPos();
	//void SetVel(float vx, float vy);
	Plataformas Plataforma;
	//Plataformas Plataforma2;
	//Plataformas Plataforma3;
	//Plataformas Plataforma4;
	//Vida Vida;
	//Creditos Creditos;
	Suelo Suelo;
	//Caja Caja;
	//Proyectiles Proyectiles;//Cuando la hagamos
	//Interaccion Interaccion;

	//float y_ojo;
	//float z_ojo;
};
