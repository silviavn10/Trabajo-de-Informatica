#include "Nivel.h"
#include "ETSIDI.h"
#include "glut.h"

Nivel::Nivel()
{
}
Nivel:: ~Nivel()
{
}
void Nivel::Mueve()
{

	muñeco.Mueve(0.025f);
	ListaCreditos.Mueve(0.005f);
	for (int i = 0; i < ListaCreditos.getNumero(); i++) 
	{
		aux = Interaccion::Colision(muñeco, *ListaCreditos[i]);
		if (aux == true) {
			contador++;
		}
	}
	for (int i = 0; i < ListaPlataformas.getNumero(); i++)
	{
		Interaccion::Colision(muñeco, *ListaPlataformas[i]);
		//printf("Estoy entrando");
	}

	if (nivel == 1) {
		for (int i = 0; i < ListaProbetas.getNumero(); i++) {
			aux2 = Interaccion::Colision(muñeco, *ListaProbetas[i]);
			if (aux2 == true) {
				setvida -= 1;
			}
		}
		for (int i = 0; i < MAX_PROBETAS; i++)
		{
			if (ListaProbetas[i]->getPosX() - muñeco.posicion.x < 8.5)
			{
				ListaProbetas[i]->mueve(0.025f);
				for (int j = 0; j < MAX_PLATAFORMAS; j++)
				{
					aux3 = Interaccion::Colision(*ListaPlataformas[j], *ListaProbetas[i]);
					if (aux3 == true)
						ListaProbetas[i]->SetPosZ(-0.5);
				}
			}
		}
	}
	if (nivel == 1) {
		for (int i = 0; i < MAX_C; i++) {
			aux1 = Interaccion::Colision(muñeco, *ListaCharcos[i]);
			if (aux1 == true) {
				setvida -= 1;
			}
		}
	}
	if (nivel == 2) {
		for (int i = 0; i < ListaReglas.getNumero(); i++) {
			aux2 = Interaccion::Colision(muñeco, *ListaReglas[i]);
			if (aux2 == true) {
				setvida -= 1;
			}
		}
		for (int i = 0; i < MAX_REGLAS; i++)
		{
			if (ListaReglas[i]->getPosX() - muñeco.posicion.x < 8.5)
			{
				ListaReglas[i]->mueve(0.025f);
				for (int j = 0; j < MAX_REGLAS; j++)
				{
					aux3 = Interaccion::Colision(*ListaPlataformas[j], *ListaReglas[i]);
					if (aux3 == true)
						ListaReglas[i]->SetPosZ(-0.5);
				}
			}
		}
	}
}

