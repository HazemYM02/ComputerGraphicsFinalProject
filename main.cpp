#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif
using namespace std;

char title[] = "Hazem Mahmoud Final Project";
GLfloat positions[][3] = {{3.0f, 0.0f, -10.0f}, {-3.5f, 0.0f, -10.0f}, {3, 0, -2}};
GLfloat angle = 0.0f;
GLfloat scale [] = {1.0f, 1.0f, 1.0f};
GLfloat axis [] = {0.0f, 0.0f, 0.0f};
GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 4;
GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 }; //Black Color
GLfloat qaGreen[] = { 1.0, 0.0, 0.0, 1.0 }; //Green Color
GLfloat qaWhite[] = { 1.0, 1.0, 0.0, 1.0 }; //White Color
GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 }; //Red Color

// Set lighting intensity and color
GLfloat qaAmbientLight[] = { 1.0, 2.0, 0.1, 2.0 };
GLfloat qaDiffuseLight[] = { 1, 1, 1, 1.0 };
GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat emitLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };
//Light source position
GLfloat qalightPosition[] = { 0.5, 1.0, 1.0, 0.0 };//position of light
GLfloat qaLightPosition[] = { 1, 0, 0, 1 };// Positional Light
GLfloat qaLightDirection[] = { 1, 1, 1, 0 };// Directional Light
// Light Color
GLfloat colorWhite[] = { 1.00, 1.00, 1.00, 1.0 };
GLfloat colorDarkGray[] = { 0.10, 0.10, 0.10, 1.0 };
GLfloat colorLightGray[] = { 0.75, 0.75, 0.75, 1.0 };


