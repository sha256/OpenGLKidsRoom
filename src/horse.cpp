//
//  horse.cpp
//  Offline1
//
//  Created by Shamim Hasnath on 10/6/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include "Header.h"


void horseTop(){
    // circle 1
    
    color(LB_PILLER);
    glPushMatrix();{
        glTranslatef(0, 0, 80);
        glScalef(1.0, 1.0 , 1.0);
        glutSolidSphere(1.5, 20, 20);
    }glPopMatrix();
    
    // cirlce 2
    glPushMatrix();{
        glTranslatef(0, 20, 80);
        glScalef(1.0, 1.0 , 1.0);
        glutSolidSphere(1.5, 20, 20);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(18, -0.4, 80);
        glScalef(18.5, 1.0 , 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(18, 20.3, 80);
        glScalef(18.5, 1.0 , 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(-0.5, 9.9, 80);
        glScalef(1.0, 10.0 , 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(32.3, 11.0, 68.6);
        glScalef(5.0, 6.3, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    color(LB_PILLER);
    glPushMatrix();{
        glTranslatef(42, 11.9, 67.0);
        glScalef(0.6, 1.0, 0.5);
        horseHead();
    }glPopMatrix();
    
    //color(LB_PILLER_VAR2);
    glPushMatrix();{
        glTranslatef(-3, 10, 70);
        glRotatef(15, 0, 1, 0);
        glScalef(1.0, 8.0, 8.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
   

}


void displayHorse(){
    
    glPushMatrix();{
        glTranslatef(4, 4, 0);
        horseTop();
    }glPopMatrix();
    
   
    
    // rotated reck
    glPushMatrix();{
        glTranslatef(15, 15, 65);
        glScalef(1.3, 1.3, 1.0);
        skewedPlane();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(25, 0, 20);
        horseMover();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(25, 40, 20);
        horseMover();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-10, 20.0, 4);
        glScalef(2.0, 20, 2.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(55, 20.0, 3);
        glScalef(2.0, 20, 2.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    //color(LB_PILLER_VAR1);
    
    glPushMatrix();{
        glTranslatef(-4, 2, 31.5);
        glRotatef(16, -0.2, 1, 0);
        glScalef(1.3, 1.3, 31.5);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-2, 31, 31.5);
        glRotatef(20, 0.7, 1, 0);
        glScalef(1.3, 1.3, 31.5);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(47, 6, 34.5);
        glRotatef(-17, 0.9, 1, 0);
        glScalef(1.3, 1.3, 34.5);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(47, 30, 35.5);
        glRotatef(-21.4, -1.9, 1, 0);
        glScalef(1.3, 1.3, 35.5);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    //glColor3f(1.0, 0.0, 1.0);
    color(LB_PILLER_VAR2);
    glPushMatrix();{
        glTranslatef(37.5, 14.0, 80.5);
        glScalef(1.0, 9.5, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(45.5, 18.0, 40.5);
        glScalef(1.0, 16, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
}

void horseMover(){
    GLdouble eqn1[4] = {0.0, 0.0, -1.0, -10.0 };
    glClipPlane( GL_CLIP_PLANE0, eqn1 );
    
    glEnable(GL_CLIP_PLANE0);
    glPushMatrix();{
        glRotatef(90, 1.0, 0.0, 0);
        glScalef(3, 1.0, 1.0);
        glutSolidTorus(2, 20, 40, 40);
    }glPopMatrix();
    glDisable(GL_CLIP_PLANE0);
}

void horseHead(){
    GLdouble eqn1[4] = {0.0, 0.0, 1.0, 10.0 };
    glPushMatrix();{
        glTranslatef(0, 0, 30.0);
        glRotatef(-75, 0, 1, 0);
        glClipPlane( GL_CLIP_PLANE1, eqn1 );
    }glPopMatrix();
    
    GLdouble eqn2[4] = { 0.0, 0.0, 1.0, -1.0 };
    glPushMatrix();{
        glClipPlane(GL_CLIP_PLANE0, eqn2);
    }glPopMatrix();
    
    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_CLIP_PLANE1);
    glPushMatrix();{
        glRotatef(90, 1.0, 0.0, 0);
        glScalef(1.0, 4 , 0.4);
        glutSolidTorus(5, 15, 40, 40);
    }glPopMatrix();
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE0);
}

void skewedPlane(){
    GLdouble eqn1[4] = {0.0, 1.0, 0.0, 8.0 };
    glPushMatrix();{
        glRotatef(15, 0, 0, 1);
        glClipPlane( GL_CLIP_PLANE1, eqn1 );
    }glPopMatrix();
    
    GLdouble eqn2[4] = { 0.0, -1.0, 0.0, 8.0 };
    glPushMatrix();{
        glRotatef(-15, 0, 0, 1);
        glTranslatef(0.0, 0.0f, 0.0f );
        glClipPlane(GL_CLIP_PLANE0, eqn2);
    }glPopMatrix();
    
    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_CLIP_PLANE1);
    glPushMatrix();{
        glRotatef(-15, 0, 1.0, 0);
        glScalef(13.0, 12.0 , 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE0);
}
