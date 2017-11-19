/*
  multiview.c


  Program that shows how to use multiple viewports in a single
  context (using scissoring).
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#define TEXTID	5

GLuint sphere_list = 0;
GLfloat spin_x = 0.0;
GLfloat spin_y = 0.0;
int flag=1;
int next=1;
int solid=0;
int form=0;

void DrawTextXY(double x,double y,double z,double scale,char *s)
{
   int i;
   glPushMatrix();
   glTranslatef(x,y,z);

   glScalef(scale,scale,scale);
   for (i=0;i<strlen(s);i++)
   {
glColor3f(1.0,0.0,0.0);
	   glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
   }
   glPopMatrix();
}
void
text(char* string)
{
    char* p;

    for (p = string; *p; p++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
}
void first()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.80,1.50,0.0,0.0018," Graphical Implementation Of ");
	glColor3f(1.0,0.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.20,1.20,0.0,0.0015,"''MULTIPLE VIEWPORT'' ");
	glColor3f(1.0,1.0,1.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.50,0.80,0.0,0.0015,"    USING OpenGL");
	glColor3f(1.0,1.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.5,0.50,0.0,0.001,"                  SUBMITTED BY:");
	glColor3f(1.0,1.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.5,-0.0,0.0,0.001,"         AMAN KUMAR        GOKUL KRISHNA G");
	glColor3f( 1.0,1.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.5,-0.25,0.0,0.001,"         (1ST14CS013)           (1ST14CS052)");
	glColor3f(0.0,1.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.5,-0.5,0.0,0.001,"               UNDER THE GUIDANCE OF:");
	glColor3f(0.0,0.0,1.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.5,-0.8,0.0,0.001,"         Mrs HEMALATHA H M           Mrs Vidya H A");
	glColor3f(0.0,0.0,1.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.5,-1.0,0.0,0.001,"         Asst.Prof,Dept.of CSE         Asst.Prof,Dept.of CSE");
	glColor3f(1.0,0.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-1.5,-1.3,0.0,0.001,"      SAMBHRAM INSTITUTE OF TECHNOLOGY");
	glColor3f(1.0,0.0,1.0);
	glLoadName(TEXTID);
	DrawTextXY(0.8,-1.5,0.0,0.0005,"     PRESS C TO CONTINUE");
	glFlush();
	glutSwapBuffers();
}

void second()
{

    glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.20,1.60,0.0,0.002,"      OPTIONS: ");
    glColor3f(1.0,0.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.20,1.20,0.0,0.001,"         press 1 to execute(Use 's' to toggle solid,'n' for next 'b' for back ");
    glColor3f(1.0,0.0,0.0);
	glLoadName(TEXTID);
	DrawTextXY(-2.20,1.0,0.0,0.001,"         press 2 to exit ");
	glFlush();
	glutSwapBuffers();
}

void
lists(void)
{
    GLfloat gold_Ka[4] = { 0.24725f, 0.1995f, 0.0745f, 1.0f };
    GLfloat gold_Kd[4] = { 0.75164f, 0.60648f, 0.22648f, 1.0f };
    GLfloat gold_Ks[4] = { 0.628281f, 0.555802f, 0.366065f, 1.0f };
    GLfloat gold_Ke    = 41.2f;
    GLfloat silver_Ka[4]  = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat silver_Kd[4]  = { 0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat silver_Ks[4]  = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat silver_Ke     = 12.0f;

    sphere_list = glGenLists(1);
    glNewList(sphere_list, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT,  gold_Ka);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  gold_Kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, gold_Ks);
    glMaterialf(GL_FRONT, GL_SHININESS, gold_Ke);
    glMaterialfv(GL_BACK, GL_AMBIENT,  silver_Ka);
    glMaterialfv(GL_BACK, GL_DIFFUSE,  silver_Kd);
    glMaterialfv(GL_BACK, GL_SPECULAR, silver_Ks);
    glMaterialf(GL_BACK, GL_SHININESS, silver_Ke);
	if(flag==1){ printf("1");
	if(solid==1)
	glutSolidSphere(1.0,20.0,30.0);
	glutWireSphere(1.0,20.0,30.0);	}
	if(flag==2){printf("2");
	if(solid==1)
	glutSolidCube(1.0);
	glutWireCube(1.0);}
	if(flag==3){ printf("3");
		if(solid==1)
		glutSolidCone(1.0,0.9,100,100);
	glutWireCone(1.0,0.9,100,100);	}
	if(flag==4){ printf("4");
		if(solid==1)
		glutSolidTorus(0.3,0.5,16,32);
	glutWireTorus(0.3,0.5,16,32);	}
	if(flag==5){ printf("5");
		if(solid==1)
		glutSolidTeapot(0.6);
	glutWireTeapot(0.6);	}
	if(flag==6)	{printf("6");
	glPushMatrix();
	glScalef(1.0,1.0,1.0);
	if(solid==1)
	glutSolidIcosahedron();
	glutWireIcosahedron();
	glPopMatrix();
	}
    glEndList();
}

void
init(void)
{
    GLfloat light_pos[4] = { 1.0, 1.0, 1.0, 0.0 };

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
}

void
reshape(int w,int h)
{

    glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,
2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
glOrtho(-2.0*(GLfloat)w/(GLfloat)h,
 2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void projection(int width, int height, int perspective)
{
    float ratio = (float)width/height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (perspective)
        gluPerspective(60, ratio, 1, 256);
    else
        glOrtho(-ratio, ratio, -ratio, ratio, 1, 256);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

#define bottom_left                             \
    glViewport(0, 0, width, height);            \
    glScissor(0, 0, width, height)

#define bottom_right                            \
    glViewport(width, 0, width, height);        \
    glScissor(width, 0, width, height)

#define top_left                                \
    glViewport(0, height, width, height);       \
    glScissor(0, height, width, height)

#define top_right                               \
    glViewport(width, height, width, height);   \
    glScissor(width, height, width, height)

#define front                                   \
    projection(width, height, 0);               \
    glRotatef(spin_y, 1.0, 0.0, 0.0);           \
    glRotatef(spin_x, 0.0, 1.0, 0.0)

/*#define back                                    \
    projection(width, height, 0);               \
    glRotatef(180.0, 0.0, 1.0, 0.0);            \
    glRotatef(spin_y, 1.0, 0.0, 0.0);           \
    glRotatef(spin_x, 0.0, 1.0, 0.0)*/

