#include <GL/glut.h>

void drawHut() {
    // Draw the rectangular base
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.4f, 0.2f); // Brown color
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();

    // Draw the triangular roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.2f); // Red color
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.0, 1.0);
    glEnd();

    // Draw the door
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.0f); // Dark brown color
    glVertex2f(-0.2, -0.5);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.2, 0.0);
    glVertex2f(-0.2, 0.0);
    glEnd();

    // Draw two windows
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.8f, 1.0f); // Light blue color
    glVertex2f(-0.4, 0.2);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.3, 0.4);
    glVertex2f(-0.4, 0.4);

    glVertex2f(0.3, 0.2);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.3, 0.4);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawHut();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("HUT HOUSE");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0, 0.0, 1.0, 0.0); // Set background color to white

    glutMainLoop();

    return 0;
}
