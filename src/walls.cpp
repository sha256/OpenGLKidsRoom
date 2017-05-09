//
//  walls.cpp
//  Offline1
//
//  Created by Shamim Hasnath on 10/7/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include "Header.h"



void leftSideWall(){
    
    color(WHITISH_WLL);
    glPushMatrix();{
        glTranslatef(-150, 135, 250+100);
        glScalef(1.0, 12, 50);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-150, -100, 250+100);
        glScalef(1.0, 20, 50);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-150, 0, 100);
        glScalef(1.0, 40, 0.1);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    color(WIN_CURT);
    glPushMatrix();{
        glTranslatef(-149, 38, 180);
        glScalef(2.0, 37, 40);
        glutSolidCube(2.0);
    };glPopMatrix();
    
    color(WHITISH_WLL);
    glPushMatrix();{
        glTranslatef(-150, 0, 280);
        glScalef(1.0, 40, 12);
        glutSolidCube(10.0);
    }glPopMatrix();
    

}

void drawWall(){
    
    
    GLdouble eqn1[4] = {1.0, 0.0, 0.0, 185.0 };
    GLdouble eqn2[4] = {0.0, 0.0, -1.0, 300};
    
    glClipPlane(GL_CLIP_PLANE1, eqn2);
    
    glPushMatrix();{
        glRotatef(30, 0, 1, 0);
        glClipPlane( GL_CLIP_PLANE0, eqn1 );
    }glPopMatrix();
        
    glEnable(GL_CLIP_PLANE0);
    glEnable(GL_CLIP_PLANE1);
    
    color(BLUE_WLL);
    glPushMatrix();{
        glTranslatef(-150, 0, 40.0);
        glScalef(1.0, 40, 8.0);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    
    color(0xBDA94A);
    glPushMatrix();{
        glTranslatef(-150, 0, 90);
        glScalef(1.0, 40, 2.0);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    color(BLUE_WLL);
    glPushMatrix();{
        glTranslatef(48, 196, 150);
        glScalef(40, 1.0, 30);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-69, 0, -59);
        glRotatef(30, 0, 1, 0);
        leftSideWall();
    };glPopMatrix();
    
    color(WHITISH_ROOF);
    glPushMatrix();{
        glTranslatef(45, 0, 300);
        glScalef(40.0, 40, 1);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE0);
    
    // floor
    color(0xE0D1B9);
    glPushMatrix();{
        glTranslatef(55, -5, -5);
        glScalef(40.0, 40, 1);
        glutSolidCube(10.0);
    }glPopMatrix();
    
    
    
//
}
