// 원그리기 (키보드 상,하 키 누르면 원이 됨)
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>

double PI = 3.14159265;
int arrowIdx = 1;

void init();
void display();

void KeySpecial(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        arrowIdx++;
        break;
    case GLUT_KEY_DOWN:
        arrowIdx--;
        break;
    }
    glutPostRedisplay();
}

void DrawPoints(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    glPointSize(0.1);

    double radius = 1.0;
    glBegin(GL_POLYGON);
    for(int i=0;i<=arrowIdx;i++){
        double theta = PI * 2.0 * double(i) / double(arrowIdx);
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        glVertex2f(x, y);
    }
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
    glutSpecialFunc(KeySpecial);

    glutDisplayFunc(DrawPoints);
    glutMainLoop();
    return 1;
}
