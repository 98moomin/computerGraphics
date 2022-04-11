#define GL_SILENCE_DEPRECATION

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <iostream>

using namespace std;

void MyLightInit() {
    GLfloat global_ambient[] = { 0.5, 0.5, 0.5, 1.0 };    //¿¸ø™ ¡÷∫Øπ›ªÁ
    
    GLfloat Light0_Ambient[] = { 1.0, 1.0, 1.0, 1.0 };    //0π¯ ±§ø¯ ∆Øº∫
    GLfloat Light0_Diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat Light0_Specular[] = { 1.0, 1.0, 1.0, 1.0 };
    
    GLfloat Light1_Ambient[] = { 0.3, 0.3, 0.3, 1.0 };    //1π¯ ±§ø¯ ∆Øº∫
    GLfloat Light1_Diffuse[] = { 0.3, 0.3, 0.3, 0.3 };
    GLfloat Light1_Specular[] = { 1.0, 1.0, 1.0, 1.0 };
    
    GLfloat Light0_Position[] = { 0.0, 0.0, 1.0, 1.0 };    //0π¯ ±§ø¯¿ßƒ°
    GLfloat Light0_Direction[] = { 0.0, 0.0, -1.0 };        //0π¯ ±§ø¯ πÊ«‚
    GLfloat Light0_Cutoff[] = { 7.0 };                    //0π¯ ±§ø¯ ∞¢µµ
    
    GLfloat Light1_Position[] = { 0.0, 0.0, 1.0, 1.0 };    //1π¯ ±§ø¯¿ßƒ°
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, Light0_Ambient);    //0π¯ ±§ø¯ ∆Øº∫«“¥Á
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Light0_Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, Light0_Specular);
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, Light1_Ambient);    //1π¯ ±§ø¯ ∆Øº∫«“¥Á
    glLightfv(GL_LIGHT1, GL_DIFFUSE, Light1_Diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, Light1_Specular);
    
    glLightfv(GL_LIGHT0, GL_POSITION, Light0_Position);    //Ω∫∆˜∆Æ∂Û¿Ã∆Æ
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Light0_Direction);    //πÊ«‚
    glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, Light0_Cutoff);    //∞¢µµ
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1.0);            //∫˚ ∞®ºË ¡§µµ [0~128]
    
    GLfloat material_ambient[] = { 0.0, 0.0, 0.0, 1.0 };    //π∞√º ∆Øº∫
    GLfloat material_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 127.0 };
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);//π∞√º ∆Øº∫«“¥Á
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//¿¸ø™¡÷∫Øπ›ªÁ
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); //±Ÿ¡¢Ω√¡°
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);    //±Ì¿Ã πˆ∆€ »∞º∫»≠
    glEnable(GL_LIGHTING);        //¡∂∏Ì »∞º∫»≠
    glEnable(GL_LIGHT0);        //0π¯ ±§ø¯ »∞º∫»≠
    glEnable(GL_LIGHT1);        //1π¯ ±§ø¯ »∞º∫»≠
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);     //Ω√¡°∫Ø»Ø
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            glPushMatrix();
            glTranslatef(-0.5 + i * 0.3, -0.5 + j * 0.3, 0.0);
            glutSolidSphere(0.2, 50, 50);
            glPopMatrix();
        }
    }
    glDisable(GL_LIGHTING);
    glTranslatef(0.0, 0.0, 1.0);
    glutWireCone(0.05, 0.1, 50, 50);
    glEnable(GL_LIGHTING);
    glFlush();
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLsizei)w / (GLsizei)h, 0.1, 100);
    glutPostRedisplay();
}

void KeySpecial(int key, int x, int y){
    switch(key) {
        case GLUT_KEY_UP:
            break;
        case GLUT_KEY_DOWN:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Spotlight");
    glClearColor(0.5, 0.5, 0.5, 0.5);
    MyLightInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutSpecialFunc(KeySpecial);
    glutMainLoop();
    return 0;
}