void Nivel::Inicializa() //Para nivel 1
{
	muñeco.SetPos(0, 2.5);

	for (int i = 0; i < MAX_PLATAFORMAS; i++)
	{
		ListaPlataformas += new Plataformas(1.5f, 21 * (i + 1), 2.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES
		ListaPlataformas += new Plataformas(1.5f, 27 * (i + 1), 3.1); // ---------------------------------------------------------SOBRECARGA DE OPERADORES
		ListaPlataformas += new Plataformas(1.5f, 28.5 * (i + 1), 3.4); // ---------------------------------------------------------SOBRECARGA DE OPERADORES
		ListaPlataformas += new Plataformas(1.5f, 33 * (i + 1), 2.9);
		l1 = ListaPlataformas.lista[i]->posicion.x - (ListaPlataformas.lista[i]->lado / 2); //limite1.x
		l2 = ListaPlataformas.lista[i]->posicion.y + (ListaPlataformas.lista[i]->lado / 2); //limite1.y
		l3 = ListaPlataformas.lista[i]->posicion.x + (ListaPlataformas.lista[i]->lado / 2); //limite2.x
		l4 = ListaPlataformas.lista[i]->posicion.y - (ListaPlataformas.lista[i]->lado / 2); //limite2.y
		ListaPlataformas.lista[i]->SetPos(l1, l2, l3, l4);
	}
	for (int i = 0; i < 200; i += 20) {

		ListaCreditos += new Creditos(8 + i, 5.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 0; i < 200; i += 25) {

		ListaCreditos += new Creditos(1.2 + i, 2.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 0; i < 200; i += 35) {

		ListaCreditos += new Creditos(13 + i, 3.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 1; i < MAX_PROBETAS; i++)
	{
		Probeta* p1 = new Probeta(15 * i, 9.5); //Para cambiar la altura de probetas
		ListaProbetas.Agregar(p1);
		Probeta* p2 = new Probeta(20 * i, 9.5);
		ListaProbetas.Agregar(p2);
	}
	for (int i = 1; i < MAX_C; i++)
	{
		Charcos* c1 = new Charcos(15 * i);
		ListaCharcos.Agregar(c1);
		Charcos* c2 = new Charcos(37 * i);
		ListaCharcos.Agregar(c2);
	}

	nivel = 1;
}

void Nivel::Inicializa2()
{
	/*ListaCharcos.DestruirContenido();
	ListaCreditos.DestruirContenido();
	ListaPlataformas.DestruirContenido();
	ListaProbetas.DestruirContenido();*/

	muñeco.SetPos(0, 2.5);

	for (int i = 0; i < MAX_PLATAFORMAS; i++)
	{
		ListaPlataformas += new Plataformas(1.5f, 21 * (i + 1), 2.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES
		ListaPlataformas += new Plataformas(1.5f, 27 * (i + 1), 3.1); // ---------------------------------------------------------SOBRECARGA DE OPERADORES
		ListaPlataformas += new Plataformas(1.5f, 28.5 * (i + 1), 3.4); // ---------------------------------------------------------SOBRECARGA DE OPERADORES
		ListaPlataformas += new Plataformas(1.5f, 33 * (i + 1), 2.9);
		l1 = ListaPlataformas.lista[i]->posicion.x - (ListaPlataformas.lista[i]->lado / 2); //limite1.x
		l2 = ListaPlataformas.lista[i]->posicion.y + (ListaPlataformas.lista[i]->lado / 2); //limite1.y
		l3 = ListaPlataformas.lista[i]->posicion.x + (ListaPlataformas.lista[i]->lado / 2); //limite2.x
		l4 = ListaPlataformas.lista[i]->posicion.y - (ListaPlataformas.lista[i]->lado / 2); //limite2.y
		ListaPlataformas.lista[i]->SetPos(l1, l2, l3, l4);
	}
	for (int i = 0; i < 200; i += 20) {

		ListaCreditos += new Creditos(8 + i, 5.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 0; i < 200; i += 25) {

		ListaCreditos += new Creditos(4 + i, 2.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 0; i < 200; i += 35) {

		ListaCreditos += new Creditos(15 + i, 3.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 1; i < MAX_REGLAS; i++)
	{
		Reglas* p1 = new Reglas(15 * i, 9.5);
		ListaReglas.Agregar(p1);
		Reglas* p2 = new Reglas(20 * i, 9.5);
		ListaReglas.Agregar(p2);
	}
	/*
	for (int i = 1; i < MAX_C; i++)
	{
		Charcos* c1 = new Charcos(15 * i);
		ListaCharcos.Agregar(c1);
		Charcos* c2 = new Charcos(37 * i);
		ListaCharcos.Agregar(c2);
	}*/

	nivel = 2;

	/*ListaCharcos.DestruirContenido();
	ListaCreditos.DestruirContenido();
	ListaPlataformas.DestruirContenido();
	ListaProbetas.DestruirContenido();*/
}


void Nivel::Dibuja()
{
	if (setvida == 2)
	{
		/*ETSIDI::stopMusica();
		ETSIDI::play("bin/bso/nivel1.mp3");*/
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/nivel1.png").id); //foto pasillo

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(180, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(180, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

	if (setvida == 1)
	{
		//printf("Ketchup");
		//ETSIDI::stopMusica();
		//ETSIDI::playMusica("bin/bso/julio.mp3",true); 
		//TAMPOCO VA
		for(int i=0; i<1;i++)
		{
			printf("Entra2Taco");
			ETSIDI::stopMusica();
			ETSIDI::playMusica("bin/bso/julio.mp3", true);
		}
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondoJULIO.png").id); //foto pasillo JULIO

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-9.7, -0.25, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(180, -0.25, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(180, 9.25, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-9.7, 9.25, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	muñeco.Dibuja();
	if (nivel == 1)
	{
		ListaProbetas.Dibuja();
		ListaCharcos.Dibuja();
		ListaPlataformas.Dibuja();
		ListaCreditos.Dibuja();
	}
	if (nivel == 2) {

		ListaPlataformas.Dibuja();
		ListaCreditos.Dibuja();
		ListaReglas.Dibuja();
	}

}

void Nivel::TeclaEspecial(unsigned char key)
{
	muñeco.TeclaEspecial(key);
}
