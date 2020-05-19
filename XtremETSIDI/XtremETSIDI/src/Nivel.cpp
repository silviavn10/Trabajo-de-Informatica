#include "Nivel.h"
#include "ETSIDI.h"
#include "glut.h"

Nivel::Nivel()
{
	//DE MOMENTO NADA
}
Nivel:: ~Nivel()
{

}

void Nivel::Mueve()
{
	
	muñeco.Mueve(0.025f);
	for (int i = 0; i < ListaPlataformas.getNumero(); i++)
	{
		Interaccion::Colision(muñeco, *ListaPlataformas[i]);
		//printf("Estoy entrando");
	}
	for (int i = 0; i < ListaCreditos.getNumero(); i++)
		Interaccion::Colision(muñeco, *ListaCreditos[i]);
	ListaCreditos.Mueve(0.005f);
	//Proyectil.Mueve() falta por hacer
	//AQUI FALTAN TODAS LAS INTERACCIONES
}

void Nivel::Inicializa(Suelo& s, Creditos& c, Proyectiles& pro, Vida& v)
{
	//habria que hacerlo con vectores
	//Proyectil.SetPos(-5.0f, 0.0f);
	s.SetPos();
	//Vida.SetPos(2, 6);
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
		ListaPlataformas.lista[i]->SetPos(l1,l2,l3,l4);
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
}

void Nivel::Dibuja()
{
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
	
	ListaPlataformas.Dibuja();
	ListaCreditos.Dibuja();
	muñeco.Dibuja();
}

void Nivel::TeclaEspecial(unsigned char key)
{
	muñeco.TeclaEspecial(key);
}
