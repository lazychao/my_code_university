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
//	//��һ��Ҳ������Ҫ��һ�㣺OpenGL�е�ģ����ͼ�任����ȫ��(�������)�ҳ˵�ǰ�任����
//
//	//���ҳˣ�����������ڵ�ǰ��������档ת��ʱgqb666���ӡ���
//
//	//����������⣺ÿһ�α任���Ǳ任�����ҳ�ջ�����󣬶�������ҳ����ڵ�ջ������
//
//	//���ҳˣ��任��������ջ����������档ת��ʱgqb666���ӡ���
//	glPushMatrix();  //����ǰ�任����(��λ��)ѹ���ջ
//	glTranslatef(0.0, 0.0, -5.0);     // transformation 1
//	glPushMatrix();  //��ƽ�Ʊ任��ĵľ�����Ϊ��ǰ�任����ѹ���ջ,
//	glRotated((GLdouble)spin, 1.0, 0.0, 0.0);
//	glLightfv(GL_LIGHT0, GL_POSITION, position);
//	glTranslated(0.0, 0.0, 1.5);
//	glDisable(GL_LIGHTING);
//	glColor3f(0.0, 1.0, 0.0);
//	glutWireCube(0.1);//��ɫ���¿򣬴����Դλ��
//	glEnable(GL_LIGHTING);
//	glPopMatrix();  //����������ɫWireCubeʱ�Ե�ǰ�任�����Ӱ��
//
//	glutSolidSphere(0.5, 40, 40);//�����յ�����
//	glPopMatrix(); // Pop the old matrix without the transformations.   //���ص���λ����
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