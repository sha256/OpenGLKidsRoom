//
//  shelf.cpp
//  Offline1
//
//  Created by Shamim Hasnath on 10/5/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include "Header.h"


void drawHorizontalBook(double x, double y, double z, double width, double thick, double hs){
    glPushMatrix();{
        glTranslatef(x, 0, z);
        glScalef(width, thick, hs);
        glutSolidCube(1.0);
    }glPopMatrix();

}

void drawPenHolder(){
    // bottom
    glPushMatrix();{
        glTranslatef(1, 1, 1);
        glScalef(12, 12, 1.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    //left
    glPushMatrix();{
        glTranslatef(-5, 1, 8);
        glScalef(2, 12, 16.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    //right
    glPushMatrix();{
        glTranslatef(7, 1, 8);
        glScalef(2, 12, 16.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(0, 6, 8);
        glScalef(12, 2, 16.0);
        glutSolidCube(1.0);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(2, -4, 8);
        glScalef(12, 2, 16.0);
        glutSolidCube(1.0);
    }glPopMatrix();
}


void displayShelf(){
    
    double height = 250;
    double qubeSize = 2.0;
    int planes = 6;
    double spaceHeight = height/planes;
    double width = 60.0;
    double thick = 10.0;
    
    color(LB_PILLER);
    
    glPushMatrix();{
        glTranslatef(-width/2, 0, height/qubeSize);
        glScalef(1, thick, height/qubeSize);
        glutSolidCube(qubeSize);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(width/2, 0, height/qubeSize);
        glScalef(1, thick, height/qubeSize);
        glutSolidCube(qubeSize);
    }glPopMatrix();
    
    color(LB_PILLER_VAR2);
    for(int i=0; i<planes; i++){
        glPushMatrix();{
            glTranslatef(0, 0, i*spaceHeight);
            glScalef(width/qubeSize, thick, 1.0);
            glutSolidCube(qubeSize);
        }glPopMatrix();
    }
    
    /***
     Books
    **/
    
    glPushMatrix();{
        glTranslatef(10, 0, 3*spaceHeight);
        color(RED_DEEP);
        drawHorizontalBook(3, 3, 4, 25, 15, 4);
        color(GREEN_DEEP);
        drawHorizontalBook(5, 4, 8, 25, 15, 5);
        color(YELLOW_DEEP);
        drawHorizontalBook(3, 3, 13, 25, 15, 7);
    }glPopMatrix();
    
    
    glPushMatrix();{
        glTranslatef(-24, 0, 3*spaceHeight + 10);
        glRotatef(65, 0, 1, 0);
        color(YELLOW_DEEP);
        drawHorizontalBook(0, 3, 4, 25, 15, 4);
        color(GREEN_DEEP);
        drawHorizontalBook(1, 4, 8, 25, 15, 5);
        color(RED_DEEP);
        drawHorizontalBook(3, 3, 13, 25, 15, 7);
    }glPopMatrix();
    
    color(WHITISH_ROOF);
    glPushMatrix();{
        glTranslatef(10, 4, 5*spaceHeight);
        glScalef(1.0, 1.0, 1.2);
        drawPenHolder();
    }glPopMatrix();
    
    color(RED_DEEP);
    glPushMatrix();{
        glTranslatef(17, 2, 10);
        glutSolidSphere(12, 20, 30);
    }glPopMatrix();
    
    
    
    
    
}
