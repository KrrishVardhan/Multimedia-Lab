#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}
void SetLine() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    // Top
    glVertex2i(-20, 80);
    glVertex2i(20, 100);
    glEnd();
    glFlush();
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 30);
    glutInitWindowSize(1000, 1000);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Pixel Window");

    init();
    glutDisplayFunc(SetLine);
    glutMainLoop();
    return 0;
}