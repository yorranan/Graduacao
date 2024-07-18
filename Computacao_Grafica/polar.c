#include<GL/glut.h>
#include<GL/freeglut.h>
#include<stdlib.h>
#include<stdio.h>

GLfloat distance = 4;
GLfloat azimuth = 0;
GLfloat incidence = 2;
GLfloat twist = 0;

void polarView(GLfloat distance, GLfloat azimuth, GLfloat incidence, GLfloat twist) {
	glTranslatef(0.0, 0.0, -distance);
	glRotatef(-twist, 0.0, 0.0, 1.0);
	glRotatef(-incidence, 1.0, 0.0, 0.0);
	glRotatef(-azimuth, 0.0, 0.0, 1.0);
}

void display()
{
    const double a = glutGet(GLUT_ELAPSED_TIME)/100;

    /* Limpa todos os pixels da tela */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    polarView(distance, azimuth, incidence, twist);

    glColor3f(1, 1, 0);
    glPushMatrix();
    glRotatef(a, 0, 0, 1);
    glutSolidSphere(0.5, 40, 30);
    glPopMatrix();

    glColor3f(1, 0, 0);
    glPushMatrix();
    glRotatef(a, 0, 0, 1);
    glTranslatef(1.34, 0, 0);
    glRotatef(-a*10, 0, 0, 1);
    glutSolidSphere(0.2, 10, 10);
    // Tentando criar a lua
    glColor3f(0, 0, 1);
    glPushMatrix();
    glRotatef(a, 0, 0, 1);
    glTranslatef(0.5, 0, 0);
    glRotatef(-a*8, 0, 0, 1);
    glutSolidSphere(0.05, 5, 5);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,1);
    glRotatef(a, 0, 0, 1);
    glTranslatef(3, -2, 0);
    glRotatef(-a*10, 0, 0, 1);
    glutSolidSphere(0.23, 20, 20);

    glPushMatrix();
    glColor3f(1, 0, 1);
    glRotatef(a, 0, 0, 1);
    glutSolidTorus(0.01, 0.37, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    /* Troca buffers � double-buffering */
    glutSwapBuffers();
}

void myReshape(int winWidth, int winHeight) // reshape window
{
    int tam = winWidth < winHeight ? winWidth : winHeight;
    glViewport(0, 0, tam, tam);
}

void myKeyboard(unsigned char c, int x, int y)
{
    switch(c){
        case  27: exit(0);          break; // ESC
        case 'a': azimuth   -= 0.5; break;
        case 'd': azimuth   += 0.5; break;
        case 'w': incidence -= 0.5; break;
        case 's': incidence += 0.5; break;
        case 'q': twist     -= 0.5; break;
        case 'e': twist     += 0.5; break;
        case 'z': distance  -= 0.1; break;
        case 'x': distance  += 0.1; break;
    }
    glutPostRedisplay();
}

void keySpecial(int key, int x, int y) {
    //printf("(%d, %d)\n", x, y);
    switch(key){
        case GLUT_KEY_LEFT:  azimuth -=0.5;   break;
        case GLUT_KEY_RIGHT: azimuth +=0.5;   break;
        case GLUT_KEY_UP:    incidence -=0.5; break;
        case GLUT_KEY_DOWN:  incidence +=0.5; break;
    }
    glutPostRedisplay();
}

void myMouse(int b, int s, int x, int y)
{
    switch(b){
        case GLUT_LEFT_BUTTON:
            printf("(%d, %d)\n", x, y);
    }
}

void myMotion(int x, int y){
    printf("Motion: (%d, %d)\n", x, y);
}

// Rotina Callback chamada quando nao ocorre nenhum evento
void idle(){
    glutPostRedisplay(); // Solicita redesenho da tela
}

void init()
{
    /* Define a cor de fundo (preto) */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /* Inicializa as Matrizes do OpenGL */
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-2.0, 2.0, -2.0 , 2.0, -2.0, 2.0);
    gluPerspective(45, 1, 1, 30);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    // Inicializacoes
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    // glClear(GL_COLOR_BUFFER_BIT);
    glutCreateWindow("Sistema Solar");
    init();
	
	// Registro de Rotinas Callback
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(keySpecial);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutIdleFunc(idle);
	
	// Loop principal
    glutMainLoop();

    return 0;
}