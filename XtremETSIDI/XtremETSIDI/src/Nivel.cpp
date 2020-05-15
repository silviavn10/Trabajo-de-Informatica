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

void Nivel::Mueve(Muñeco& muñeco)
{
	
	for (int i = 0; i < ListaPlataformas.getNumero(); i++)
		Interaccion::Colision(*ListaPlataformas[i], muñeco);
	

	//Proyectil.Mueve() falta por hacer
	//AQUI FALTAN TODAS LAS INTERACCIONES
}

void Nivel::Inicializa( Suelo &s, Creditos &c, Proyectiles &pro, Vida &v)
{
	//habria que hacerlo con vectores
	//Creditos.SetPos(5.0f, 5.0f);
	//Proyectil.SetPos(-5.0f, 0.0f);
	s.SetPos();
	//Vida.SetPos(2, 6);
	Plataformas* e1 = new Plataformas(1.5f, 8, 2.5);
	e1->SetColor(148, 26, 28);
	ListaPlataformas.Agregar(e1); //esfera
	Plataformas* e2 = new Plataformas(1.5f,15 , 3);
	e2->SetColor(148, 26, 28);
	ListaPlataformas.Agregar(e2); //esfera2
	Plataformas* e3 = new Plataformas(1.2f, 17, 5);
	e3->SetColor(148, 26, 28);
	ListaPlataformas.Agregar(e3); //esfera3
	/*for (int i = 0; i < 6; i++)
	{
		Plataformas aux = new Plataformas(0.75 + i  0.25, i, 1 + i, i, i);
		esferas.Agregar(aux);
	}
	*/
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
}

void Nivel::TeclaEspecial(unsigned char key)
{


}
