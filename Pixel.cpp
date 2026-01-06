/* 
Q.1. Write a program to produce a single pixel
as per specified pattern with features like changing
background color, object color, reshaping of window
and repositioning of window.
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init() {
    glClearColor(0.2, 0.2, 0.5, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}
void SetPixel() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.67, 0.0);
    glVertex2i(5, 15);
    glEnd();
    glFlush();
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 30);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Pixel Window");

    init();
    glutDisplayFunc(SetPixel);
    glutMainLoop();
    return 0;
}