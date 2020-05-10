//#include "Vida.h"
#include "Menu.h"
#include "glut.h"


MenuXtremETSIDI XtremETSIDI;
//Muñeco muñeco;
//Nivel1 nivel1;

//Las siguientes son funciones que serán llamadas automáticamente por la glut cuando sucedan eventos, no es necesario llamarlas explícitamente
void onDraw(void); //esta funcion sera llamada para dibujar
void onTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void onKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y); //cuando se pulse una tecla especial	

int main(int argc, char* argv[])
{
	//Funciones para inicializar el gestor de ventanas GLUT y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1456, 720);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("XtremETSIDI");
	glutFullScreen(); // PANTALLA COMPLETA
	

	//Funciones para habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 1456 / 720.0f, 0.1, 150);

	
	//Registrar los callbacks
	glutDisplayFunc(onDraw);
	glutTimerFunc(25, onTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(onKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();
	return 0;
}

void onDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Función para borrar la pantalla

	glMatrixMode(GL_MODELVIEW);	 //Función para definir el punto de vista
	glLoadIdentity();

	XtremETSIDI.Dibuja();

	glutSwapBuffers();
}

void onKeyboardDown(unsigned char key, int x_t, int y_t)  //Funciones para el teclado (Disparar con el espacio)
{
	XtremETSIDI.Tecla(key);
	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)  //Funciones para teclas especiales (mover el muñeco)
{
	XtremETSIDI.TeclaEspecial(key);

}
void onTimer(int value) //Funciones de animación (movimiento de los objetos)
{
	XtremETSIDI.Mueve();
	glutTimerFunc(25, onTimer, 0);
	glutPostRedisplay();
}


