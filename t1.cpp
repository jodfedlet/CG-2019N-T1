#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

void renderCoordenadas(){ // Funçao para criar coordenadas x e y
	glBegin(GL_LINES);
	 glColor3f(0,1,0);
	 glVertex2f(-6,0);
	 glVertex2f(6,0);
	 glColor3f(0,0,1);
	 glVertex2f(0,-6);
	 glVertex2f(0,6);
	 
		
	glEnd();

}


void Display (){
	glClear(GL_COLOR_BUFFER_BIT);

	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();*/
	gluOrtho2D(-6,6,-6,6);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	renderCoordenadas();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef (0.0, 1.0, 0.0);
	glutWireCube (1.0);
	glPopMatrix();

	

	glFlush();
}
void KeyBoard(unsigned char tecla, GLint x, GLint y){
	switch(tecla){
		case '+':
			escala++;
			break;
		case '-':
		 	escala--;
		 	break;
		case '1':
			rotation+=3;
			break;
		case '2':
		 	rotation-=3;
		 	break;


	}
	Desenha();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,600);
	glutInitWindowPosition(320,150);
	glutCreateWindow("BRACO ROBOTICO");
	glutKeyboardFunc(KeyBoard);
	
	glutDisplayFunc(Display);
	glClearColor(1,1,1,1);
	glutMainLoop();
	return 0;
}