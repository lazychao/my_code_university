//#include "windows.h"
//#include <gl/glut.h>
//
//static int spin = 0;
//
//void init()
//{
//	glShadeModel(GL_SMOOTH);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };
//
//	//第一点也是最重要的一点：OpenGL中的模型视图变换矩阵全是(顶点对象)右乘当前变换矩阵
//
//	//（右乘：顶点对象置于当前矩阵的右面。转载时gqb666增加。）
//
//	//或者这样理解：每一次变换都是变换矩阵右乘栈顶矩阵，顶点对象右乘终于的栈顶矩阵
//
//	//（右乘：变换矩阵置于栈顶矩阵的右面。转载时gqb666增加。）
//	glPushMatrix();  //将当前变换矩阵(单位阵)压入堆栈
//	glTranslatef(0.0, 0.0, -5.0);     // transformation 1
//	glPushMatrix();  //将平移变换后的的矩阵作为当前变换矩阵压入堆栈,
//	glRotated((GLdouble)spin, 1.0, 0.0, 0.0);
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//	glTranslated(0.0, 0.0, 1.5);
//	glDisable(GL_LIGHTING);
//	glColor3f(0.0, 1.0, 0.0);
//	glutWireCube(0.1);//绿色的下框，代表光源位置
//	glEnable(GL_LIGHTING);
//	glPopMatrix();  //消除绘制绿色WireCube时对当前变换矩阵的影响
//
//	glutSolidSphere(0.5, 40, 40);//被光照的物体
//	glPopMatrix(); // Pop the old matrix without the transformations.   //返回到单位矩阵
//	glFlush();
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	switch (button)
//	{
//	case GLUT_LEFT_BUTTON:
//		if (state == GLUT_DOWN)
//		{
//			spin = (spin + 30) % 360;
//			glutPostRedisplay();
//		}
//		break;
//	default:
//		break;
//	}
//}
//
//int main(int argc, char ** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//	return 0;
//}