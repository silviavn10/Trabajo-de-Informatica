/*#include "ListaProbetas.h"
#include "Interaccion.h"


ListaProbetas::ListaProbetas()
{
	numero = 0;
	for (int i = 0; i < MAX_PROBETAS; i++)
		lista[i] = 0;
}
ListaProbetas::~ListaProbetas() {

}
bool ListaProbetas::Agregar(Probeta* d)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == d)
			return false;

	if (numero < MAX_PROBETAS)
		lista[numero++] = d;
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
void ListaProbetas::Mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}
void ListaProbetas::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}
int ListaProbetas::Colision(Mu�eco m)
{
	for (int i = 0; i < numero; i++) //Recorre la lista de probetas
	{
		if (Interaccion::Colision(*(lista[i]), m)) //Detecta la colisi�n entre la plataforma y un elemento de la lista de probetas
			return i; //Si hay colisi�n devuelve el n�mero de elemento de la lista que ha colisionado
	}
	return -1; // No hay colisi�n 
	//HAY QUE HACER COMO SALTAR A JULIO 
}

void ListaProbetas::Eliminar(int index)  //Env�a destruir las probetas de la lista indicado
{
	if ((index < 0) || (index >= numero))  //Comprueba que el n�mero de la lista indicado tenga sentido
		return;

	delete lista[index];
	numero--;  //Hay un elemento menos en la lista
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];  //Elimina ese elemento de la lista de probetas

}


void ListaProbetas::Eliminar(Probeta * p) //Borra las probetas, pero tiene que recibir una probeta en concreto
{
	for (int i = 0; i < numero; i++)  //Recorre la lista hasta encontrar la probeta que le hemos indicado
		if (lista[i] == p)
		{
			Eliminar(i); //Env�a esa probeta a la funci�n eliminar (anterior)
			return;
		}
}


int ListaProbetas:: Colision(Plataformas f)  //Colisi�n entre la probeta y la plataforma
{
	for (int i = 0; i < numero; i++) //Recorre la lista de probetas
	{
		if (Interaccion::Colision(*(lista[i]), f)) //Detecta la colisi�n entre la plataforma y un elemento de la lista de probetas
			return i; //Si hay colisi�n devuelve el n�mero de elemento de la lista que ha colisionado
	}
	return -1; // No hay colisi�n
}
bool ListaProbetas::Agregar(Probeta* m) //Funci�n para agregar una plataforma
{
	for (int i = 0; i < numero; i++) // Evitamos plataformas ya existentes
		if (lista[i] == m)
			return false;
	if (numero < MAX_PROBETAS)  //Si no se ha llegado al m�ximo de plataformas permitidas
		lista[numero++] = m;  //se a�ade uno
	else
		return false;
	return true;
}
Probeta* ListaProbetas::operator [](int i) //Sobrecarga del operador [] para escoger una plataforma de toda la lista
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}
*/