#include "ListaCharcos.h"

ListaCharcos::ListaCharcos()
{
	numero = 0;
	for (int i = 0; i < MAX_C; i++) {
		lista[i] = 0;
	}
}

ListaCharcos::~ListaCharcos()
{

}

bool ListaCharcos::Agregar(Charcos *c)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == c)
			return false;

	if (numero < MAX_C)
		lista[numero++] = c;
	else
		return false;
	return true;
}

void ListaCharcos::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaCharcos::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaCharcos::Eliminar(int index) 
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaCharcos::Eliminar(Charcos *c)
{
	for (int i=0;i<numero;i++)
		if (lista[i] == c)
		{
			Eliminar(i);
			return;
		}
}