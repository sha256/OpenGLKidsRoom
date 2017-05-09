//
//  greenbusket.cpp
//  Offline1
//
//  Created by Shamim Hasnath on 10/6/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include "Header.h"

float green[3] = {135/255.0, 140/255.0, 62/255.0};
float whitish[3] = {175/255.0, 155/255.0, 103/255.0};
float whitish2[3] = {185/255.0, 165/255.0, 113/255.0};

void greenTrianlge(){
    glColor3fv(green);
    GLdouble eqn1[4] = {0.0, 10.0, 0.0, -10.0 };
    glPushMatrix();{
        glRotatef(90, 1, 0, 0);
        glPushMatrix();{
            glRotatef(45, 0, 0, 1);
            glClipPlane( GL_CLIP_PLANE0, eqn1 );
        }glPopMatrix();
        
        glEnable(GL_CLIP_PLANE0);
        glPushMatrix();{
            glScalef(10, 10, 1.0);
            glutSolidCube(2.0);
        }glPopMatrix();
        glDisable(GL_CLIP_PLANE0);
    }glPopMatrix();
    
}

void displayGreenBusket(){
    
    glColor3fv(green);
    glPushMatrix();{
        glTranslatef(0, 0, 2);
        glScalef(40.0, 20.0, 2.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glColor3fv(whitish);
    glPushMatrix();{
        glTranslatef(0, -19, 34);
        glScalef(40.0, 1.0, 30.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(0, 19, 34);
        glScalef(40.0, 1.0, 30.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glColor3fv(whitish2);
    glPushMatrix();{
        glTranslatef(-39, 0, 34);
        glScalef(1.0, 20.0, 30.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glColor3fv(whitish2);
    glPushMatrix();{
        glTranslatef(39, 0, 34);
        glScalef(1.0, 20.0, 30.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-30, -20.0, 54);
        greenTrianlge();
    }glPopMatrix();
    glPushMatrix();{
        glTranslatef(-30, 20.0, 54);
        greenTrianlge();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(30, -20.0, 54);
        glRotatef(180, 0, 0, 1);
        greenTrianlge();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(30, 20.0, 54);
        glRotatef(180, 0, 0, 1);
        greenTrianlge();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-40, -10.0, 54);
        glRotatef(90, 0, 0, 1);
        greenTrianlge();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(40, -10.0, 54);
        glRotatef(90, 0, 0, 1);
        greenTrianlge();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-40, 10.0, 54);
        glRotatef(270, 0, 0, 1);
        greenTrianlge();
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(40, 10.0, 54);
        glRotatef(270, 0, 0, 1);
        greenTrianlge();
    }glPopMatrix();
    
    
}

