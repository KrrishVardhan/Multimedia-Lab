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
    
    // Vertical Line
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2i(0, -100);
    glVertex2i(0, 0);

    glVertex2i(4, -100);
    glVertex2i(4, 0);

    glEnd();
    
    // Draw hexagon
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);

    int ox = 0, oy = 45, r2 = 50;

    // Calculate 6 vertices at 0°, 60°, 120°, 180°, 240°, 300°
    int x0 = ox + r2 * cos(0 * 3.14/180);
    int y0 = oy + r2 * sin(0 * 3.14/180);

    int x_1 = ox + r2 * cos(60 * 3.14/180);
    int y_1 = oy + r2 * sin(60 * 3.14/180);

    int x_2 = ox + r2 * cos(120 * 3.14/180);
    int y_2 = oy + r2 * sin(120 * 3.14/180);

    int x3 = ox + r2 * cos(180 * 3.14/180);
    int y3 = oy + r2 * sin(180 * 3.14/180);

    int x4 = ox + r2 * cos(240 * 3.14/180);
    int y4 = oy + r2 * sin(240 * 3.14/180);

    int x5 = ox + r2 * cos(300 * 3.14/180);
    int y5 = oy + r2 * sin(300 * 3.14/180);

    // Draw 6 lines
    glVertex2i(x0, y0); glVertex2i(x_1, y_1);  // line 1
    glVertex2i(x_1, y_1); glVertex2i(x_2, y_2);  // line 2
    glVertex2i(x_2, y_2); glVertex2i(x3, y3);  // line 3
    glVertex2i(x3, y3); glVertex2i(x4, y4);  // line 4
    glVertex2i(x4, y4); glVertex2i(x5, y5);  // line 5
    glVertex2i(x5, y5); glVertex2i(x0, y0);  // line 6

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