#define right                                   \
    projection(width, height, 0);               \
    glRotatef(90.0, 0.0, 1.0, 0.0);             \
    glRotatef(spin_y, 1.0, 0.0, 0.0);           \
    glRotatef(spin_x, 0.0, 1.0, 0.0)

/*#define left                                    \
    projection(width, height, 0);               \
    glRotatef(-90.0, 0.0, 1.0, 0.0);            \
    glRotatef(spin_y, 1.0, 0.0, 0.0);           \
    glRotatef(spin_x, 0.0, 1.0, 0.0)*/

#define top                                     \
    projection(width, height, 0);               \
    glRotatef(90.0, 1.0, 0.0, 0.0);             \
    glRotatef(spin_y, 1.0, 0.0, 0.0);           \
    glRotatef(spin_x, 0.0, 1.0, 0.0)

/*#define bottom                                  \
    projection(width, height, 0);               \
    glRotatef(-90.0, 1.0, 0.0, 0.0);            \
    glRotatef(spin_y, 1.0, 0.0, 0.0);           \
    glRotatef(spin_x, 0.0, 1.0, 0.0)*/

#define perspective                             \
    projection(width, height, 1);               \
    glRotatef(30.0, 0.0, 1.0, 0.0);             \
    glRotatef(20.0, 1.0, 0.0, 0.0);             \
    glRotatef(spin_y, 1.0, 0.0, 0.0);           \
    glRotatef(spin_x, 0.0, 1.0, 0.0)

void
display(void)
{
	if(form==2)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,0.0);
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_LIGHTING);
    glColor3f(.8,.498039,.196078);
    glBegin(GL_LINES);
    glVertex2i(width/2,0);
    glVertex2i(width/2,height);
    glVertex2i(0,height/2);
    glVertex2i(width,height/2);
    glEnd();

    glRasterPos2i(5, 5);
    text("Front");
    glRasterPos2i(width/2+5, 5);
    text("Right");
    glRasterPos2i(5, height/2+5);
    text("Top");
    glRasterPos2i(width/2+5, height/2+5);
    text("Perspective");

    glEnable(GL_LIGHTING);

    width = (width+1)/2;
    height = (height+1)/2;

    glEnable(GL_SCISSOR_TEST);

    bottom_left;
    front;
    glCallList(sphere_list);

    bottom_right;
    right;
    glCallList(sphere_list);

    top_left;
    top;
    glCallList(sphere_list);

    top_right;
    perspective;
    glCallList(sphere_list);

    glDisable(GL_SCISSOR_TEST);

    glutSwapBuffers();
}
else if(form==0)
{ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	first();
}
else if(form==1)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	second();
}
}

void
keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
     case 'n':if((flag=++next)>6)
				flag=next=1;
				lists();
				break;
	 case 'b':if((flag=--next)<1)
				flag=next=6;
				lists();
				break;
	case 's':  solid=!solid;
				lists();
				break;
	case 'c':if(form==0)
				form=1;
				break;
	case '1':if(form==1)
				form=2;
				break;
	case '2':if(form==1)
				exit(0);
    }

    glutPostRedisplay();
}

int old_x, old_y;

void
mouse(int button, int state, int x, int y)
{
    old_x = x;
    old_y = y;

    glutPostRedisplay();
}

void
motion(int x, int y)
{
    spin_x = x - old_x;
    spin_y = y - old_y;

    glutPostRedisplay();
}
void menu(int id)
{
	if(id==1) {flag=1;lists();}
	else if(id==2)
	{flag=2;lists();}
	else if(id==3)
	{flag=3;lists();}
	else if(id==4)
	{flag=4;lists();}
	else if(id==5)
	{flag=5;lists();}
	else if(id==6)
	{flag=6;lists();}
	else if(id==7)
	{solid=!(1 & solid);lists();}
glutPostRedisplay();

}
int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1000, 1000);
    glutInit(&argc, argv);
    glutCreateWindow("Multiple Viewports");
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
glutCreateMenu(menu);
glutAddMenuEntry("Toggle Solid",7);
glutAddMenuEntry("sphere",1);
glutAddMenuEntry("cube",2);
glutAddMenuEntry("cone",3);
glutAddMenuEntry("torus",4);
glutAddMenuEntry("teapot",5);
glutAddMenuEntry("Icosahedron",6);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 3.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0, 0.0, -2.0);
glEnable(GL_NORMALIZE);
glEnable(GL_DEPTH_TEST);
init();
lists();
glutMainLoop();
return 0;
}






