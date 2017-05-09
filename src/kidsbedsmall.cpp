//
//  kidsbedsmall.c
//  Offline1
//
//  Created by Shamim Hasnath on 10/5/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include "Header.h"

void kidsBedSmallDisplay(){
    
    color(LB_PILLER);
    
    glPushMatrix();{
        glTranslatef(10, 0, 0);
        glScaled(1, 3, 1);
        drawCurvedCubicLine(200, 100);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(10, 0, 0);
        glScaled(1, 3, 1);
        drawCurvedCubicLine(200, 40);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-10, -5.0, 0);
        glScaled(1, 3, 1);
        drawCurvedCubicLine(90, 100);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-10, -5.0, 0);
        glScaled(1, 3, 1);
        drawCurvedCubicLine(90, 40);
    }glPopMatrix();
    
    // high cubes
    
    glPushMatrix();{
        glTranslatef(-18.0, -48.0, 50.0);
        glScaled(1.0, 1.2, 20.0);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(18.0, -48.0, 50.0);
        glScaled(1.0, 1.2, 20.0);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(20.5, 51.0, 50.0);
        glScaled(1.0, 1.2, 20.0);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(-15.0, 51.0, 50.0);
        glScaled(1.0, 1.2, 20.0);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(2.0, 51.0, 40.0);
        glScaled(7, 1, 1);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(0.0, -51.0, 40.0);
        glScaled(7, 1, 1);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(2.0, 51.0, 98.0);
        glScaled(7, 1, 1);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(0.0, -51.0, 97.0);
        glScaled(7, 1, 1);
        glutSolidCube(5.0f);
    }glPopMatrix();
    
    glPushMatrix();{
        glScaled(1, 2.5, 1);
        drawSphereLine(0, 67);
    }glPopMatrix();
    
    drawHighCubeLine(51.0);
    drawHighCubeLine(-51.0);
    
    GLdouble eqn1[4] = { 0.0, 1.0, 1.0, 0.0 };
    GLdouble eqn2[4] = { 0.0, -1.0, 1.0, 0.0 };
    
    glPushMatrix();{
        glTranslatef(0, 20, 0);
       glClipPlane(GL_CLIP_PLANE0,eqn1);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(0, -20, 0);
        glClipPlane(GL_CLIP_PLANE1,eqn2);
    }glPopMatrix();
    
    color(LB_PILLER_VAR2);
    glEnable(GL_CLIP_PLANE1);
    glEnable(GL_CLIP_PLANE0);{
        
        glPushMatrix();{
            glScaled(0.9, 1, 1);
            drawCurvedPlate(0, 67);
        }glPopMatrix();
        
        
    }glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    
}

void drawHighCubeLine(float y){
    float x = -15;
    for(int i=0; i<7; i++){
        glPushMatrix();{
            glTranslatef(x + 5*i, y, 66);
            glScaled(1, 1, 30);
            glutSolidCube(2.0);
        }glPopMatrix();
    }
    
}

void drawCurvedPlate(double fromAngle, double z){
    double angle = fromAngle;
    double radius = 30;
    for(int i=0; i<200; i++){
        double m = radius * cos(angle);
        double n = radius * sin(angle);
        //drawBitmapInt(i, m, n, 100);
        glPushMatrix();{
            glTranslatef(m, n, z);
            glScaled(1, 30, 1);
            
            glutSolidCube(2);
        }glPopMatrix();
        
        angle += 3.10;
    }
    //once = true;
    //glDisable(GL_BLEND);
}

void drawSphereLine(double fromAngle, double z){
    double angle = fromAngle;
    double radius = 30;
    //glEnable(GL_BLEND);
    for(int i=0; i<100; i++){
        double m = radius * cos(angle);
        double n = radius * sin(angle);
        
        //
        
        glPushMatrix();{
            glTranslatef(m, n, z);
            glScaled(1, 0.3, 32);
 //           drawBitmapInt(i, m, n, 100);
            if ((i > 17 && i < 59) || (i > 92 && i<100))
                glutSolidCube(0.0);
            else
                glutSolidCube(2);
        }glPopMatrix();
        
        angle += 3.10;
    }
    //once = true;
    //glDisable(GL_BLEND);
}





void drawCurvedCubicLine(double fromAngle, double z){
    
    
    glBegin(GL_QUADS);{
        double angle = fromAngle;
        double radius = 20;
        double leno = 2;
        double zh = 5.0;
        
        for(int i =0; i<200; i++){
            
            double m = radius * cos(angle);
            double n = radius * sin(angle);
            
            //glColor3f(1.0f, 0.0f, 0.0f);     // Red
            
            
            glVertex3f(m+leno, n, z);
            glVertex3f(m, n, z);
            glVertex3f(m,  n+leno, z);
            glVertex3f( m+leno,  n+leno, z);
            
            
            // Back face (z = -1.0f)
            //glColor3f(1.0, 1.0, 0.0f);     // Yellow
            glVertex3f(m+leno, n, z-zh);
            glVertex3f(m, n, z-zh);
            glVertex3f(m,  n+leno, z-zh);
            glVertex3f( m+leno,  n+leno, z-zh);
            
            // Left face (x = -1.0f)
            //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
            glVertex3f(m,  n+leno,  z);
            glVertex3f(m,  n+leno, z-zh);
            glVertex3f(m, n, z-zh);
            glVertex3f(m, n,  z);
            
            // Right face (x = 1.0f)
            //glColor3f(0.0f, 1.0f, 0.0f);     // Magenta
            glVertex3f(m+leno,  n+leno, z-zh);
            glVertex3f(m+leno,  n+leno,  z);
            glVertex3f(m+leno, n,  z);
            glVertex3f(m+leno, n, z-zh);
            
            angle += 0.01;
            
        }
    }glEnd();
}

