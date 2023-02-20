



































































//ELLIPSE GO BRRRR


//#include <GL/glut.h>
//#include <stdio.h>
//#include<stdlib.h>
//
//int xc, yc, rx, ry;
//
//void drawEllipse(int xc, int yc, int x, int y) {
//    glBegin(GL_POINTS);
//    glVertex2i(xc + x, yc + y);
//    glVertex2i(xc - x, yc + y);
//    glVertex2i(xc + x, yc - y);
//    glVertex2i(xc - x, yc - y);
//    glEnd();
//}
//
//void midpointEllipse(int xc, int yc, int rx, int ry) {
//    float dx, dy, d1, d2, x, y;
//    x = 0;
//    y = ry;
//    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
//    dx = 2 * ry * ry * x;
//    dy = 2 * rx * rx * y;
//
//    while (dx < dy) {
//        drawEllipse(xc, yc, x, y);
//        x++;
//        dx = dx + (2 * ry * ry);
//        if (d1 < 0)
//            d1 = d1 + dx + (ry * ry);
//        else {
//            y--;
//            dy = dy - (2 * rx * rx);
//            d1 = d1 + dx - dy + (ry * ry);
//        }
//    }
//
//    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
//        ((rx * rx) * ((y - 1) * (y - 1))) -
//        (rx * rx * ry * ry);
//
//    while (y >= 0) {
//        drawEllipse(xc, yc, x, y);
//        y--;
//        dy = dy - (2 * rx * rx);
//        if (d2 > 0)
//            d2 = d2 + (rx * rx) - dy;
//        else {
//            x++;
//            dx = dx + (2 * ry * ry);
//            d2 = d2 + dx - dy + (rx * rx);
//        }
//    }
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    midpointEllipse(xc, yc, rx, ry);
//    glFlush();
//}
//
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glColor3f(1.0, 1.0, 1.0);
//    glPointSize(2.0);
//    gluOrtho2D(0, 500, 0, 500);
//}
//
//int main(int argc, char** argv) {
//    printf("Enter the center coordinates: ");
//    scanf_s("%d %d", &xc, &yc);
//    printf("Enter the x-radius: ");
//    scanf_s("%d", &rx);
//    printf("Enter the y-radius: ");
//    scanf_s("%d", &ry);
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}





















































//CIRCLE-MIDPOINT GO BRRRRRR


//#include <GL/glut.h>
//#include <math.h>
//
//
//void drawCircle(int x0, int y0, int radius)
//{
//    int x = radius;
//    int y = 0;
//    int decisionOver2 = 1 - x;   // decision variable initialized
//
//    while (y <= x)
//    {
//        // draw the eight octants of the circle
//        glBegin(GL_POINTS);
//        glVertex2i(x + x0, y + y0);
//        glVertex2i(y + x0, x + y0);
//        glVertex2i(-x + x0, y + y0);
//        glVertex2i(-y + x0, x + y0);
//        glVertex2i(-x + x0, -y + y0);
//        glVertex2i(-y + x0, -x + y0);
//        glVertex2i(x + x0, -y + y0);
//        glVertex2i(y + x0, -x + y0);
//        glEnd();
//
//        y++;
//        if (decisionOver2 <= 0)
//        {
//            decisionOver2 += 2 * y + 1;
//        }
//        else
//        {
//            x--;
//            decisionOver2 += 2 * (y - x) + 1;
//        }
//    }
//}
//
//// function to display the circle on the screen
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);  // set the color of the circle to white
//    drawCircle(250, 250, 100); // call the function to draw the circle
//    glFlush();
//}
//
//// function to set up the screen and display the circle
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Midpoint Circle Algorithm");
//    glClearColor(0.0, 0.0, 0.0, 0.0); // set the background color to black
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, 500, 0, 500); // set the size of the screen
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}











































//CIRCLE-BRESSENHAM GO BRRRRR


//#include <GL/glut.h>
//
//void display() {
//    int xc = 300; // x-coordinate of center of circle
//    int yc = 300; // y-coordinate of center of circle
//    int r = 100;  // radius of circle
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1, 1, 1); // set color to white
//
//    int x = 0;
//    int y = r;
//    int d = 3 - 2 * r;
//
//    glBegin(GL_POINTS); // draw points
//    while (x <= y) {
//        glVertex2i(xc + x, yc + y);
//        glVertex2i(xc + y, yc + x);
//        glVertex2i(xc - y, yc + x);
//        glVertex2i(xc - x, yc + y);
//        glVertex2i(xc - x, yc - y);
//        glVertex2i(xc - y, yc - x);
//        glVertex2i(xc + y, yc - x);
//        glVertex2i(xc + x, yc - y);
//        if (d < 0) {
//            d = d + 4 * x + 6;
//        }
//        else {
//            d = d + 4 * (x - y) + 10;
//            y--;
//        }
//        x++;
//    }
//    glEnd();
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(600, 600);
//    glutCreateWindow("Bresenham's Circle Drawing Algorithm");
//    glClearColor(0, 0, 0, 0); // set background color to black
//    gluOrtho2D(0, 600, 0, 600); // set the coordinate system
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}











































//line drawing bressenham go brrrrr

