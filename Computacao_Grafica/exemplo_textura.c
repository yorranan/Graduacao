#include<GL/glut.h>
#include<GL/freeglut.h>
#include<stdlib.h>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdbool.h>

GLfloat distance = 4;
GLfloat azimuth = 0;
GLfloat incidence = 0;
GLfloat twist = 0;
GLuint id;

void createTexture()
{
    // Carrega uma imagem
    SDL_Surface* image = IMG_Load("image.png");
    if (!image)
    {
        printf("Unable to load image: %s\n", SDL_GetError());
        return;
    }

   //Criamos um objeto de textura e obtemos seu id
   glGenTextures(1, &id);
    //Dizemos ao OpenGL que iremos trabalhar com o objeto.
   glBindTexture(GL_TEXTURE_2D, id);
   //Filtro
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   //Descobrimos o formato a partir da imagem
   GLint format = image->format->BytesPerPixel == 3 ? GL_RGB : GL_RGBA;
   //Carregamos a imagem do disco
   glTexImage2D(GL_TEXTURE_2D, 0, format, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);
   //Como o OpenGL copiou a imagem,
   // apagamos a SDL_Image.
   SDL_FreeSurface(image);
}



void polarView(GLfloat distance, GLfloat azimuth, GLfloat incidence, GLfloat twist)
{
	glTranslatef(0.0, 0.0, -distance);
	glRotatef(-twist, 0.0, 0.0, 1.0);
	glRotatef(-incidence, 1.0, 0.0, 0.0);
	glRotatef(-azimuth, 0.0, 0.0, 1.0);
}



void drawSphere(GLfloat radius , GLfloat slices, GLfloat stacks)
{

	GLUquadric *quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	gluQuadricTexture(quadObj, true);
	gluSphere(quadObj, radius, stacks, slices);

}



void display()
{

    /*GlutGet - recupera o estado simples representado por inteiros.
    GLUT_ELAPSED_TIME - Número de milissegundos desde a chamada de glutInit */
    const double a = glutGet(GLUT_ELAPSED_TIME)/100;
    /* Limpa todos os pixels da tela */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    polarView(distance, azimuth, incidence, twist);
    glBindTexture(GL_TEXTURE_2D, id);
    glPushMatrix();
    glRotatef(a, 0, 0, 1);
    glTranslatef(0.8, 0, 0);
    glRotatef(-a*10, 0, 0, 1);
    drawSphere(0.5, 30, 30);

    glPopMatrix();



    // glBindTexture(GL_TEXTURE_2D, id);

    // glPushMatrix();

    // glTranslated(-0.6, -1.2, -6);
    // glBegin(GL_QUADS);
    //     glTexCoord2f(0, 1);
    //     glVertex2f(-1, -1);
    //     glTexCoord2f(1, 1);
    //     glVertex2f(1, -1);
    //     glTexCoord2f(1, 0);
    //     glVertex2f(1, 1);
    //     glTexCoord2f(0, 0);
    //     glVertex2f(-1, 1);
    // glEnd();
   	
   	// glPopMatrix();

    // glPushMatrix();

    // glTranslated(1.4, -1.2, -6);
    // glBegin(GL_TRIANGLES);
    //     glTexCoord2f(0, 1);
    //     glVertex2f(-1, -1);
    //     glTexCoord2f(1, 1);
    //     glVertex2f(1, -1);
    //     glTexCoord2f(0.5, 0);
    //     glVertex2f(0, 1);
    // glEnd();
    
    // glPopMatrix();

    glPopMatrix();
    
    /* Troca buffers – double-buffering */
    glutSwapBuffers();
}
void myReshape(int winWidth, int winHeight) // reshape window
{
    int tam = winWidth < winHeight ? winWidth : winHeight;

    glViewport(0, 0, tam, tam);
}

void myKeyboard(unsigned char c, int x, int y)
{

    /* a acelera a translação e rotação
    d inverte a translação, vai pra sentido horário
    w muda a visualização do ângulo de incidência (desce)
    s muda a visualização do ângulo de incidência (sobe)
    q rotaciona o angulo de visão twist (esquerda)
    e rotaciona o angulo de visão twist (direita)
    z aproxima a visão
    x distancia a visão*/

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
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    createTexture();

    /* Inicializa as Matrizes do OpenGL */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-2.0, 2.0, -2.0 , 2.0, -2.0, 2.0);
    gluPerspective(45, 1, 1, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    // Inicializacoes
	glutInit(&argc, argv);
    //habilita o depth buffer para as superficies escondidas
    glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
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