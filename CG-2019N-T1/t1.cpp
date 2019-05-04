/*
to compile
 g++ t1.cpp -o compile -lGLEW -lglut -lGLU -lGL
 ./compile

*/
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <iostream>

GLfloat RedRotation = 0.0;
GLfloat GreenRotation = 0.0;
GLfloat BlueRotation = 0.0;
GLfloat Translate = 0.0;
GLfloat move = 0.0;

const unsigned int FRAMES_PER_SECOND = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

void drawCoordinates() {

	// line x
	glColor3f(0, 1, 0); // green x
	glBegin(GL_LINES);
	glVertex2f(-20.0, 0.0);
	glVertex2f(20.0, 0.0);
	glEnd();
	
	// line y 
	glColor3f(0, 0,1); // blue y
	glBegin(GL_LINES);
	glVertex2f(0.0, 20.0);
	glVertex2f(0.0, -2.0);
	glEnd();
}


void Display (){
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0, 0, -10.0f);

	drawCoordinates();

	glTranslatef(Translate,0.0,0.0);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);//black
	glTranslatef(0.0, 1.0, 0.0);
	glutWireCube(1.0);
	glPopMatrix();

	glRotatef(move,0.0f,1.0f,0.0f);
	glRotatef(RedRotation, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);//red
	glTranslatef(0.0, 2.0, 0.0);
	glutWireCube(1.0);
	glPopMatrix();

	glRotatef(GreenRotation, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);//green
	glTranslatef(0.0, 3.0, 0.0);
	glutWireCube(1.0);
	glPopMatrix();
	
	glRotatef(BlueRotation, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);//blue
	glTranslatef(0.0, 4.0, 0.0);
	glScalef(1, 2, 1);
	glutWireCube(1.0);
	glPopMatrix();
		

	glutSwapBuffers();																																				
}
void KeyBoard(unsigned char tecla, GLint x, GLint y){
	switch(tecla){
		//Red rotation
		case 'q':
			if (RedRotation < 28)
			{
				RedRotation+=0.25;
			}
			break;
		case 'a':
		 	if (RedRotation > -28)
			{
				RedRotation-=0.25;
			}
			break;
		//green rotation
		case 'w':
			if (GreenRotation < 18)
			{
				GreenRotation+=0.25;
			}
			break;
		case 's':
		 	if (GreenRotation > -18)
			{
				GreenRotation-=0.25;
			}
			break;
		//blue rotation
		case 'e':
			if (BlueRotation < 10)
			{
				BlueRotation+=0.25;
			}
			break;
		case 'd':
		 	if (BlueRotation > -10)
			{
				BlueRotation-=0.25;
			}
			break;
		//axis x rotation
		case 'x':
				move+=0.025;
			break;
		case 'z':
				move-=0.025;
			break;

	}
	glutPostRedisplay();
}
void Direction(GLint tecla, GLint x, GLint y){
	switch(tecla){
		case GLUT_KEY_LEFT:move -=0.25; 
				break;
		case GLUT_KEY_RIGHT:move +=0.25;
				break;
	}
	glutPostRedisplay();
}
void initView(void){
	//glViewport(0,0,(GLsizei)WIDTH,(GLsizei)HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);

	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(850,700);
	glutInitWindowPosition(320,150);
	glutCreateWindow("BRACO ROBOTICO");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(Display);
	glutSpecialFunc(Direction);
	glutKeyboardFunc(KeyBoard);
	
	
	
	initView();
	glutMainLoop();
	return 0;
}