//#include <GL/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void drawLine(int x0, int y0, int x1, int y1) {
//    int dx = abs(x1 - x0);
//    int dy = abs(y1 - y0);
//    int sx = x0 < x1 ? 1 : -1;
//    int sy = y0 < y1 ? 1 : -1;
//    int err = dx - dy;
//    int x = x0;
//    int y = y0;
//    while (x != x1 || y != y1) {
//        glBegin(GL_POINTS);
//        glVertex2i(x, y);
//        glEnd();
//        int e2 = 2 * err;
//        if (e2 > -dy) {
//            err -= dy;
//            x += sx;
//        }
//        if (e2 < dx) {
//            err += dx;
//            y += sy;
//        }
//    }
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0);
//    drawLine(0, 0, 300, 300);
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(640, 480);
//    glutCreateWindow("Bresenham Line Algorithm");
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0, 640, 0, 480, -1, 1);
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}









































//line drawing DDA go brrrrr

//#include <GL/glut.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//float abs(float a) {
//    if (a < 0) {
//        return a * (-1);
//    }
//    else {
//        return a;
//    }
//    return 0;
//}
//
//int x1, y1, x2, y2;
//
//void display(void)
//{
//    float x, y, dx, dy, m;
//    int i, steps;
//
//    // Clear the screen
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Set line color to red
//    glColor3f(1.0, 0.0, 0.0);
//
//    // Calculate dx and dy
//    dx = x2 - x1;
//    dy = y2 - y1;
//
//    // Calculate slope
//    m = dy / dx;
//
//    // Set the starting point
//    x = x1;
//    y = y1;
//
//    // Determine the number of steps to take
//    if (abs(dx) > abs(dy)) {
//        steps = abs(dx);
//    }
//    else {
//        steps = abs(dy);
//    }
//
//    // Draw the line
//    glBegin(GL_POINTS);
//    glVertex2i(x, y);
//
//    for (i = 0; i < steps; i++) {
//        x = x + (dx / steps);
//        y = y + (dy / steps);
//
//        glVertex2i(x, y);
//    }
//
//    glEnd();
//    glFlush();
//}
//
//void init(void)
//{
//    // Set the window background color to white
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//
//    // Set the view port
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0, 500, 0, 500);
//}
//
//int main(int argc, char** argv)
//{
//    printf("Enter the value of x1: ");
//    scanf_s("%d", &x1);
//    printf("Enter the value of y1: ");
//    scanf_s("%d", &y1);
//    printf("Enter the value of x2: ");
//    scanf_s("%d", &x2);
//    printf("Enter the value of y2: ");
//    scanf_s("%d", &y2);
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("DDA Line Drawing Algorithm");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}








//CREATE EMPTY WINDOW

//Black Window
//#include<windows.h>
//#include<GL/GLU.h>
//#include<GL/glut.h>
//void display()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
////Program to create an empty Widnow
//void init()
//{
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 200);
//	glutCreateWindow("empty window");
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}
////************************************************************************
//////White Window
//#include<windows.h>
//#include<GL/GLU.h>
//#include<GL/glut.h>
//void display()
//{
//	glClearColor(1.0, 1.0, 1.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
////Program to create an empty Widdow
//void init() {
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 200);
//	glutCreateWindow("White window");
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}
////************************************************************************
////Color Window
//#include<windows.h>
//#include<GL/GLU.h>
//#include<GL/glut.h>
//void display()
//{
//	glClearColor(0.4, 0.2, 0.1, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
////Program to create an empty Widdow
//void init()
//{
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 200);
//	glutCreateWindow("Color window");
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//	return 0;
//}


//DRAW A POINT



//#include <GL/glut.h>
//#include<stdio.h>
//void init2D(float r, float g, float b)
//{
//	glClearColor(r, g, b, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 1.0, 1.0);
//	glPointSize(10);
//	//Size = 10 for point
//	//draw a points in 100,100
//	glBegin(GL_POINTS);
//	glVertex2i(100, 100);
//	//drawing point at (100,100)
//	glEnd();
//	glFlush();//flushing
//}
//void main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);//initialize GLUT
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(1000, 100);
//	glutCreateWindow("points of size 10");
//	init2D(0.0, 0.0, 0.0);
//	glutDisplayFunc(display);
//	glutMainLoop();//routine
//}


//GREEEN COLOR LINE



//#include <GL/glut.h>
//#include<stdio.h>
//void init2D(float r, float g, float b)
//{
//	glClearColor(r, g, b, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_LINES);
//	glVertex2i(10, 10);//starting vertex
//	glVertex2i(50, 50);//ending vertex
//	glEnd();
//	glFlush();
//}
//void main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);//initialize GLUT
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(250, 250);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Green line");
//	init2D(0.0, 0.0, 0.0);
//	glutDisplayFunc(display);
//	glutMainLoop();
//}


//TRIANGLE



//#include <GL/glut.h>
//#include<stdio.h>
//void init()
//{
//	glClearColor(0, 0, 0, 0);
//	glMatrixMode(GL_PROJECTION);
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.5, 0.6, 0.5);
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(-0.1, -0.4);
//	glVertex2f(-0.7, -0.4);
//	glVertex2f(-0.4, 0.0);
//	glEnd();
//	glFlush();
//}
//void main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Triangle on black background");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//}


//RECTANGLE

//#include <GL/glut.h>
//#include<stdio.h>
//void init()
//{
//	glClearColor(0, 0, 0, 0);
//	glMatrixMode(GL_PROJECTION);
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.5, 0.6, 0.5);
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(-0.1, 0.1);
//	glVertex2f(0.8, 0.1);
//	glVertex2f(0.8, -0.4);
//	glVertex2f(-0.1, -0.4);
//	glEnd();
//	glFlush();
//}
//void main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Rectangle on black background");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//}


