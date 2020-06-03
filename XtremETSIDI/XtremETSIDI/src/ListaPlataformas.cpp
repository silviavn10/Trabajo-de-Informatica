#include "ListaPlataformas.h"


ListaPlataformas::ListaPlataformas(void)
{
	numero = 0;
	lista = new Plataformas * [MAX_PLATAFORMAS];   // reserva memoria dinámicamente para vector lista con una dimension maxima de MAX_PLATAFORMAS
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

void ListaPlataformas::Colision(Muñeco& h)
{
	for (int i = 0; i < numero; i++)
		Interaccion::Colision(h, *lista[i]);
}

void ListaPlataformas::Mueve(float f)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(f);

}