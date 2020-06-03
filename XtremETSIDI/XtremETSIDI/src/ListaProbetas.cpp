#include "ListaProbetas.h"

ListaProbetas::ListaProbetas()
{
	numero = 0;
	for (int i = 0; i < MAX_PROBETAS; i++)
		lista[i] = 0;
}
ListaProbetas::~ListaProbetas() {

}
bool ListaProbetas::Agregar(Probeta* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
			return false;

	if (numero < MAX_PROBETAS)
		lista[numero++] = p;
	else
		return false;
	return true;
}

void ListaProbetas::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaProbetas::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}


Probeta* ListaProbetas::operator [](int i) //Sobrecarga del operador [] para escoger una plataforma de toda la lista
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}
