/*#include "ListaCharcoCOVID.h"

ListaCharcoCOVID::ListaCharcoCOVID()
{
	numero = 0;
	for (int i = 0; i < MAX_C; i++) {
		lista[i] = 0;
	}
}
ListaCharcoCOVID::~ListaCharcoCOVID()
{

}
bool ListaCharcoCOVID::Agregar(CharcoCOVID* co)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == co)
			return false;

	if (numero < MAX_C)
		lista[numero++] = co;
	else
		return false;
	return true;
}

void ListaCharcoCOVID::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaCharcoCOVID::DestruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaCharcoCOVID::Eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaCharcoCOVID::Eliminar(CharcoCOVID* co)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == co)
		{
			Eliminar(i);
			return;
		}
}
CharcoCOVID* ListaCharcoCOVID::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}
*/