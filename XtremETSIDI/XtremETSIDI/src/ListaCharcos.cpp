#include "ListaCharcos.h"

ListaCharcos::ListaCharcos()
{
	numero = 0;
	for (int i = 0; i < MAX_C; i++) {
		lista[i] = 0;
	}
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

Charcos* ListaCharcos::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}


