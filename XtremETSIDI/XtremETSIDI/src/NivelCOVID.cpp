#include "NivelCOVID.h"
#include "ETSIDI.h"
#include "glut.h"

NivelCOVID::NivelCOVID()
{
	ListaCharcos.DestruirContenido();
	puntos = 0;
}
NivelCOVID:: ~NivelCOVID()
{

}
void NivelCOVID::Mueve()
{
	// MOVIMIENTOS Y COLISIONES DEL NIVEL 3

	muñeco.Mueve(0.025f);
	COVID.mueve(0.025f);
	ListaCreditos.Mueve(0.005f);

	for (int i = 0; i < ListaPlataformas.getNumero(); i++)
		Interaccion::Colision(muñeco, *ListaPlataformas[i]);


	for (int i = 0; i < ListaCreditos.getNumero(); i++) {
		aux = Interaccion::Colision(muñeco, *ListaCreditos[i]);
		if (aux == true) {
			puntos += 6;
			if (puntos >= 60)
				puntos = 60;
			

		}
	}

	for (int i = 0; i < MAX_C; i++) {
		aux1 = Interaccion::Colision(muñeco, *ListaCharcos[i]);
		if (aux1 == true) {
			setvida -= 1;
			COVID.setPosX(muñeco.getPosX() - 10);
		}
	}

	aux3 = Interaccion::Colision(muñeco, COVID);
	if (aux3 == true)
		setvida -= 1;
}

void NivelCOVID::Inicializa()
{
	// Se destruyen los creditos y plataformas creados en niveles anteriores
	ListaCreditos.DestruirContenido();
	ListaPlataformas.DestruirContenido();

	muñeco.SetPos(0, 2.5);

	//BUCLE PARA INICIALIZAR LAS PLATAFORMAS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 0; i < MAX_PLATAFORMAS; i++)
	{
		ListaPlataformas += new Plataformas(1.5f, 21 * (i + 1), 2.5);
		ListaPlataformas += new Plataformas(1.5f, 27 * (i + 1), 3.1); 
		ListaPlataformas += new Plataformas(1.5f, 28.5 * (i + 1), 3.4); 
		ListaPlataformas += new Plataformas(1.5f, 33 * (i + 1), 2.9);
		l1 = ListaPlataformas.lista[i]->GetPosX() - (ListaPlataformas.lista[i]->GetLado() / 2); //limite1.x
		l2 = ListaPlataformas.lista[i]->GetPosY() + (ListaPlataformas.lista[i]->GetLado() / 2); //limite1.y
		l3 = ListaPlataformas.lista[i]->GetPosX() + (ListaPlataformas.lista[i]->GetLado() / 2); //limite2.x
		l4 = ListaPlataformas.lista[i]->GetPosY() - (ListaPlataformas.lista[i]->GetLado() / 2); //limite2.y
		ListaPlataformas.lista[i]->SetPos(l1, l2, l3, l4);
		ListaPlataformas.Color(0,143,57);
	}

	//BUCLE PARA INICIALIZAR LOS CREDITOS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 0; i < MAX_CREDITOS; i +=20) {

		ListaCreditos += new Creditos(8 + i, 5.5); 
		ListaCreditos += new Creditos(12.3 + i, 2.5);
		ListaCreditos += new Creditos(18.2 + i, 3.5);

	}
	
	//BUCLE PARA INICIALIZAR LOS CHARCOS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 1; i < MAX_C; i++)
	{
		CharcoCOVID *c1 = new CharcoCOVID(48.3 * i);
		ListaCharcos.Agregar(c1);
		CharcoCOVID*c2 = new CharcoCOVID(38.5 * i);
		ListaCharcos.Agregar(c2);
	}
}

void NivelCOVID::Dibuja()
{
	//DIBUJA PARA LA CONVOCATORIA ORDINARIA

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
	
	//DIBUJA PARA LA CONVOCATORIA DE JULIO

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

	//DIBUJA COMUNES PARA AMBAS COMBOCATORIAS 

	ListaPlataformas.Dibuja();
	ListaCreditos.Dibuja();
	ListaCharcos.Dibuja();
	COVID.Dibuja();
	muñeco.Dibuja();
	ActDatos(puntos);  //Función para ir actualizando los datos que aparecen en la parte superior de la pantalla (contador de creditos)
}

void NivelCOVID::TeclaEspecial(unsigned char key)
{
	muñeco.TeclaEspecial(key);
}



void NivelCOVID::ActDatos(int puntos)  //Función para contar los créditos
{
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::setFont("bin/fuentes/azoft-sans.ttf", 20);
	char cont[100];
	sprintf(cont, "CREDITOS: %d / %d", puntos, 60);
	ETSIDI::printxy(cont, muñeco.getPosX() - 5.5, 8, 2);
}
