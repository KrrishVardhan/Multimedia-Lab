#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}
void Clock() {
    int x1 = 2, y1 = -100, r = 20;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);

    glVertex2i(x1,y1);
    for(int i=0;i<=361;i++){
        int x2 = x1 + r * cos(i*3.14/180);
        int y2 = y1 + r * sin(i*3.14/180);
        glVertex2i(x2,y2); 
    }
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
    glutDisplayFunc(Clock);
    glutMainLoop();
    return 0;
}