#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

// gcc fonte.c -o fonte -lglut -lGL -lGLU -lm

float angle = 45.0;
float rotation = 0.0;

void wireBox(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x / 2, 0, 0);
    glScalef(x, y, z);
    glutWireCube(1);
    glPopMatrix();
}

void init()

{
    glClearColor(0.0, 0.3, 0.2, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0, 1.0, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef( 0.0, 0.0, -8.0 );
    wireBox( 2.0, 0.4, 1.0 );
    glTranslatef( 2.0, 0.0, 0.0 );
    glPushMatrix();
    glRotatef(angle+rotation,0.0,0.0,1.0);
    wireBox( 2.0, 0.4, 1.0 );
    glPopMatrix();
    glPushMatrix();
    glRotatef(-angle+rotation, 0.0, 0.0, 1.0 );
    wireBox( 2.0, 0.4, 1.0 );
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void keySpecial(int key, int x, int y)
{
    printf("(%d, %d)\n", x, y);
    switch (key)
    {
    case GLUT_KEY_DOWN:
        angle += 2.0;
        break;
    case GLUT_KEY_UP:
        angle -= 2.0;
        break;
    case GLUT_KEY_ALT_L:
        rotation -= 5.0;
        break;
    case GLUT_KEY_ALT_R:
        rotation += 5.0;
        break;
    }

    printf("rotation: %f\n", rotation);
    printf("angle: %f\n", angle);
    if (angle > 70.0){
        angle = 70.0;
    } else if (angle < 5){
        angle = 5.0;
    }
    if (rotation > 80.0){
        rotation = 80.0;
    } else if (rotation < -80.0){
        rotation = -80.0;
    }
    glutPostRedisplay();
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

int main(int argc, char **argv)

{

    glutInit(&argc, argv);                       // inicializa
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // mostra o display como
    glutInitWindowSize(1080, 720);                // tamanho da janela
    // glutPostRedisplay
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Jaré");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(myReshape);
    glutSpecialFunc(keySpecial);
    glutMainLoop();

    return 0;
}