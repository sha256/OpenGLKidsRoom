//
//  largebed.cpp
//  Offline1
//
//  Created by Shamim Hasnath on 10/5/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include "Header.h"

void displayLargeBed(){
    
    double height = 120;
    double woodThickness = 2.0;
    
    // curtain front right;
    color(WHITISH_ROOF);
    glPushMatrix();{
        glTranslatef(30, 5, 55);
         glRotatef(5, 1, 0, 0);
        glScalef(1.0, 0.3, 72);
        drawCurtain(40);
    }glPopMatrix();
    
    // curtain front left
    glPushMatrix();{
        glTranslatef(-100, 5, 55);
        glRotatef(5, 1, 0, 0);
        glScalef(1.0, 0.3, 72);
        drawCurtain(80);
    }glPopMatrix();
    
    // curtain right side
    glPushMatrix();{
        glTranslatef(70, 5, 55);
        glRotatef(90, 0, 0, 1);
        glScalef(1.0, 0.3, 72);
        drawCurtain(75);
    }glPopMatrix();
    
    // curtain left side;
    glPushMatrix();{
        glTranslatef(-100, 5, 55);
        glRotatef(90, 0, 0, 1);
        glScalef(1.0, 0.3, 72);
        drawCurtain(75);
    }glPopMatrix();

    
    // 1
    color(LB_PILLER);
    glPushMatrix();{
        glTranslatef(70.0, 0, height/2);
        glScalef(10.0, woodThickness, height);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    //2
    glPushMatrix();{
        glTranslatef(30.0, 0, height/2);
        glScalef(10.0, woodThickness, height);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    //3
    glPushMatrix();{
        glTranslatef(-20.0, 0, height/2);
        glScalef(10.0, woodThickness, height);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    //4
    glPushMatrix();{
        glTranslatef(-100.0, 0, height/2);
        glScalef(10.0, woodThickness, height);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    glColor3f(1.0, 0.0, 0.0);
    
    // 5
    color(LB_PILLER_VAR1);
    glPushMatrix();{
        glTranslatef(-15.0, woodThickness, height-25);
        glScalef(180, woodThickness, 10.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    // 7
    glPushMatrix();{
        glTranslatef(74, 40, height-25);
        glScalef(woodThickness, 78, 10.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    // 7 below 1
    glPushMatrix();{
        glTranslatef(74, 40, 50);
        glScalef(woodThickness, 78, 6.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    // 7 below 2
    glPushMatrix();{
        glTranslatef(74, 40, 30);
        glScalef(woodThickness, 78, 10.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    // 7 opposite
    glPushMatrix();{
        glTranslatef(-105, 40, height-15);
        glScalef(woodThickness, 80, 30.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    color(LB_STICKS);
    for(int i=0; i<4; i++){
        glPushMatrix();{
            glTranslatef(50.0, 0, i*25 + 10.0);
            glScalef(40.0, 4, 1);
            glutSolidCube(1.0);
        }glPopMatrix();
    }
    
    // back wall
    color(LB_PILLER);
    glPushMatrix();{
        glTranslatef(-15.0, 80, height/2);
        glScalef(180, woodThickness, height);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    
    // bed bottom
    
    //glColor3f(0.0, 1.0, 1.0);
    color(LB_BED_BOTTOM);
    glPushMatrix();{
        glTranslatef(-15.0, 40, 8.0);
        glScalef(180, 80, 16.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    //6
    color(LB_PILLER_VAR1);
    glPushMatrix();{
        glTranslatef(-60.0, -2, height-8);
        glScalef(90, 2, 16.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    
    // bed top
    color(YELLOW_DEEP);
    glPushMatrix();{
        glTranslatef(-15.0, 40, height-16);
        glScalef(180, 78, 8.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    color(LB_PILLER_VAR2);
    
    glPushMatrix();{
        glTranslatef(5, -60, 0);
        curvedStand();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(45, -60, 0);
        curvedStand();
    }glPopMatrix();
    
    // 15
    color(LB_PILLER_VAR2);
    glPushMatrix();{
        glTranslatef(-15, -30, 82);
        glRotatef(-52, 1, 0, 0);
        glScalef(2.0, 15.0, 90);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    // 16
    
    glPushMatrix();{
        glTranslatef(25, -30, 82);
        glRotatef(-52, 1, 0, 0);
        glScalef(2.0, 15.0, 90);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    
    color(BLUE_WLL);
    glPushMatrix();{
        glTranslatef(5, -32, 79);
        glRotatef(-52, 1, 0, 0);
        glScalef(40.0, 2.0, 90);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    color(LB_PILLER_VAR2);
    //12
    glPushMatrix();{
        glTranslatef(5, -76, 20);
        glScalef(38.0, 2.0, 10.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    //11
    color(BLUE_WLL);
    glPushMatrix();{
        glTranslatef(5, -68, 50);
        glScalef(38.0, 2.0, 5.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    
    // 10
    color(LB_PILLER);
    glPushMatrix();{
        glTranslatef(5, 0, 155);
        glScalef(41.0, 2.0, 5.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    //13
    color(LB_PILLER_VAR2);
    glPushMatrix();{
        glTranslatef(27, 0, 125);
        glScalef(2.0, 7.0, 70);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    //14
    glPushMatrix();{
        glTranslatef(-17, 0, 125);
        glScalef(2.0, 7.0, 70);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    
}

void curvedStand(){
    
    GLdouble eqn1[4] = { 0.0, -5.0, -1.0, 0.0 };
    glPushMatrix();{
        glTranslatef(0.0, 9.0f, 0.0f );
        glClipPlane( GL_CLIP_PLANE1, eqn1 );
    }glPopMatrix();
    
    GLdouble eqn2[4] = { 0.0, 0.0, 5.0, 0.0 };
    glClipPlane(GL_CLIP_PLANE0, eqn2);
    
    glEnable(GL_CLIP_PLANE1);
    glEnable( GL_CLIP_PLANE0 );
    glPushMatrix();{
        glTranslatef(-20, 0, 20);
        glRotatef(90, 0, 1, 0);
        glScalef(1.2, 0.5 , 0.2);
        glutSolidTorus(10, 30, 20, 22);
    }glPopMatrix();
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);

}

void drawCurtain(int len){
    double j = 0.0;
    for(int i=0; i<len; i++){
        double x = i;
        double y = sin(3.1416 * j/180.0) * 10;
        glPushMatrix();{
            glTranslatef(x, y, 0);
            glScalef(1, 2.0, 1.0);
            glutSolidCube(1.0);
        }glPopMatrix();
        j += 20;
    }
  
}

