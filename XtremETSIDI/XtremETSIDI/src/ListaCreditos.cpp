#include "ListaCreditos.h"


ListaCreditos::ListaCreditos(void)
{
	numero = 0;
	lista = new Creditos * [MAX_CREDITOS];
	
}


ListaCreditos::~ListaCreditos(void)
{
	delete [] lista;
}


void ListaCreditos::Dibuja()
{

	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaCreditos::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

Creditos* ListaCreditos::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}
bool ListaCreditos::Agregar(Creditos* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
			return false;

	if (numero < MAX_CREDITOS)
		lista[numero++] = p;
	else
		return false;
	return true;
}
void ListaCreditos::Mueve(float t)
{

	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}
bool ListaCreditos::operator += (Creditos* c) {

	if (numero < MAX_CREDITOS) {
		lista[numero++] = c;
		return true;
	}
	return false;
}