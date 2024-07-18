#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

int isPerspective = 1;

void drawGrid(float size, int divisions) {
    float step = size / divisions;
    float halfSize = size / 2;

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);

    for (int i = 0; i <= divisions; ++i) {
        float coord = -halfSize + i * step;
        
        glVertex3f(coord, 0, -halfSize);
        glVertex3f(coord, 0, halfSize);

        glVertex3f(-halfSize, 0, coord);
        glVertex3f(halfSize, 0, coord);
    }

    glEnd();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (isPerspective) {
        gluPerspective(0.0, 1.0, 1.0, 10.0);
    } else {
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    }
    glScalef(1.0, 1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    if (isPerspective) {
        gluLookAt(0, 5, 5, 0, 0, 0, 0, 1, 0);
    } else {
        glTranslatef(0, 0, 15);
    }

    drawGrid(10.0, 10);
    glutSwapBuffers();
}


void myReshape(int winWidth, int winHeight) {
    glViewport(0, 0, winWidth, winHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)winWidth / (float)winHeight;
    if (isPerspective) {
        gluPerspective(45.0, aspect, 1.0, 50.0);
    } else {
        if (aspect >= 1.0) {
            glOrtho(-10.0 * aspect, 10.0 * aspect, -10.0, 10.0, -10.0, 20.0);
        } else {
            glOrtho(-10.0, 10.0, -10.0 / aspect, 10.0 / aspect, -10.0, 20.0);
        }
    }

    glMatrixMode(GL_MODELVIEW);
}

void keySpecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1: // Use F1 key for toggling perspective
            isPerspective = !isPerspective;
            init();
            glutPostRedisplay();
        break;
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Perspective Toggle Example");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutSpecialFunc(keySpecial);
    glutMainLoop();

    return 0;
}
