//
//  Header.h
//  Offline1
//
//  Created by Shamim Hasnath on 10/5/15.
//  Copyright © 2015 Holo. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifdef __APPLE__

    #include<OpenGL/gl.h>
    #include<OpenGL/glu.h>
    #include<GLUT/glut.h>

#else
    #include <windows.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>

#endif

#ifndef Header_h
#define Header_h

#define WIN_CURT 0xF8F0C2
#define BLUE_WLL 0x404F8B
#define WHITISH_WLL 0xD9DADC
#define WHITISH_ROOF 0xCFCEC9
#define LB_PILLER 0xB89159
#define LB_PILLER_VAR1 0xBAA872
#define LB_PILLER_VAR2 0xA97840
#define LB_STICKS 0xC8AF84
#define LB_BED_BOTTOM 0x837864
#define YELLOW_BED 0xF7E878
#define WHITE 0xFFFFFF
#define CART_NORMAL 0xCBB896
#define YELLOW_DEEP 0xE3C03B
#define GREEN_DEEP 0x355A3B
#define RED_DEEP 0x831D36


#define color(rgbValue) glColor3ub(((rgbValue & 0xFF0000) >> 16), ((rgbValue & 0xFF00) >> 8), rgbValue & 0xFF)

void drawCurvedCubicLine(double fromAngle, double z);
void drawHighCube();
void drawSphereLine(double fromAngle, double z);
void drawBitmapText(char *string, float x, float y,float z);
void drawBitmapInt(int c, float x, float y,float z);
void drawHighCubeLine(float y);
void drawCurvedPlate(double fromAngle, double z);
void kidsBedSmallDisplay();

void drawPenHolder();
void displayShelf();
void drawHorizontalBook(double x, double y, double z, double width, double thick, double hs);


void displayLargeBed();
void drawCurtain(int len);
void drawCurvedJoint(double fromAngle, double z);
void curvedStand();


void displayHorse();
void skewedPlane();
void horseHead();
void horseMover();


void drawCart();
void holedRect();


void displayGreenBusket();
void greenTriangle();

void drawWall();


#endif /* Header_h */
