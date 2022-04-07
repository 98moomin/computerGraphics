// 삼각형, 사각형 그리기
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

void init();
void display();

void DrawPoints(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glPointSize(0.1);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.1, 0);
    glVertex2f(0.1, 0);
    glVertex2f(0, 0.2);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.3, 0.2);
    glVertex2f(0.1, 0.2);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    int mode=GLUT_RGB|GLUT_SINGLE;

    glutInit(&argc, argv);
    glutInitDisplayMode(mode);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL");
    glutSetWindowTitle("DAU CG");

    glutDisplayFunc(DrawPoints);
    glutMainLoop();
    return 1;
}
