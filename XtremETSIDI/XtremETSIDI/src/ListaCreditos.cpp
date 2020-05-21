#include "ListaCreditos.h"
#include "Interaccion.h"

ListaCreditos::ListaCreditos(void)
{
	numero = 0;
	//for (int i = 0; i < MAX_CREDITOS; i++)lista[i] = 0;
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

void ListaCreditos::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;

	delete lista[index];

	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];

}

void ListaCreditos::Eliminar(Creditos* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
		{
			Eliminar(i);
			return;
		}
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