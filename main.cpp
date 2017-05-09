
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>


#include <GLUT/glut.h>


#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))


double dim=3.0;
int windowWidth=840;
int windowHeight=680;

void setEye();
void project();
void drawAxes();
void drawMain();


int toggleAxes = 1;
int toggleMode = 0; // projection mode
int th = 0;   // azimuth of view angle
int ph = 0;   // elevation of view angle
int fov = 55; // field of view for perspective
int asp = 1;  // aspect ratio
int objId = 1;
int objSlices = 16;
int objStacks = 16;

/*  Cube vertices */
GLfloat vertA[3] = { 0.5, 0.5, 0.5};
GLfloat vertB[3] = {-0.5, 0.5, 0.5};
GLfloat vertC[3] = {-0.5,-0.5, 0.5};
GLfloat vertD[3] = { 0.5,-0.5, 0.5};
GLfloat vertE[3] = { 0.5, 0.5,-0.5};
GLfloat vertF[3] = {-0.5, 0.5,-0.5};
GLfloat vertG[3] = {-0.5,-0.5,-0.5};
GLfloat vertH[3] = { 0.5,-0.5,-0.5};


void drawMain() {
    
    glColor3f(1.0,1.0,0.0);
//    
//    if (objId>18)
//        objId = 1;
//    
//    // objId == 0 => draw nothing
//    if (objId == 1)
//        glutWireSphere(1,objSlices,objStacks);
//    else if (objId == 2)
//        glutSolidSphere(1,objSlices,objStacks);
//    else if (objId == 3)
//        glutWireCube(1);
//    else if (objId == 4)
//        glutSolidCube(1);
//    else if (objId == 5)
//        glutWireCone(1,2,objSlices,objStacks);
//    else if (objId == 6)
//        glutSolidCone(1,2,objSlices,objStacks);
//    else if (objId == 7)
//        glutWireTorus(1,2,objSlices,objStacks);
//    else if (objId == 8)
//        glutSolidTorus(1,2,objSlices,objStacks);
//    else if (objId == 9)
//        glutWireIcosahedron();
//    else if (objId == 10)
//        glutSolidIcosahedron();
//    else if (objId == 11)
//        glutWireOctahedron();
//    else if (objId == 12)
//        glutSolidOctahedron();
//    else if (objId == 13)
//        glutWireTetrahedron();
//    else if (objId == 14)
//        glutSolidTetrahedron();
//    else if (objId == 15)
//        glutWireDodecahedron();
//    else if (objId == 16)
//        glutSolidDodecahedron();
//    else if (objId == 17)
//        glutWireTeapot(1);
//    else if (objId == 18)
//        glutSolidTeapot(1);
    
    
    double equ[4];
    
    equ[0] = 0;	//0.x
    equ[1] = 0;	//0.y
    equ[2] = -1;//-1.z
    equ[3] = 2;//30
    
    glClipPlane(GL_CLIP_PLANE0, equ);
    
    //now we enable the clip plane
    
    glEnable(GL_CLIP_PLANE0);{
        glColor3f(0,0.3,0.8);	//blue
        
        glPushMatrix();{
            glTranslatef(50,50,30);
            glutWireSphere(20, 20, 20);	//radius, slices(XY), stacks(Z) -- like earth
        }glPopMatrix();
        
        glPushMatrix();{
            glTranslatef(50,-50,30);
            glutWireSphere(20, 20, 20);
        }glPopMatrix();
    }glDisable(GL_CLIP_PLANE0);
    
    
}

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    
    setEye();
    drawAxes();
    drawMain();
    
   // glFlush();
    glutSwapBuffers();
}


void drawAxes(){
    
    if (toggleAxes) {
        
        double len = 3.0;
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_LINES);
        glVertex3d(0,0,0);
        glVertex3d(len,0,0);
        glVertex3d(0,0,0);
        glVertex3d(0,len,0);
        glVertex3d(0,0,0);
        glVertex3d(0,0,len);
        glEnd();
        /*  Label axes */
        glRasterPos3d(len,0,0);
        //print("X");
        glRasterPos3d(0,len,0);
        // print("Y");
        glRasterPos3d(0,0,len);
        // print("Z");
        
    }
}




void reshape(int width,int height){
    
    asp = (height>0) ? (double)width/height : 1;
    glViewport(0,0, width,height);
    project();
}


void windowKey(unsigned char key,int x,int y){
    
    if (key == 27) exit(0);
    else if (key == 'a' || key == 'A') toggleAxes = 1-toggleAxes;
    else if (key == 'm' || key == 'M') toggleMode = 1-toggleMode;
    /*  Change field of view angle */
    else if (key == '-' && key>1) fov--;
    else if (key == '+' && key<179) fov++;
    /*  Change dimensions */
    else if (key == 'D') dim += 0.1;
    else if (key == 'd' && dim>1) dim -= 0.1;
    else if (key == 'f') objId++;
    
    project();
    glutPostRedisplay();
}

void project(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (toggleMode) {
        gluPerspective(fov,asp,dim/4,4*dim);
    }else {
        glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 0.0f, 1.0f);
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void setEye(){
    if (toggleMode) {
        double Ex = -2*dim*Sin(th)*Cos(ph);
        double Ey = +2*dim        *Sin(ph);
        double Ez = +2*dim*Cos(th)*Cos(ph);
        gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ph),0);
    } else {
        glRotatef(ph,1,0,0);
        glRotatef(th,0,1,0);
    }
}


void windowSpecial(int key,int x,int y){
    
    /*  Right arrow key - increase azimuth by 5 degrees */
    if (key == GLUT_KEY_RIGHT) th += 5;
    /*  Left arrow key - decrease azimuth by 5 degrees */
    else if (key == GLUT_KEY_LEFT) th -= 5;
    /*  Up arrow key - increase elevation by 5 degrees */
    else if (key == GLUT_KEY_UP) ph += 5;
    /*  Down arrow key - decrease elevation by 5 degrees */
    else if (key == GLUT_KEY_DOWN) ph -= 5;
    /*  Keep angles to +/-360 degrees */
    th %= 360;
    ph %= 360;
    
    project();
    glutPostRedisplay();
}

int main(int argc,char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Childrens Room");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(windowKey);
    glutSpecialFunc(windowSpecial);
    
    glutMainLoop();
    return 0;
}