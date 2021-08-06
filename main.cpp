
#include<iostream> #include<math.h> #include<GL/glut.h> using namespace std;
typedef float Matrix4[4][4];
Matrix4 theMatrix;
static GLfloat input[4][3] =
{
{0,3,1},{3,3,2},{3,0,0},{0,0,0}
};
float output[4][3]; float tx,ty, tz;
void setIdentityM(Matrix4 m)
{
for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
m[i][j] = (i == j);
}
void translate(int tx, int ty, int tz)
{
for (int i = 0; i < 4; i++)
{
output[i][0] = input[i][0] + tx;
output[i][1] = input[i][1] + ty;
output[i][2] = input[i][2] + tz;
}
}
void multiplyM()
{
//We Don't require 4th row and column in scaling and rotation
//[8][3]=[8][3]*[3][3] //4th not used for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 3; j++)
{
output[i][j] = 0;
for (int k = 0; k < 3; k++)
{
output[i][j] = output[i][j] + input[i][k] * theMatrix[k][j];
}
}
}
}

void draw(float a[4][3])
{
glColor3f(0.7, 0.4, 0.7); glBegin(GL_POLYGON); glVertex3fv(a[0]); glVertex3fv(a[1]); glVertex3fv(a[2]); glVertex3fv(a[3]); glEnd();
}


void init()
{
glClearColor(1.0, 1.0, 1.0, 1.0); //set backgrond color to white
glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
// Set the no. of Co-ordinates along X & Y axes and their gappings glEnable(GL_DEPTH_TEST);
// To Render the surfaces Properly according to their depths
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0); draw(input); setIdentityM(theMatrix); translate(tx, ty, tz);
glEnable(GL_DEPTH_TEST);
// To Render the surfaces Properly according to their depths
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0); draw(input); setIdentityM(theMatrix); translate(tx, ty, tz)

draw(output); glFlush();
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); glutInitWindowSize(1362, 750);
glutInitWindowPosition(0, 0); glutCreateWindow("3D TRANSFORMATIONS"); init();
cout << "\nEnter Tx,Ty &Tz: \n"; cin >> tx >> ty >> tz; glutDisplayFunc(display); glutMainLoop();
return 0;
}
