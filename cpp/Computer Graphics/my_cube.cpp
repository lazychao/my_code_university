//#include <gl/glut.h>  
//
//int flag = 1;
//GLfloat rquad = 0;
//GLfloat vertices[8][3] = { {-1.0, -1.0, 1.0},{-1.0, 1.0, 1.0},{1.0,1.0, 1.0},{1.0,-1.0,1.0},
//{-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0} };
//
//GLfloat colors[6][3] = { {1.0,1.0,1.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0},
//{0.0,0.0,1.0}, {1.0,0.0,1.0}, {0.0,1.0,1.0} };
//
//void InitGL(GLvoid)
//{
//	glShadeModel(GL_SMOOTH);
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LEQUAL);
//	glEnable(GL_COLOR_MATERIAL);
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
//}
//
//void Polygon(int clr, int a, int b, int c, int d)
//{
//	glColor3fv(colors[clr]);
//	if (flag == 1)
//		glBegin(GL_LINE_LOOP);
//	else
//		glBegin(GL_POLYGON);
//
//	glVertex3fv(vertices[a]);
//	glVertex3fv(vertices[b]);
//	glVertex3fv(vertices[c]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//void ColorCube(void)
//{
//	Polygon(0, 0, 3, 2, 1);
//	Polygon(1, 2, 3, 7, 6);
//	Polygon(2, 0, 4, 7, 3);
//	Polygon(3, 1, 2, 6, 5);
//	Polygon(4, 4, 5, 6, 7);
//	Polygon(5, 0, 1, 5, 4);
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	glPushMatrix();
//
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//	glTranslatef(0.0f, 0.0f, -1.0f);	//平移
//	//glRotatef(rquad, 1.0f, 0.0f, 0.0f);	//旋转一个角度
//	ColorCube();
//	glPopMatrix();
//
//	rquad -= 0.15f;	//修改立方体的旋转角度
//	glutSwapBuffers();
//}
//void reshape(int width, int height)
//{
//	if (height == 0)
//		height = 1;
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	//gluPerspective(90.0f, (GLfloat)width / (GLfloat)height, 0.0f, 100.0f);
//	gluPerspective(90.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
//	//if (width <= height)
//	//	glOrtho(-2.0, 2.0, -2.0*(GLfloat)height / (GLfloat)width, 2.0*(GLfloat)height / (GLfloat)width, 1.0, 20.0);
//	//else
//	//	glOrtho(-2.0*(GLfloat)width / (GLfloat)height, 2.0*(GLfloat)width / (GLfloat)height, -2.0, 2.0, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case '1':
//		flag = 1;
//		glutPostRedisplay();
//		break;
//	case '2':
//		flag = 2;
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
//	glutInitWindowSize(600, 600);
//	glutCreateWindow("Hello Cube");
//	InitGL();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutIdleFunc(display);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//
//	return 0;
//}