void display();
void idleFunc(void)
{
    if (zRotated > 360.0) {
        zRotated -= 360.0 * floor(zRotated / 360.0);   // Don't allow overflow
    }

    if (yRotated > 360.0) {
        yRotated -= 360.0 * floor(yRotated / 360.0);   // Don't allow overflow
    }
    zRotated += 0.1;
    yRotated += 0.1;

    display();
}
void initLighting()
{

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Set lighting intensity and color
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
    ///
}
void initGL() {
    glEnable(GL_LIGHTING);
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
    glColor3f(0.40, 0.61, 0.94);
    glClearColor(1.0f, 2.0f, 3.0f, 4.0f); // Set background color to black and opaque
    glClearDepth(5.0f);// Set background depth to farthest
    glEnable(GL_DEPTH_TEST);// Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);// Set the type of depth-test
    glShadeModel(GL_SMOOTH);// Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();// Reset the model-view matrix
    glLightfv(GL_LIGHT0, GL_POSITION, qalightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, colorWhite);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, colorLightGray);
    glLightfv(GL_LIGHT0, GL_SPECULAR, colorWhite);
    glTranslatef(positions[0][0], positions[0][1], positions[0][2]);// Move right and into the screen
    glRotatef(angle, axis[0], axis[1], axis[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glBegin(GL_QUADS);// Begin drawing the color cube with 6 quads
    
    
    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Back face (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Right face (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // End of drawing color-cube

    // Render a pyramid consists of 4 triangles
    glLoadIdentity();                  // Reset the model-view matrix
    glTranslatef(positions[1][0], positions[1][1], positions[1][2]);// Move left and into the screen
    glRotatef(angle, axis[0],axis[1],axis[2]);
    glScalef(scale[0], scale[1], scale[2]);

    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
    // Front
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    glColor3f(1.0f, 0.0f, 0.0f);       // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);       // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);       // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();   // Done drawing the pyramid
    glTranslatef(positions[2][0], positions[2][1], positions[2][2]);
    glRotatef(angle, axis[0],axis[1],axis[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glutSolidTeapot(1);               // bottom teapot

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emitLight);

    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Noemit);
    glPopMatrix();
    //glFlush();
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
void pressKey(unsigned char key, int x, int y)
{
    if ((key == 'D') || (key == 'd')) //translate Right (X)
    {
        positions[0][0] += 1.0f;
        positions[1][0] += 1.0f;
        positions[2][0] += 1.0f;
        display();
    }
    else if ((key == 'A') || (key == 'a')) //translate Left (X)
    {
        positions[0][0] -= 1.0f;
        positions[1][0] -= 1.0f;
        positions[2][0] -= 1.0f;
        display();
    }
    else if ((key == 'W') || (key == 'w')) //translate Up (Y)
    {
        positions[0][1] += 1.0f;
        positions[1][1] += 1.0f;
        positions[2][1] += 1.0f;
        display();
    }
    else if ((key == 'S') || (key == 's')) //translate Down (Y)
    {
        positions[0][1] -= 1.0f;
        positions[1][1] -= 1.0f;
        positions[2][1] -= 1.0f;
        display();
    }
    else if ((key == 'Q') || (key == 'q')) //translate clockwise (Z)
    {
        positions[0][2] += 1.0f;
        positions[1][2] += 1.0f;
        positions[2][2] += 1.0f;
        display();
    }
    else if ((key == 'Z') || (key == 'z')) //translate counterclockwise (Z)
    {
        positions[0][2] -= 1.0f;
        positions[1][2] -= 1.0f;
        positions[2][2] -= 1.0f;
        display();
    }
    else if ((key == 'T') || (key == 't')){ //Rotate Left (X)
        
        axis[0] = 1.0f;
        axis[1] = 0.0f;
        axis[2] = 0.0f;
        angle-=1.0f;
        display();
    }
    else if  ((key == 'G') || (key == 'g')){ //Rotate Right (X)
        
        axis[0] = 1.0f;
        axis[1] = 0.0f;
        axis[2] = 0.0f;
        angle+=1.0f;
        display();
    }
    else if ((key == 'Y') ||(key == 'y') ){ //Rotate Up (Y)
        
        axis[0] = 0.0f;
        axis[1] = 1.0f;
        axis[2] = 0.0f;
        angle -= 1.0f;
        display();
    }
    else if ((key == 'H') || (key == 'h')){ //Rotate Down (Y)
        
        axis[0] = 0.0f;
        axis[1] = 1.0f;
        axis[2] = 0.0f;
        angle += 1.0f;
        display();
    }
    else if ((key == 'U') || (key == 'u')){ //Rotate CounterClockwise (Z)
        
        axis[0] = 0.0f;
        axis[1] = 0.0f;
        axis[2] = 1.0f;
        angle -= 1.0f;
        display();
    }
    else if ((key == 'J') || (key == 'j')){ //Rotate Clockwise (Z)
        
        axis[0] = 0.0f;
        axis[1] = 0.0f;
        axis[2] = 1.0f;
        angle += 1.0f;
        display();
    }
    else if ((key == 'O') || (key == 'o')){ //Scale Up
        
        scale [0] +=1.0f;
        scale [1] +=1.0f;
        scale [2] +=1.0f;
        display();
    }
    else if ((key == 'L') || (key == 'l')){ //Scale Down
            scale [0] -=1.0f;
            scale [1] -=1.0f;
            scale [2] -=1.0f;
            display();
    }
    else if ((key == 'X') || (key == 'x')) //lighting Right (X)
    {
        qalightPosition[0] += 1.0f;
        display();
    }
    else if ((key == 'C') || (key == 'c')) //lighting Left (X)
    {
        qalightPosition[0] -= 1.0f;
        display();
    }
    else if ((key == 'V') || (key == 'v')) //lighting Up (Y)
    {
        qalightPosition[1] += 1.0f;
        display();
    }
    else if ((key == 'B') || (key == 'b')) //lighting Down (Y)
    {
        qalightPosition[1] -= 1.0f;
        display();
    }
    else if ((key == 'M') || (key == 'm')) //lighting clockwise (Z)
    {
        qalightPosition[2] += 1.0f;
        display();
    }
    else if ((key == 'N') || (key == 'n')) //lighting counterclockwise (Z)
    {
        qalightPosition[2] -= 1.0f;
        display();
    }
}

void reshape(GLsizei width, GLsizei height){  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    //glutSpecialFunc(pressKey);
    initLighting();
    xRotated = yRotated = zRotated = 0.0;
    glutIdleFunc(idleFunc);
    glutKeyboardFunc(pressKey);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}

