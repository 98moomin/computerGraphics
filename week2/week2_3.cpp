// 마우스로 선 그리기
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

double PI = 3.14159265;
int arrowIdx = 1;
int width = 500, height = 500;
struct point {double x; double y;};
vector<point> pts;

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
    glPointSize(10.0);
    glBegin(GL_POINTS);
    for (auto &pt : pts)
        glVertex2d(pt.x, pt.y);
    glEnd();

    glFlush();
}

void Motion(int x, int y)
{
    printf("Mouse motion (%d %d)\n", x, y);

    double xd, yd;
    xd = x / 500.0 * 4.0 - 2.0;
    yd = y / 500.0 * 4.0 - 2.0;
    yd *= -1.0;

    pts.push_back({xd, yd});

    glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        printf("Mouse Click (%d %d)\n", x, y);
    
    glutPostRedisplay();
}

void KeyDown(unsigned char key, int x, int y)
{
    switch (key) {
        case 'p': case 'P':
            printf("Hello world!\n");
            break;
        case 'r':case 'R':
            pts.clear();
            break;
    }


    glutPostRedisplay();
}

void Init()
{
    glViewport(0, 0, width, height);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
}


int main(int argc, char **argv) {
    int mode=GLUT_RGB|GLUT_SINGLE;

    glutInit(&argc, argv);
    glutInitDisplayMode(mode);
    glutInitWindowPosition(300,300);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");
    glutSetWindowTitle("DAU CG");

    Init();
    glutDisplayFunc(DrawPoints);
    glutSpecialFunc(KeySpecial);
    glutMouseFunc(Mouse);
    glutKeyboardFunc(KeyDown);
    glutMotionFunc(Motion);
    glutMainLoop();

    return 1;
}
