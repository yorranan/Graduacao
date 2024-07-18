#include<GL/glut.h>
#include<GL/freeglut.h>
#include<stdlib.h>
#include<stdio.h>



void init()

{

   /* Define a cor de fundo (preto) */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //deixa o fundo vermelho
    //glClearColor(1.0, 0.0, 0.0, 0.0);
    /* Inicializa as Matrizes do OpenGL */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0 , 1.0, -1.0, 1.0); //transforma pra visão ortográfica
    /* GluPerspective
    - O campo de ângulo de exibição, em graus, na direção y
    - A taxa de proporção que determina o campo de exibição na direção x.
    A taxa de proporção é a taxa de x (largura) para y (altura).
    - A distância do visualizador até o plano de recorte próximo (sempre positivo).
    - A distância do visualizador para o plano de recorte distante (sempre positivo).*/
    gluPerspective( 45.0, 1.0, 1.0, 5.0);
    //glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);

}



void display(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    //transformando a visão
    //gluLookAt(0, 0, 2, 0, 0, 0, 0, 1, 0);
    //gluLookAt(0, 1, 2, 0, 0, 0, 0, 1, 0);
    //gluLookAt(-1, 1, 2, 0, 0, 0, 0, 1, 0);
    //glScalef(1.0, 2.0, 1.0);
    glutWireCube(0.5);
    glutSwapBuffers();

}



void myReshape(int winWidth, int winHeight) // reshape window

{

    int tam = winWidth < winHeight ? winWidth : winHeight;
    glViewport(0, 0, tam, tam); // reset the viewport

}



int main(int argc, char** argv)

{

    glutInit(&argc, argv); //inicializa
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //mostra o display como
    glutInitWindowSize(350, 350); //tamanho da janela
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}