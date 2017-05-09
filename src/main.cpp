#include "Header.h"


#define BLACK 0, 0, 0

//make a global variable -- for tracking the anglular position of camera
double cameraAngle;			//in radian
double cameraAngleDelta;

double cameraHeight;
double cameraRadius;

double rectAngle;	//in degree

bool canDrawGrid;
void drawGrids();

float cartY = 30;
bool yNow = true;
float cartX = 190;
bool xNow = false;
bool backNow = false;


float horseRotateAngle = 0;
bool rotationPositive = true;

bool seeFromTop = false;


void display(){
    
    //clear the display
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(BLACK, 0);	//color black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    if (seeFromTop)
        gluLookAt(50, 0, 250,cameraRadius*cos(cameraAngle), cameraRadius*sin(cameraAngle), 0, 0,0,1);
    else
        gluLookAt(cameraRadius*cos(cameraAngle), cameraRadius*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
    
    glMatrixMode(GL_MODELVIEW);
    
    //drawGrids();
    
    // Small Bed
    
    glPushMatrix();{
        glTranslatef(-120, 0, 0);
        glScalef(0.8, 1.3, 0.8);
        kidsBedSmallDisplay();
    }glPopMatrix();
    
    
    // Shelf
    
    glPushMatrix();{
        glScalef(1.0, 1.2, 1.0);
        glTranslatef(175, 150, 0);
        displayShelf();
    };glPopMatrix();
    
    
    // The large bed
    glPushMatrix();{
        glTranslatef(50, 135, 0);
        glScalef(1.0, 0.7, 1.1);
        displayLargeBed();
    }glPopMatrix();
    
    
    // Horse with animation
    
    
    glPushMatrix();{
        glTranslatef(60, -60, 5);
        glPushMatrix();{
            glRotatef(horseRotateAngle, 0, 1, 0);
            glTranslatef(-20, 0, 0);
            displayHorse();
        }glPopMatrix();
    }glPopMatrix();
    
    // Cart
    
    glPushMatrix();{
        glTranslatef(cartX, cartY, 0);
        
        if (backNow && yNow)
            glRotated(-90, 0, 0, 1);
        else if (backNow && xNow)
            glRotated(180, 0, 0, 1);
        else if (!backNow && yNow)
            glRotatef(90, 0, 0, 1);
        else if (!backNow && xNow)
            glRotated(0, 0, 0, 1);
//        else
//            glRotated(0, 0, 0, 1);
        
        glScalef(1.3, 1.3, 1.3);
        drawCart();
    }glPopMatrix();
    
    // Green Basket
    
    glPushMatrix();{
        glTranslatef(-130, -120, 0);
        glRotatef(90, 0, 0, 1);
        glScalef(0.7, 0.8, 1);
        displayGreenBusket();
    }glPopMatrix();
    
    drawWall();
    

    
    glutSwapBuffers();
}



void drawGrids(){
    if(canDrawGrid == true){
        glColor3f(0.3, 0.3, 0.3);	//grey
        glBegin(GL_LINES);{
            for(int i=-10;i<=10;i++){
                
                if(i==0)
                    continue;	//SKIP the MAIN axes
                
                //lines parallel to Y-axis
                glVertex3f(i*10, -100, 0);
                glVertex3f(i*10,  100, 0);
                
                //lines parallel to X-axis
                glVertex3f(-100, i*10, 0);
                glVertex3f( 100, i*10, 0);
            }
        }glEnd();
    }
    
    // draw the two AXES
    glColor3f(1, 1, 1);	//100% white
    glBegin(GL_LINES);{
        //Y axis
        glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
        glVertex3f(0,  150, 0);
        
        //X axis
        glColor3f(1, 1, 1);	//100% white
        glVertex3f(-150, 0, 0);
        glVertex3f( 150, 0, 0);
    }glEnd();
}

bool gulu = false;
bool mulu = true;

void animate(){
    //codes for any changes in Camera
    
    //cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!
    
    //codes for any changes in Models
    
    rectAngle -= 1;
    
    //printf("%d : %d\n", xNow, yNow);
    if (!backNow && yNow && cartY < -120 && !gulu){
        yNow = false;
        xNow = true;
        gulu = true;
        printf("xnow1");
    } else if (!backNow && xNow && cartX < -20 && gulu){
        yNow = true;
        xNow = false;
        printf("ynow1");
    }
    
    if (!backNow && cartY < -150){
        backNow = true;
        xNow = true;
        yNow = false;
        printf("xnow2");
    }
    
    if (backNow && xNow && cartX > 170){
        yNow = true;
        xNow = false;
        printf("ynow2");
    }
    
    if (backNow && yNow && cartY > 25){
        mulu = false;
    }
    
    
    
    if (mulu){
        if (backNow && xNow)
            cartX++;
        else if (backNow && yNow)
            cartY++;
        else if (xNow)
            cartX--;
        else if (yNow)
            cartY--;
    }
    
    
    if (rotationPositive)
        horseRotateAngle += 0.2;
    else
        horseRotateAngle -= 0.2;
    
    if (horseRotateAngle > 5)
        rotationPositive = false;
    else if (horseRotateAngle < -10)
        rotationPositive = true;
        

    glutPostRedisplay();
}

void keyboardListener(unsigned char key, int x,int y){
    switch(key){
            
        case '1':	//reverse the rotation of camera
            cameraAngleDelta = -cameraAngleDelta;
            break;
            
        case '2':	//increase rotation of camera by 10%
            cameraAngleDelta *= 1.1;
            break;
            
        case '3':	//decrease rotation
            cameraAngleDelta /= 1.1;
            break;
            
        case '8':	//toggle grids
            canDrawGrid = 1 - canDrawGrid;
            break;
            
        case 27:	//ESCAPE KEY -- simply exit
            exit(0);
            break;
        case '0':
            seeFromTop = !seeFromTop;
            glutPostRedisplay();
            break;
        case '9':
            mulu = true;
            break;
        default:
            break;
    }
}

void specialKeyListener(int key, int x,int y){
    switch(key){
        case GLUT_KEY_DOWN:		//down arrow key
            cameraRadius += 10;
            break;
        case GLUT_KEY_UP:		// up arrow key
            if(cameraRadius > 10)
                cameraRadius -= 10;
            break;
            
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_LEFT:
            break;
            
        case GLUT_KEY_PAGE_UP:
            cameraHeight += 10;
            break;
        case GLUT_KEY_PAGE_DOWN:
            cameraHeight -= 10;
            break;
            
        case GLUT_KEY_INSERT:
            break;
            
        case GLUT_KEY_HOME:
            break;
        case GLUT_KEY_END:
            break;
            
        default:
            break;
    }
}

void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
                cameraAngleDelta = -cameraAngleDelta;
            }
            break;
            
        case GLUT_RIGHT_BUTTON:
            //........
            break;
            
        case GLUT_MIDDLE_BUTTON:
            //........
            break;
            
        default:
            break;
    }
}


