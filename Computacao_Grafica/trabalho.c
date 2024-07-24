/* lightPosition.c - demonstrates how the light position is affected by
 *             the modelview matrix
 *
 *  Left Mouse Button       - change incidence and azimuth angles
 *  Middle Mousebutton      - change the twist angle based on
 *                            horizontal mouse movement
 *  Right Mousebutton       - zoom in and out based on vertical
 *                            mouse movement
 *  <l> key                 - toggle light binding
 *  Escape key              - exit the program
 */

#include <GL/glut.h> /* includes gl.h, glu.h */

#include <math.h>
#include <stdio.h>

/*  Function Prototypes  */

void initgfx();
void drawScene();
void reshape(GLsizei, GLsizei);
void keyboard(GLubyte, GLint, GLint);
void mouse(GLint, GLint, GLint, GLint);
void motion(GLint, GLint);
void moveCar(float x, float y, float z);
void drawCar();
void resetView();
void polarView(GLfloat, GLfloat, GLfloat, GLfloat);
void printHelp(char *);

/* Global Definitions */

#define KEY_ESC 27 /* ascii value for the escape key */

/* Global Variables */

float x_car = 0.0;
float y_car = 0.0;
float z_car = 0.0;

GLfloat redAmbient[] = {0.3, 0.1, 0.1, 1.0};
GLfloat redDiffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat blueAmbient[] = {0.1, 0.1, 0.3, 1.0};
GLfloat blueDiffuse[] = {0.0, 0.0, 1.0, 1.0};
GLfloat yellowDiffuse[] = {1.0, 1.0, 0.0, 1.0};
GLfloat greenDiffuse[] = {0.95, 1.0, 0.76, 1.0};
GLfloat greenEmission[] = {0.4, 0.6, 0.4, 1.0};
GLfloat yellowEmission[] = {0.6, 0.6, 0.0, 1.0};
GLfloat defaultEmission[] = {0.0, 0.0, 0.0, 1.0};
GLfloat whiteSpecular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat greenSpecular[] = {0.0, 1.0, 0.0, 1.0};
GLfloat defaultSpecular[] = {0.0, 0.0, 0.0, 1.0};

enum lighttypes
{
    EYE_LIGHT,
    SCENE_LIGHT
};
static GLint lightpos;

enum actions
{
    MOVE_EYE,
    TWIST_EYE,
    ZOOM,
    MOVE_NONE
};
static GLint action;

static GLdouble xStart = 0.0, yStart = 0.0;

static GLfloat fovy, nearClip, farClip;
static GLfloat distance, twistAngle, incAngle, azimAngle;

int main(int argc, char *argv[])
{
    GLsizei width, height;

    glutInit(&argc, argv);

    width = glutGet(GLUT_SCREEN_WIDTH);
    height = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition(width / 4, height / 4);
    glutInitWindowSize((width / 2) - 4, height / 2);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);

    initgfx();

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutDisplayFunc(drawScene);

    printHelp(argv[0]);

    glutMainLoop();

    return 0;
}

void drawCar() {
   

    // Carroceria
    glColor3f(1.0, 0.0, 0.0); // Vermelho
    glBegin(GL_POLYGON); // Frente
        glVertex3f(x_car, y_car, z_car);
        glVertex3f(x_car+2.0, y_car, z_car);
        glVertex3f(x_car+2.0, y_car+.70, z_car);
        glVertex3f(x_car, y_car+.70, z_car);
    glEnd();

    glBegin(GL_POLYGON); // Trás
        glVertex3f(x_car, y_car, z_car+1.0);
        glVertex3f(x_car+2.0, y_car, z_car+1.0);
        glVertex3f(x_car+2.0, y_car+1.0, z_car+1.0);
        glVertex3f(x_car, y_car+1.0, z_car+1.0);
    glEnd();

    glBegin(GL_POLYGON); // Lateral esquerda
        glVertex3f(x_car, y_car, z_car);
        glVertex3f(x_car, y_car, z_car+1.0);
        glVertex3f(x_car, y_car+1.0, z_car+1.0);
        glVertex3f(x_car, y_car+1.0, z_car);
    glEnd();

    glBegin(GL_POLYGON); // Lateral direita
        glVertex3f(x_car+2.0, y_car, z_car);
        glVertex3f(x_car+2.0, y_car, z_car+1.0);
        glVertex3f(x_car+2.0, y_car+1.0, z_car+1.0);
        glVertex3f(x_car+2.0, y_car+1.0, z_car);
    glEnd();

    glBegin(GL_POLYGON); // Topo
        glVertex3f(x_car, y_car+1.0, z_car);
        glVertex3f(x_car+2.0, y_car+1.0, z_car);
        glVertex3f(x_car+2.0, y_car+1.0, z_car+1.0);
        glVertex3f(x_car, y_car+1.0, z_car+1.0);
    glEnd();

    glBegin(GL_POLYGON); // Base
        glVertex3f(x_car, y_car, z_car);
        glVertex3f(x_car+2.0, y_car, z_car);
        glVertex3f(x_car+2.0, y_car, z_car+1.0);
        glVertex3f(x_car, y_car, z_car+1.0);
    glEnd();

    // Rodas
    glColor3f(0.0, 0.0, 0.0); // Preto
    glPushMatrix();
    glTranslatef(x_car+.5, y_car, z_car);
    glutSolidSphere(0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x_car+1.5, y_car, z_car);
    glutSolidSphere(0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x_car+0.5, y_car, z_car+1.0);
    glutSolidSphere(0.25, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x_car+1.5, y_car, z_car+1.0);
    glutSolidSphere(0.25, 20, 20);
    glPopMatrix();
}

