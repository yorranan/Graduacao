// #define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

// adicionar as formas a serem mostradas na cena
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha a base da casa
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.4, 0.1);  
    glVertex3f(-8, -8, 0);     // canto inferior esquerdo
    glVertex3f(8, -8, 0);      // canto inferior direito
    glVertex3f(8, 0, 0);       // canto superior direito
    glVertex3f(-8, 0, 0);      // canto superior esquerdo
    glEnd();

    // Desenha o telhado da casa
    glBegin(GL_TRIANGLES);
    glColor3f(1, .4, 0);        
    glVertex3f(-9, 0, 0);      // canto inferior esquerdo
    glVertex3f(9, 0, 0);       // canto inferior direito
    glVertex3f(0, 4.5, 0);       // vértice superior
    glEnd();

    // Desenha a porta da casa
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.15, 0.0);  
    glVertex3f(-1, -8, 0);     // canto inferior esquerdo
    glVertex3f(2.5, -8, 0);      // canto inferior direito
    glVertex3f(2.5, -2, 0);      // canto superior direito
    glVertex3f(-1, -2, 0);     // canto superior esquerdo
    glEnd();

    // Desenha uma janela à esquerda
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.8, 1);    
    glVertex3f(-5.5, -4.5, 0);     // canto inferior esquerdo
    glVertex3f(-1.5, -4.5, 0);     // canto inferior direito
    glVertex3f(-1.5, -2, 0);      // canto superior direito
    glVertex3f(-5.5, -2, 0);      // canto superior esquerdo
    glEnd();

    glutSwapBuffers();
}

void myReshape(int winWidth, int winHeight) // reshape window
{
    int tam = winWidth < winHeight ? winWidth : winHeight;
    glViewport(0, 0, tam, tam); // reset the viewport
}

void myKeyboard(unsigned char c, int x, int y)
{
    switch (c)
    {
    case 'q':
        exit(0);
        break;
    }
}

/*comandos especiais do teclado*/

void keySpecial(int key, int x, int y)
{
    printf("(%d, %d)\n", x, y);
    switch (key)
    {
    case GLUT_KEY_LEFT:
        printf("Left pressed\n");
        break;
    case GLUT_KEY_UP:
        printf("Up pressed\n");
        break;
    case GLUT_KEY_CTRL_L:
        printf("CTRL L pressed\n");
        break;
    case GLUT_KEY_CTRL_R:
        printf("CTRL R pressed\n");
        break;
    }

    if (glutGetModifiers() == GLUT_ACTIVE_ALT) // GLUT_ACTIVE_CTRL ou SHIFT
        printf("ALT pressed\n");
}

// imprimir as coordenadas com o clique do mouse

void myMouse(int b, int s, int x, int y)
{
    switch (b)
    {
    case GLUT_LEFT_BUTTON:
        printf("(%d, %d)\n", x, y);
    }
}

void myMotion(int x, int y)
{
    printf("Motion: (%d, %d)\n", x, y);
}

void init()
{
    glClearColor(1, 1, 0.7627, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(300, 200);                
    glutInitWindowPosition(128, 128);
    glutCreateWindow("Atividade 1 - Yorranan");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(keySpecial);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutMainLoop();
    return 0;
}
