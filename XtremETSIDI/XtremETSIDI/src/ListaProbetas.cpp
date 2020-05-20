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
/*void ListaProbetas::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}*/
void ListaProbetas::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}


void ListaProbetas::Eliminar(int index)  //Envía destruir las probetas de la lista indicado
{
	if ((index < 0) || (index >= numero))  //Comprueba que el número de la lista indicado tenga sentido
		return;

	delete lista[index];
	numero--;  //Hay un elemento menos en la lista
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];  //Elimina ese elemento de la lista de probetas

}


void ListaProbetas::Eliminar(Probeta* p) //Borra las probetas, pero tiene que recibir una probeta en concreto
{
	for (int i = 0; i < numero; i++)  //Recorre la lista hasta encontrar la probeta que le hemos indicado
		if (lista[i] == p)
		{
			Eliminar(i); //Envía esa probeta a la función eliminar (anterior)
			return;
		}
}


Probeta* ListaProbetas::operator [](int i) //Sobrecarga del operador [] para escoger una plataforma de toda la lista
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}
