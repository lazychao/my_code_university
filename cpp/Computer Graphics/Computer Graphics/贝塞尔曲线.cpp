//#include "GL\glut.h"
//#include <math.h>
//#include <Windows.h>
//#include<stdio.h>
//class Point
//{
//public:
//	int x, y;
//	void setxy(int _x, int _y) {
//		x = _x;
//		y = _y;
//	}
//};
//int rank;
//int nums;
//int choosed_point;
//int choosed_num;
//static int POINTSNUM = 0;
//
//
//static Point points[100][5];
//
////初始化函数
//void init(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 0);
//	glColor3f(0.0, 0.0, 0.0);
//	glPointSize(2.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 600.0, 0.0, 480.0);
//}
//void setPoint(Point p) {
//	glBegin(GL_POINTS);
//	glVertex2f(p.x, p.y);
//	glEnd();
//	glFlush();
//}
//
// //绘制直线
//void setline(Point p1, Point p2) {
//	glBegin(GL_LINES);
//	glVertex2f(p1.x, p1.y);
//	glVertex2f(p2.x, p2.y);
//	glEnd();
//	glFlush();
//}
//
// //绘制贝塞尔曲线
//Point setBezier3(Point p1, Point p2, Point p3, Point p4, double t) {
//	Point p;
//	double a1 = pow((1 - t), 3);
//	double a2 = pow((1 - t), 2) * 3 * t;
//	double a3 = 3 * t*t*(1 - t);
//	double a4 = t * t*t;
//	p.x = a1 * p1.x + a2 * p2.x + a3 * p3.x + a4 * p4.x;
//	p.y = a1 * p1.y + a2 * p2.y + a3 * p3.y + a4 * p4.y;
//	return p;
//}
//Point setBezier2(Point p1, Point p2, Point p3, double t) {
//	Point p;
//	double a1 = pow((1 - t), 2);
//	double a2 = pow((1 - t), 1) * 2 * t;
//	double a3 = t*t;
//	p.x = a1 * p1.x + a2 * p2.x + a3 * p3.x ;
//	p.y = a1 * p1.y + a2 * p2.y + a3 * p3.y ;
//	return p;
//}
//Point setBezier4(Point p1, Point p2, Point p3, Point p4, Point p5,double t) {
//	Point p;
//	double a1 = pow((1 - t), 4);
//	double a2 = pow((1 - t), 3) * 4 * t;
//	double a3 = pow((1 - t), 2) * 6 * pow( t, 2);
//	double a4 = pow( t, 3) * 4 *(1- t);
//	double a5= t * t*t*t;
//
//	p.x = a1 * p1.x + a2 * p2.x + a3 * p3.x + a4 * p4.x+ a5*p5.x;
//	p.y = a1 * p1.y + a2 * p2.y + a3 * p3.y + a4 * p4.y + a5 * p5.y;
//	return p;
//}
////display函数
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
//
//
//
// /*鼠标事件*/
//void mymouseFunction(int button, int state, int x, int y) 
//{
//	int flag = 0;
//	if (state == GLUT_DOWN) 
//	{
//		for (int i = 0; i < rank+1; i++)
//		{
//			for (int j = 0; j < nums; j++)
//			{
//				if (abs(x - points[j][i].x) <= 40 && abs((480 - y) - points[j][i].y) <= 40 && POINTSNUM == 0)
//				{
//					points[j][i].x = x;
//					points[j][i].y = 480-y;
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (!flag) points[nums][POINTSNUM].setxy(x, 480 - y); // 这里求鼠标点的坐标的时候
//		/* 设置点的颜色，绘制点*/
//		glClear(GL_COLOR_BUFFER_BIT);
//		glColor3f(1.0, 0.0, 0.0);
//		for (int i = 0; i < nums; i++)
//		{
//			for (int j = 0; j < rank+1; j++)
//				setPoint(points[i][j]);
//
//		}
//		for (int k = 0; k <= POINTSNUM; k++)
//		{
//			if (flag == 1 && k == POINTSNUM);
//			else
//			setPoint(points[nums][k]);
//		}
//		for (int i = 0; i < nums; i++)
//		{
//			for (int j = 0; j < rank; j++)
//			{
//				setline(points[i][j], points[i][j + 1]);
//			}
//		}
//		for (int k = 0; k < POINTSNUM; k++)
//		{
//			setline(points[nums][k], points[nums][k + 1]);
//		}
//		glColor3f(0.0, 0.0, 1.0);
//		for (int i = 0; i < nums; i++)
//		{
//			Point p_current = points[i][0]; //设为起点
//			Point P;
//			for (double t = 0.0; t <= 1.0; t += 0.02)
//			{
//				if (rank == 3)
//				{
//					P = setBezier3(points[i][0], points[i][1], points[i][2], points[i][3], t);
//				}
//				else if (rank == 2)
//				{
//					P = setBezier2(points[i][0], points[i][1], points[i][2], t);
//				}
//				else if (rank == 4)
//				{
//					P = setBezier4(points[i][0], points[i][1], points[i][2], points[i][3], points[i][4],t);
//				}
//				setline(p_current, P);
//				p_current = P;
//			}
//		}
//		
//		if(!flag)
//		{
//			if (POINTSNUM == rank) {
//				/*绘制贝塞尔曲线  */ 
//				glColor3f(0.0, 0.0, 1.0); // 设定贝塞尔曲线的颜色
//
//				Point p_current = points[nums][0]; //设为起点
//				Point P;
//				for (double t = 0.0; t <= 1.0; t += 0.05)
//				{
//					if (rank == 3)
//					{
//						P = setBezier3(points[nums][0], points[nums][1], points[nums][2], points[nums][3], t);
//					}
//					else if (rank == 2)
//					{
//						P = setBezier2(points[nums][0], points[nums][1], points[nums][2], t);
//					}
//					else if (rank == 4)
//					{
//						P = setBezier4(points[nums][0], points[nums][1], points[nums][2], points[nums][3], points[nums][4], t);
//					}
//					setline(p_current, P);
//					p_current = P;
//				}
//				nums++;
//				POINTSNUM = 0;
//			}
//			else {
//				POINTSNUM++;
//			}
//	    }
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv); 
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);  
//	glutInitWindowSize(600, 480);   
//	glutInitWindowPosition(100, 100); 
//	glutCreateWindow("贝塞尔");
//
//	init(); 
//	printf("请输入贝塞尔曲线阶数：");
//	scanf("%d", &rank);
//	while(rank > 4)
//	{
//		printf("只能显示2~4阶,请重新输入");
//		scanf("%d", &rank);
//	}
//	glutMouseFunc(mymouseFunction); // 添加鼠标事件
//	glutDisplayFunc(display); // 执行显示   
//	glutMainLoop(); //处理循环
//	return 0;
//}
