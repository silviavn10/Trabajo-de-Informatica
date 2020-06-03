#include "Nivel.h"
#include "ETSIDI.h"
#include "glut.h"

Nivel::Nivel()
{
	puntos = 0;
	setvida = 2;
}
Nivel:: ~Nivel()
{
}
void Nivel::Mueve()
{
	
	// MOVIMIENTOS Y COLISIONES COMUNES AL NIVEL 1 Y 2


	ListaPlataformas.Mueve(0.025);
	muñeco.Mueve(0.025f);
	ListaCreditos.Mueve(0.005f);
	ListaPlataformas.Colision(muñeco);

	for (int i = 0; i < ListaCreditos.getNumero(); i++) 
	{
		aux = Interaccion::Colision(muñeco, *ListaCreditos[i]);
		if (aux == true) {
			puntos += 3;
			if (puntos >= 60)
				puntos = 60;
			
		}
	}

	//MOVIMIENTOS Y COLISIONES EXCLUSIVOS DEL NIVEL 1

	if (nivel == 1) {

		for (int i = 0; i < ListaProbetas.getNumero(); i++) {
			aux2 = Interaccion::Colision(muñeco, *ListaProbetas[i]);
			if (aux2 == true) 
				setvida -= 1;
		}
		for (int i = 0; i < ListaProbetas.getNumero(); i++)
		{
			if (ListaProbetas[i]->getPosX() - muñeco.getPosX() < 7.5f)
				ListaProbetas[i]->mueve(0.025f);

		}

		for (int i = 0; i < MAX_C; i++) {
			aux1 = Interaccion::Colision(muñeco, *ListaCharcos[i]);
			if (aux1 == true) 
				setvida -= 1;

		}
	}


	//MOVIMIENTOS Y COLISIONES EXCLUSIVOS DEL NIVEL 2


	if (nivel == 2) {
		for (int i = 0; i < ListaReglas.getNumero(); i++) {
			aux2 = Interaccion::Colision(muñeco, *ListaReglas[i]);
			if (aux2 == true) 
				setvida -= 1;
		}
		for (int i = 0; i < ListaReglas.getNumero(); i++)
		{
			if (ListaReglas[i]->getPosX() - muñeco.getPosX() < 7.5)
				ListaReglas[i]->mueve(0.025f);
		}
		
		
	}
}



