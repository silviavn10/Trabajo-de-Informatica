#include "Creditos.h"
#include "ETSIDI.h"
//#include "glut.h"

Creditos::Creditos() : SpriteCreditos("bin/imagenes/credito.png", 1)
{
}
Creditos::Creditos(float x, float y) : SpriteCreditos("bin/imagenes/credito.png", 1) //Constructor
{
	posicion.x = x;
	posicion.y = y;
	radio = 1.5f; //FALTAN VALORES BUENOS. Radio de la imagen del bonus
	velocidad.y = 2.0f; //FALTAN VALORES BUENOS. Velocidad vertical del bonus
	posicion_z = 0.5;
	limite1.y = posicion.y;
	aceleracion.y = -9.8f;
	SpriteCreditos.setCenter(1, 0.8);  //Centro del sprite para el muñeco vq 
	SpriteCreditos.setSize(1, 0.8);  //Tamaño del sprite para el muñeco vq
	setcreditos();
}
Creditos::~Creditos() //Destructor
{

}
void Creditos::Mueve(float t) //Funcion para que el crédito tenga movimiento
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (posicion.y < limite1.y) {
		posicion.y = limite1.y;
		velocidad.y = 2;
	}
}

void Creditos::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion_z);
	activo->draw();
	glPopMatrix();
}
void Creditos::Distancia(Creditos c1, Creditos c2) {

	distancia = c1.posicion.x - c2.posicion.x;
	if (distancia < 0) { distancia = distancia * (-1); }
}

/*float Creditos::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).Unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0)
		*direccion = dir.Unitario();
	return distancia;
}*/
