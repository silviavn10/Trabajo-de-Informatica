#include<iostream>
#include "Vector2D.h"


Vector2D::Vector2D(float xv, float yv)
{
    x = xv;
    y = yv;
}
Vector2D::~Vector2D() {

}

float Vector2D::modulo() {// (2) modulo del vector0
    return (float)sqrt(x * x + y * y);
}
float Vector2D::argumento() {// (3) argumento del vector
    return (float)atan2(y, x);
}
Vector2D Vector2D::Unitario() {// (4) devuelve un vector unitario
    Vector2D retorno(x, y);
    float mod = modulo();
    if (mod > 0.00001)
    {
        retorno.x /= mod;
        retorno.y /= mod;
    }
    return retorno;
}
Vector2D Vector2D::operator - (Vector2D& v) {// (5) resta de vectores
    
	Vector2D retu;
	retu.x = x - v.x;
	retu.y = y - v.y;
	return retu;
}
Vector2D Vector2D::operator + (Vector2D& v) {// (6) suma de vectores
	Vector2D retu;
	retu.x = x + v.x;
	retu.y = y + v.y;
	return retu;
}
float Vector2D::operator *(Vector2D& v) {// (7) producto escalar
	float esca;
	esca = (x * v.x) + (y * v.y);
	return esca;
}
Vector2D Vector2D::operator *(float escalar) {// (8) producto por un escalar
	Vector2D retu;
	retu.x = escalar * x;
	retu.y = escalar * y;
	return retu;

}