void Nivel::Inicializa() // INICIALIZA DEL NIVEL 1
{

	muñeco.SetPos(0, 2.5);

	//BUCLE PARA INICIALIZAR LAS PLATAFORMAS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 0; i < MAX_PLATAFORMAS; i++)
	{
		ListaPlataformas += new Plataformas(1.5f, 20.5 + 15*i, 2.5);                           // SOBRECARGA DE OPERADORES
		ListaPlataformas += new Plataformas(1.5f, 28 + 13.5*i, 3.1); 
		ListaPlataformas += new Plataformas(1.5f, 57.5+ 27* i, 4); 

		l1 = ListaPlataformas.lista[i]->GetPosX() - (ListaPlataformas.lista[i]->GetLado() / 2); //limite1.x
		l2 = ListaPlataformas.lista[i]->GetPosY() + (ListaPlataformas.lista[i]->GetLado() / 2); //limite1.y
		l3 = ListaPlataformas.lista[i]->GetPosX() + (ListaPlataformas.lista[i]->GetLado() / 2); //limite2.x
		l4 = ListaPlataformas.lista[i]->GetPosY() - (ListaPlataformas.lista[i]->GetLado() / 2); //limite2.y
		ListaPlataformas.lista[i]->SetPos(l1, l2, l3, l4);
		ListaPlataformas.Color(148, 26, 28);
	}

	//BUCLE PARA INICIALIZAR LOS CREDITOS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL
	
	for (int i = 0; i < MAX_CREDITOS; i += 20) {
		ListaCreditos += new Creditos(8 + i, 5.5); 
		ListaCreditos += new Creditos(32.5+i, 2.5);
		ListaCreditos += new Creditos(14 + i, 3.5);
		ListaCreditos += new Creditos(57.5 + 2.7 * i, 6);

	}
	
	//BUCLE PARA INICIALIZAR LAS PLATAFORMAS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 1; i < MAX_PROBETAS; i++)
	{
		Probeta* p1 = new Probeta(15 * i, 9.5);
		ListaProbetas.Agregar(p1);
		Probeta* p2 = new Probeta(20 * i, 9.5);
		ListaProbetas.Agregar(p2);
	}

	//BUCLE PARA INICIALIZAR LOS CHARCOS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 1; i < MAX_C; i++)
	{
		Charcos* c1 = new Charcos(15 * i);
		ListaCharcos.Agregar(c1);
		Charcos* c2 = new Charcos(37.5* i);
		ListaCharcos.Agregar(c2);
	}
	nivel = 1;
}
void Nivel::Inicializa2() // INICIALIZA DEL NIVEL 2
{

	//Se destruye lo creado en el nivel 1

	ListaCharcos.DestruirContenido(); 
	ListaCreditos.DestruirContenido();
	ListaPlataformas.DestruirContenido();
	ListaProbetas.DestruirContenido();

	muñeco.SetPos(0, 2.5);
	muñeco.SetVel(0.0f, 0.0f);
	
	//BUCLE PARA INICIALIZAR LAS PLATAFORMAS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 0; i < MAX_PLATAFORMASMOVILES; i++)
	{
		ListaPlataformas += new PlataformaMovil(1.5f, 20 * (i + 1), 3.4);
		ListaPlataformas += new PlataformaMovil(1.5f, 50 * (i + 1), 2.5, 7);
		ListaPlataformas += new Plataformas(1.5f, 35 * (i + 1), 2.5);
		ListaPlataformas += new Plataformas(1.5f, 20 + 36 * (i + 2), 3.1);

		l1 = ListaPlataformas.lista[i]->GetPosX() - (ListaPlataformas.lista[i]->GetLado() / 2); //limite1.x
		l2 = ListaPlataformas.lista[i]->GetPosY() + (ListaPlataformas.lista[i]->GetLado() / 2); //limite1.y
		l3 = ListaPlataformas.lista[i]->GetPosX() + (ListaPlataformas.lista[i]->GetLado() / 2); //limite2.x
		l4 = ListaPlataformas.lista[i]->GetPosY() - (ListaPlataformas.lista[i]->GetLado() / 2); //limite2.y

		ListaPlataformas.lista[i]->SetPos(l1, l2, l3, l4);
		ListaPlataformas.Color(148, 26, 28);

	}

	//BUCLE PARA INICIALIZAR LOS CREDITOS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 0; i < MAX_CREDITOS; i += 20) {

		ListaCreditos += new Creditos(8 + i, 5.5); 
		ListaCreditos += new Creditos(4 + i, 2.5);
		ListaCreditos += new Creditos(15 + i, 3.5);
	}
	
	//BUCLE PARA INICIALIZAR LAS REGLAS EN DISTINTAS POSICIONES A LO LARGO DEL NIVEL

	for (int i = 1; i < MAX_REGLAS; i++)
	{
		Reglas* p1 = new Reglas(17 * i, 9.5); 
		ListaReglas.Agregar(p1);
		Reglas* p2 = new Reglas(23 * i, 9.5); 
		ListaReglas.Agregar(p2);
		Reglas* p3 = new Reglas(28 * i, 9.5);
		ListaReglas.Agregar(p3);
	}
	nivel = 2;
}


void Nivel::Dibuja()
{
	//DIBUJA PARA LA CONVOCATORIA ORDINARIA

	if (setvida == 2)
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

	muñeco.Dibuja();
	ActDatos(puntos); //Función para ir actualizando los datos que aparecen en la parte superior de la pantalla (contador de creditos)

	//DIBUJA PARA EL NIVEL 1

	if (nivel == 1)
	{
		ListaProbetas.Dibuja();
		ListaCharcos.Dibuja();
		ListaPlataformas.Dibuja();
		ListaCreditos.Dibuja();
	}

	//DIBUJA PARA EL NIVEL 2

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

void Nivel::ActDatos(int puntos)  //Función para contar los créditos
{
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::setFont("bin/fuentes/azoft-sans.ttf", 20); 
	char cont[100];
	sprintf(cont, "CREDITOS: %d / %d", puntos, 60);
	ETSIDI::printxy(cont, muñeco.getPosX()-5.5, 8,2);
}