void moveCar(float x, float y, float z) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, redDiffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, defaultSpecular);
        drawCar();
        glPopMatrix();
}

void printHelp(char *progname)
{
    fprintf(stdout, "\n%s - demonstrate how the modelview matrix "
                    "affects the light position\n\n"
                    "Left Mousebutton    - move eye position\n"
                    "Middle Mousebutton     - change twist angle\n"
                    "Right Mousebutton      - move up / down to zoom in / out\n"
                    "Escape Key          - exit the program\n\n",
            progname);
}

void initgfx()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    fovy = 60.0;    /* field of view in Y */
    nearClip = 3.0; /* Near clipping plane location */
    farClip = 12.0; /* Far clipping plane location */

    resetView();

    lightpos = SCENE_LIGHT;

    /* Turn on a default light */
    glEnable(GL_LIGHT0);
}

void keyboard(GLubyte key, GLint x, GLint y)
{
    switch (key)
    {
    case 'l': /* toggle light position */
        // Do nothing
        break;
    case KEY_ESC: /* Exit when the Escape key is pressed */
        exit(0);
    case 'w':
        z_car += 1.0;
        break;
    case 's':
        z_car -= 1.0;
        break;
    case 'a':
        x_car -= 1.0;
        break;
    case 'd':
        x_car += 1.0;   
        break;
    }
    printf("x: %f, y: %f, z: %f\n", x_car, y_car, z_car);
    drawScene();    
    glutPostRedisplay();
}

void mouse(GLint button, GLint state, GLint x, GLint y)
{
    static GLint buttons_down = 0;

    if (state == GLUT_DOWN)
    {
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            action = MOVE_EYE;
            break;
        case GLUT_MIDDLE_BUTTON:
            action = TWIST_EYE;
            break;
        case GLUT_RIGHT_BUTTON:
            action = ZOOM;
            break;
        }

        /* Update the saved mouse position */
        xStart = x;
        yStart = y;
    }
    else
    {
        if (--buttons_down == 0)
            action = MOVE_NONE;
    }
}

void motion(GLint x, GLint y)
{
    switch (action)
    {
    case MOVE_EYE:
        /* Adjust the eye position based on the mouse position */
        azimAngle += (GLdouble)(x - xStart);
        incAngle -= (GLdouble)(y - yStart);
        break;
    case TWIST_EYE:
        /* Adjust the eye twist based on the mouse position */
        twistAngle = fmod(twistAngle + (x - xStart), 360.0);
        break;
    case ZOOM:
        /* Adjust the eye distance based on the mouse position */
        distance -= (GLdouble)(y - yStart) / 10.0;
        break;
    default:
        printf("unknown action %d\n", action);
    }

    /* Update the stored mouse position for later use */
    xStart = x;
    yStart = y;
    glutPostRedisplay();
}

void resetView()
{
    distance = nearClip + (farClip - nearClip) / 2.0;
    twistAngle = 0.0; /* rotation of viewing volume (camera) */
    incAngle = 60.0;
    azimAngle = 0.0;
    fovy = 60.0; /* Field of view in Y angle */
}

void reshape(GLsizei width, GLsizei height)
{
    GLdouble aspect;

    glViewport(0, 0, width, height);

    aspect = (GLdouble)width / (GLdouble)height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, aspect, nearClip, farClip);
    glMatrixMode(GL_MODELVIEW);
}

void polarView(GLfloat distance, GLfloat azimuth, GLfloat incidence, GLfloat twist)
{
    glTranslatef(0.0, 0.0, -distance);
    glRotatef(-twist, 0.0, 0.0, 1.0);
    glRotatef(-incidence, 1.0, 0.0, 0.0);
    glRotatef(-azimuth, 0.0, 0.0, 1.0);
}

void drawScene()
{

    /* local light */
    GLfloat lightPosition[] = {0.0, 4.0, 4.0, 1.0};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    polarView(distance, azimAngle, incAngle, twistAngle);

    glEnable(GL_LIGHTING);
    glPushMatrix();
        glTranslatef(0.0, 4.0, 4.0);
        if (lightpos == SCENE_LIGHT)
        {
            glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        }
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, greenDiffuse);
        glMaterialfv(GL_FRONT, GL_EMISSION, greenEmission);
        glMaterialfv(GL_FRONT, GL_SPECULAR, defaultSpecular);
        glutSolidSphere(0.5, 32, 32);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0, 1.0, 1.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, whiteSpecular);
        glMaterialfv(GL_FRONT, GL_SPECULAR, defaultSpecular);
        glBegin(GL_QUADS);
            glVertex3f(10.0, -0.25, 10.0);
            glVertex3f(-10.0, -0.25, 10.0);
            glVertex3f(-10.0, -0.25, -10.0);
            glVertex3f(10.0, -0.25, -10.0);
        glEnd();
    glPopMatrix();
    drawCar(x_car, y_car, z_car);

    glPopMatrix();
    glutSwapBuffers();
}
