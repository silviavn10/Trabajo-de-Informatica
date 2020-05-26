#include "ListaPlataformas.h"
#include "Interaccion.h"

ListaPlataformas::ListaPlataformas(void)
{
	numero = 0;
	lista = new Plataformas * [MAX_PLATAFORMAS];// reserva memoria dinámicamente para vector lista con una dimension maxima de MAX_PLATAFORMAS
}


ListaPlataformas::~ListaPlataformas(void)
{

}


void ListaPlataformas::Dibuja()
{

	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaPlataformas::Color(unsigned char r, unsigned char v, unsigned char a) {

	for (int i = 0; i < numero; i++)
		lista[i]->SetColor(r, v, a);

}
void ListaPlataformas::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

void ListaPlataformas::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;

	delete lista[index];

	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];

}

void ListaPlataformas::Eliminar(Plataformas* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
		{
			Eliminar(i);
			return;
		}

}

/*Plataformas* ListaPlataformas::Colision(Muñeco m)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::Colision(*(lista[i]), m))
			return lista[i];
	}
	return 0; //no hay colisión

}*/
Plataformas * ListaPlataformas::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}
bool ListaPlataformas::Agregar(Plataformas* p)
{
	//EJERCICIO 6.4
	for (int i = 0; i < numero; i++)
		if (lista[i] == p) {
			return false;
		}

	if (numero < MAX_PLATAFORMAS)
		lista[numero++] = p;
	else
		return false;
	return true;
}

bool ListaPlataformas::operator += (Plataformas* p) {

	if (numero < MAX_PLATAFORMAS) {
		lista[numero++] = p; //guarda la direccion 
		return true;
	}
	return false;
}
void ListaPlataformas::Colision(Muñeco& h, Plataformas* Lista)
{
	for (int i = 0; i < numero; i++)
		Interaccion::Colision(h, *Lista);
}

void ListaPlataformas::Mueve(float f)
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->Mueve(f);

	}

}