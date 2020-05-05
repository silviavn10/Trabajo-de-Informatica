#include "ListaProbetas.h"
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
void ListaProbetas::Colision(Mu�eco m)
{
	for (int i = 0; i < numero; i++)
		if (Interaccion::Colision(*(lista[i]), p))
			lista[i]->SetVel(0, 0);
}

void ListaProbetas::Eliminar(int index)  //Env�a destruir el meteorito de la lista indicado
{
	if ((index < 0) || (index >= numero))  //Comprueba que el n�mero de la lista indicado tenga sentido
		return;

	delete lista[index];
	numero--;  //Hay un elemento menos en la lista
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];  //Elimina ese elemento de la lista de meteoritos

}


void ListaProbetas::Eliminar(Probeta * p) //Borra los meteoritos, pero tiene que recibir un meteorito en concreto
{
	for (int i = 0; i < numero; i++)  //Recorre la lista hasta encontrar el meteorito que le hemos indicado
		if (lista[i] == p)
		{
			Eliminar(i); //Env�a ese meteorito a la funci�n eliminar (anterior)
			return;
		}
}


int ListaProbetas:: Colision(Plataformas f)  //Colisi�n entre un meteorito y la nave
{
	for (int i = 0; i < numero; i++) //Recorre la lista de meteoritos
	{
		if (Interaccion::colision(*(lista[i]), f)) //Detecta la colisi�n entre la nave y un elemento de la lista de meteoritos
			return i; //Si hay colisi�n devuelve el n�mero de elemento de la lista que ha colisionado
	}
	return -1; // No hay colisi�n
}
bool ListaProbetas::Agregar(Probeta* m) //Funci�n para agregar un meteorito
{
	for (int i = 0; i < numero; i++) // Evitamos meteoritos ya existentes
		if (lista[i] == m)
			return false;
	if (numero < MAX_PROBETAS)  //Si no se ha llegado al m�ximo de meteoritos permitidos
		lista[numero++] = m;  //se a�ade uno
	else
		return false;
	return true;
}
Probeta* ListaProbetas::operator [](int i) //Sobrecarga del operador [] para escoger un meteorito de toda la lista
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}