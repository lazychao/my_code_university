//#include<Windows.h>
//#include<GL\glut.h>
//#include <iostream>
//using namespace std;
////void init(int argc, char**argv)
////{
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
////	glutInitWindowPosition(50, 100);
////	glutInitWindowSize(400, 400);
////	glutCreateWindow("My_Circle");
////	glClearColor(1.0, 1.0, 1.0, 0);
////	glMatrixMode(GL_PROJECTION);
////}
//int r;
//void my_circle(int x0, int y0, int r)
//{
//	int x = 0, y = r;
//	int d = 3 - 2 * r;//����Ӧ����1.25-r   ��Ϊ�˱��⸡�������㣬����������
//	//�Ȼ�����һ����
//	glVertex2i(x0, y0 + r);
//	while (x < y)
//	{
//		if (d > 0)
//		{
//			d = d + 4 * (x - y) + 10;
//			y--;
//		}
//		else
//		{
//			d = d + 4 * x + 6;
//		}
//		x++;
//		glVertex2i(x0 + x, y0 + y);
//		glVertex2i(x0 + y, y0 + x);
//		glVertex2i(x0 - x, y0 - y);
//		glVertex2i(x0 - y, y0 - x);
//		glVertex2i(x0 - x, y0 + y);
//		glVertex2i(x0 - y, y0 + x);
//		glVertex2i(x0 + x, y0 - y);
//		glVertex2i(x0 + y, y0 - x);
//	}
//
//}
//void my_func()
//{
//	glClear(GL_COLOR_BUFFER_BIT); 
//	glPointSize(1);//��Ĵ�С
//	glColor3f(1, 0,0);
//	glBegin(GL_POINTS);
//	glLoadIdentity();
//	glPushMatrix();
//	glTranslatef(-100, 0, 0);
//	my_circle(400, 400, r);
//	glPopMatrix();
//	glEnd();
//	glFlush();
//}
//void myinit(int argc,char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(50, 100);
//	glutInitWindowSize(800, 800);
//	glutCreateWindow("My_Circle");
//	glClearColor(1, 1, 1, 0);
//	/*glMatrixMode(GL_PROJECTION);*/
//	glMatrixMode(GL_MODELVIEW);
//	gluOrtho2D(0, 800, 0, 800);
//}
//int main(int argc,char **argv)
//{
//	myinit(argc, argv);
//	cout << "������Բ�İ뾶(0<r<400)��" << endl;
//	cin >> r;
//	glutDisplayFunc(my_func);
//	glutMainLoop();
//}