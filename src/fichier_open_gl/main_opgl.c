#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -1.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(1.0, -1.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Test");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