void init(){
    //codes for initialization
    cameraAngle = 200;	//// init the cameraAngle
    cameraAngleDelta = 0.002;
    rectAngle = 0;
    canDrawGrid = true;
    cameraHeight = 150;
    cameraRadius = 400;
    
    horseRotateAngle = 0;
    
    //clear the screen
    glClearColor(BLACK, 0);
    
    glMatrixMode(GL_PROJECTION);
    
    //initialize the matrix
    glLoadIdentity();
    
    //give PERSPECTIVE parameters
    gluPerspective(70,	1,	0.1,	10000.0);
    
   // gluC
   
}

void drawBitmapText(char *string, float x, float y,float z){
    glColor3f(1, 1, 1);
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
    }
    glColor3f(0, 1, 0);
}
void drawBitmapInt(int n, float x, float y,float z){
    char buffer[4];
    sprintf(buffer, "%d", n);
    drawBitmapText(buffer, x, y, z);
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(840, 680);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);	//Depth, Double buffer, RGB color
    
    glutCreateWindow("My OpenGL Program");
    
    init();
    
    glEnable(GL_DEPTH_TEST);	//enable Depth Testing
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glutDisplayFunc(display);	//display callback function
    glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)
    
    //ADD keyboard listeners:
    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    
    //ADD mouse listeners:
    glutMouseFunc(mouseListener);
    
    glutMainLoop();		//The main loop of OpenGL
    
    return 0;
}
