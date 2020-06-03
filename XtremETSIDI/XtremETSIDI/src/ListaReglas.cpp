#include "ListaReglas.h"

ListaReglas::ListaReglas()
{
	numero = 0;
	for (int i = 0; i < MAX_REGLAS; i++)
		lista[i] = 0;
}
ListaReglas::~ListaReglas() {

}
bool ListaReglas::Agregar(Reglas* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
			return false;

	if (numero < MAX_REGLAS)
		lista[numero++] = p;
	else
		return false;
	return true;
}
void ListaReglas::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaReglas::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

Reglas* ListaReglas::operator [](int i) //Sobrecarga del operador [] para escoger una plataforma de toda la lista
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}