#include "NivelCOVID.h"
#include "ETSIDI.h"
#include "glut.h"

NivelCOVID::NivelCOVID()
{
	//DE MOMENTO NADA
}
NivelCOVID:: ~NivelCOVID()
{

}
void NivelCOVID::Mueve()
{

	muñeco.Mueve(0.025f);

	//INTERACCIONES
	for (int i = 0; i < ListaPlataformas.getNumero(); i++)
	{
		Interaccion::Colision(muñeco, *ListaPlataformas[i]);
		//printf("Estoy entrando");
	}
	for (int i = 0; i < ListaCreditos.getNumero(); i++) {
		aux = Interaccion::Colision(muñeco, *ListaCreditos[i]);
		if (aux == true) {
			contador++;
		}
	}
	for (int i = 0; i < ListaProbetas.getNumero(); i++) {
		aux2 = Interaccion::Colision(muñeco, *ListaProbetas[i]);
		if (aux2 == true) {
			setvida -= 1;
		}
	}

	/*for (int i = 0; i < MAX_PROBETAS; i++)
	{
		if (ListaProbetas[i]->getPosX() - muñeco.posicion.x < 8)
		{
			ListaProbetas[i]->mueve(0.025f);
			for (int j = 0; j < MAX_PLATAFORMAS; j++)
			{
				aux3 = Interaccion::Colision(*ListaPlataformas[j], *ListaProbetas[i]);
				if (aux3 == true)
					ListaProbetas[i]->SetPosZ(-0.5);
			}
		}
	}*/

	ListaCreditos.Mueve(0.005f);

	for (int i = 0; i < MAX_C; i++) {
		aux1 = Interaccion::Colision(muñeco, *ListaCharcoCOVID[i]);
		if (aux1 == true) {
			setvida -= 1;
		}
	}
}

void NivelCOVID::Inicializa()
{
	/*ListaCharcos.DestruirContenido();
	ListaCreditos.DestruirContenido();
	ListaPlataformas.DestruirContenido();
	ListaProbetas.DestruirContenido();*/
	muñeco.SetPos(0, 2.5);
	/*for (int i = 0; i < MAX_PLATAFORMAS; i++)
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
	}*/
	for (int i = 0; i < 200; i += 20) {

		ListaCreditos += new Creditos(8 + i, 5.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 0; i < 200; i += 25) {

		ListaCreditos += new Creditos(4 + i, 2.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	for (int i = 0; i < 200; i += 35) {

		ListaCreditos += new Creditos(15 + i, 3.5); // ---------------------------------------------------------SOBRECARGA DE OPERADORES

	}
	/*for (int i = 1; i < MAX_PROBETAS; i++)
	{
		Probeta* p1 = new Probeta(15 * i, 7);
		ListaProbetas.Agregar(p1);
		Probeta* p2 = new Probeta(20 * i, 7);
		ListaProbetas.Agregar(p2);
	}*/
	for (int i = 1; i < MAX_C; i++)
	{
		CharcoCOVID *c1 = new CharcoCOVID(48 * i);
		ListaCharcoCOVID.Agregar(c1);
		CharcoCOVID *c2 = new CharcoCOVID(37 * i);
		ListaCharcoCOVID.Agregar(c2);
	}

	//ListaCharcos.DestruirContenido();
	//ListaCreditos.DestruirContenido();
	//ListaPlataformas.DestruirContenido();
	//ListaProbetas.DestruirContenido();
}

void NivelCOVID::Dibuja()
{
	if (setvida == 2)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondoCOVID.png").id); //foto pasillo

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

	//PONER BIEN CON NIVEL=1
	//ListaPlataformas.Dibuja();
	ListaCreditos.Dibuja();
	//ListaProbetas.Dibuja();
	ListaCharcoCOVID.Dibuja();
	muñeco.Dibuja();
}

void NivelCOVID::TeclaEspecial(unsigned char key)
{
	muñeco.TeclaEspecial(key);
}

//HACER UNA FUNCION EN MUÑECO QUE ME DEVUELVA MUEVE
