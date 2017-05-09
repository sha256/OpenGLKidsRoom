//
//  cart.cpp
//  Offline1
//
//  Created by Shamim Hasnath on 10/6/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include "Header.h"

void drawCart(){
    
    color(LB_PILLER_VAR2);
    
    glPushMatrix();{
        glTranslatef(0, 9, 10);
        glScalef(13, 10, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(0, -5, 20.0);
        glScalef(1.4, 1.4, 1);
        holedRect();
    }glPopMatrix();
    
    color(LB_PILLER_VAR1);
    
    for(int i=-12; i<15; i+=3){
        glPushMatrix();{
            glTranslatef(i, -3.0, 20);
            glRotatef(16, 1.0, 0, 0);
            glScalef(1.0, 1.0, 20.0);
            glutSolidCube(1.0);
        }glPopMatrix();
        
        glPushMatrix();{
            glTranslatef(i, 20.0, 20);
            glRotatef(-16, 1.0, 0, 0);
            glScalef(1.0, 1.0, 20.0);
            glutSolidCube(1.0);
        }glPopMatrix();
    }
    
    glPushMatrix();{
        glTranslatef(10, 9.5, 8.0);
        glScalef(1.0, 15, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    GLUquadricObj *quadratic = gluNewQuadric();
    color(GREEN_DEEP);
    glPushMatrix();{
        glTranslatef(10, -5.0, 8.0);
        glRotatef(90, 1, 0, 0);
        gluDisk(quadratic, 0, 5, 20, 20);
    }glPopMatrix();
    
    color(BLUE_WLL);
    GLUquadricObj *quadratic2 = gluNewQuadric();
    glPushMatrix();{
        glTranslatef(10, 24.0, 8.0);
        glRotatef(90, 1, 0, 0);
        gluDisk(quadratic2, 0, 5, 20, 20);
    }glPopMatrix();
    
    
    
    // front disks
    
    glPushMatrix();{
        glRotatef(-10, 0, 0, 1);
        color(LB_PILLER);
        glPushMatrix();{
            glTranslatef(-10, 9.5, 8.0);
            glScalef(1.0, 15, 1.0);
            glutSolidCube(2.0);
        }glPopMatrix();
        
        GLUquadricObj *quadratic3 = gluNewQuadric();
        color(YELLOW_DEEP);
        glPushMatrix();{
            glTranslatef(-10, -5.0, 8.0);
            glRotatef(90, 1, 0, 0);
            gluDisk(quadratic3, 0, 5, 20, 20);
        }glPopMatrix();
        
        color(RED_DEEP);
        GLUquadricObj *quadratic4 = gluNewQuadric();
        glPushMatrix();{
            glTranslatef(-10, 24.0, 8.0);
            glRotatef(90, 1, 0, 0);
            gluDisk(quadratic4, 0, 5, 20, 20);
        }glPopMatrix();

        
    }glPopMatrix();
    
    color(LB_PILLER);
    glPushMatrix();{
        glTranslatef(-30, 10, 8);
        glRotatef(-10, 0, 0, 1);
        glScalef(30, 1, 1);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(-58, 15, 8);
        glRotatef(-10, 0, 0, 1);
        glScalef(1, 10, 1);
        glutSolidCube(2.0);
    }glPopMatrix();
    
}


void holedRect(){
    glPushMatrix();{
        glTranslatef(0, 0, 10);
        glScalef(10.0, 1.0, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(0, 20, 10);
        glScalef(10.0, 1.0, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(-9, 10, 10);
        glScalef(1.0, 10.0, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(9, 10, 10);
        glScalef(1.0, 10.0, 1.0);
        glutSolidCube(2.0);
    }glPopMatrix();
}
