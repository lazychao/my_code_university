//#include "GL\glut.h"
//#include <math.h>
//#include <Windows.h>
//
////����һ������࣬���ڴ洢���е������
//class Point
//{
//public:
//	int x, y;
//	void setxy(int _x, int _y) {
//		x = _x;
//		y = _y;
//	}
//};
//int nums;
////�������
//int choosed_point;
//int choosed_num;
//static int POINTSNUM = 0;
//
////���ڴ洢��ļ���,��Ϊ���ƵĶ���4����ı��������ߣ����������СΪ4
//static Point points[100][4];
//
////��ʼ������
//void init(void)
//{
//	glClearColor(1.0, 1.0, 1.0, 0); //�趨����Ϊ��ɫ
//	glColor3f(0.0, 0.0, 0.0); //��ͼ��ɫΪ��ɫ
//	glPointSize(2.0); //�趨��Ĵ�СΪ2*2���ص�
//	glMatrixMode(GL_PROJECTION); // �趨���ʵľ���
//	glLoadIdentity(); // ��һ���޲ε���ֵ�������书������һ��4��4�ĵ�λ�������滻��ǰ����ʵ���Ͼ��ǶԵ�ǰ������г�ʼ����Ҳ����˵��������ǰ�����˶��ٴξ���任���ڸ�����ִ�к󣬵�ǰ������ָ���һ����λ���󣬼��൱��û�н����κξ���任״̬
//	gluOrtho2D(0.0, 600.0, 0.0, 480.0); //ƽ��ͶӰ���ĸ������ֱ���x,y��Χ
//}
//
////���Ƶ�
//void setPoint(Point p) {
//	glBegin(GL_POINTS);
//	glVertex2f(p.x, p.y);
//	glEnd();
//	glFlush();
//}
//
//// ����ֱ��
//void setline(Point p1, Point p2) {
//	glBegin(GL_LINES);
//	glVertex2f(p1.x, p1.y);
//	glVertex2f(p2.x, p2.y);
//	glEnd();
//	glFlush();
//}
//
//// ���Ʊ���������
//Point setBezier(Point p1, Point p2, Point p3, Point p4, double t) {
//	Point p;
//	double a1 = pow((1 - t), 3);
//	double a2 = pow((1 - t), 2) * 3 * t;
//	double a3 = 3 * t*t*(1 - t);
//	double a4 = t * t*t;
//	p.x = a1 * p1.x + a2 * p2.x + a3 * p3.x + a4 * p4.x;
//	p.y = a1 * p1.y + a2 * p2.y + a3 * p3.y + a4 * p4.y;
//	return p;
//}
//
//
////display����
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
//
//void reset(int button, int state, int x, int y)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 0.0, 0.0);
//	points[choosed_num][choosed_point].x = x;
//	points[choosed_num][choosed_point].y = 480 - y;
//	for (int i = 0; i < 4; i++)
//	{
//		setPoint(points[choosed_num][i]);
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		setline(points[choosed_num][i], points[choosed_num][i+1]);
//	}
//	/*setPoint(points[choosed_point]);
//	setline(points[choosed_point - 1], points[choosed_point]);
//	setline(points[choosed_point + 1], points[choosed_point]);*/
//	glColor3f(0.0, 0.0, 1.0);
//	for (int i = 0; i < nums; i++)
//	{
//		Point p_current = points[i][0]; //��Ϊ���
//		for (double t = 0.0; t <= 1.0; t += 0.02)
//		{
//			Point P = setBezier(points[i][0], points[i][1], points[i][2], points[i][3], t);
//			setline(p_current, P);
//			p_current = P;
//		}
//	}
//}
//
//// ����¼�
//void mymouseFunction(int button, int state, int x, int y) {
//	if (state == GLUT_DOWN) // �����갴�£����������Ҽ���
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 0; j < nums; j++)
//			{
//				if (abs(x - points[j][i].x) <= 15 && abs((480 - y) - points[j][i].y) <= 15 && POINTSNUM == 0)
//				{
//					choosed_point = i;
//					choosed_num = j;
//					glutMouseFunc(reset);
//					return;
//
//				}
//			}
//		}
//		points[nums][POINTSNUM].setxy(x, 480 - y); // ����������������ʱ��
//		// ���õ����ɫ�����Ƶ�
//		glColor3f(1.0, 0.0, 0.0);
//		setPoint(points[nums][POINTSNUM]);
//		// �����ߵ���ɫ��������
//		glColor3f(1.0, 0.0, 0.0);
//		if (POINTSNUM > 0) setline(points[nums][POINTSNUM - 1], points[nums][POINTSNUM]);
//
//
//		//����ﵽ��4�����Ʊ��������ߣ�����֮�������������
//		if (POINTSNUM == 3) {
//			//֮ǰ��ҲҪ��
//			glColor3f(0.0, 0.0, 1.0); // �趨���������ߵ���ɫ
//			for (int i = 0; i < nums; i++)
//			{
//				Point p_current = points[i][0]; //��Ϊ���
//				for (double t = 0.0; t <= 1.0; t += 0.02)
//				{
//					Point P = setBezier(points[i][0], points[i][1], points[i][2], points[i][3], t);
//					setline(p_current, P);
//					p_current = P;
//				}
//			}
//			//���Ʊ���������   
//			
//
//			Point p_current = points[nums][0]; //��Ϊ���
//			for (double t = 0.0; t <= 1.0; t += 0.01)
//			{
//				Point P = setBezier(points[nums][0], points[nums][1], points[nums][2], points[nums][3], t);
//				setline(p_current, P);
//				p_current = P;
//			}
//			nums++;
//			POINTSNUM = 0;
//		
//		}
//		else {
//			POINTSNUM++;
//		}
//	}
//}
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv); //�̶���ʽ
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);   //����ģʽ
//	glutInitWindowSize(600, 480);    //��ʾ��Ĵ�С
//	glutInitWindowPosition(100, 100); //ȷ����ʾ�����Ͻǵ�λ��
//	glutCreateWindow("���Ĵ���ҵ");
//
//	init(); // ��ʼ��
//	glutMouseFunc(mymouseFunction); // �������¼�
//	glutDisplayFunc(display); // ִ����ʾ   
//	glutMainLoop(); //����GLUT�¼�����ѭ��
//	return 0;
//}