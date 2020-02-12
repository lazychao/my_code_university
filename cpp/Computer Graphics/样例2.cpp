#include<GL/glut.h>
#include<cstdio>

#include<GL\glut.h>
#include <iostream>
using namespace std;
#define MAX 20

int n;
int k;
typedef struct
{
	GLfloat x;
	GLfloat y;
}point;
point ctrlpoints[MAX][MAX] = { 0.0 };

void ctrlpointsinput(void)
{
	int i;
	printf("请输入该贝塞尔曲线的的次数：\nn= ");
	scanf("%d", &n);
	printf("\n请输入%d个控制点：\n", n + 1);
	for (i = 0; i <= n; i++)
	{
		printf("\n第%d个控制点： ", i + 1);
		scanf("%f,%f", &ctrlpoints[0][i].x, &ctrlpoints[0][i].y);
	}
	printf("Input finished!\n");
}

void myInit(void)
{
	ctrlpointsinput();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

point bezierpoint(float t)
{
	k = 1;
	do
	{
		for (int i = 0; i <= n - k; i++)
		{
			ctrlpoints[k][i].x = (1 - t)*ctrlpoints[k - 1][i].x + t * ctrlpoints[k - 1][i + 1].x;
			ctrlpoints[k][i].y = (1 - t)*ctrlpoints[k - 1][i].y + t * ctrlpoints[k - 1][i + 1].y;
		}
		k++;
	} while (k <= n);
	return ctrlpoints[n][0];
}

void drawline(void)
{
	float T;
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	for (T = 0; T <= 1; T = T + 0.0001)
	{
		glVertex2f(bezierpoint(T).x, bezierpoint(T).y);
	}
	glEnd();
}

void redmark(int e)
{
	int j;
	glPointSize(4.0);
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 0.0);
	for (j = 0; j < e; j++)
	{
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(ctrlpoints[0][j].x, ctrlpoints[0][j].y);
	}
	for (j = e + 1; j <= n; j++)
	{
		glVertex2f(ctrlpoints[0][j].x, ctrlpoints[0][j].y);
	}
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(ctrlpoints[0][e].x, ctrlpoints[0][e].y);
	glEnd();
	glFlush();
}

void myDisplay(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	drawline();
	glPointSize(4.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i <= n; i++)
		glVertex2f(ctrlpoints[0][i].x, ctrlpoints[0][i].y);
	glEnd();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)w / (GLfloat)h, 5.0*(GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int t = 0;
void myKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case'j':
		redmark((t + 1) % (n + 1));
		t = t + 1;
		break;
	case'k':
		redmark((t - 1) % (n + 1));
		t = t - 1;
		break;
	case'e':
		exit(0);
		break;
	case'w':
		ctrlpoints[0][t % (n + 1)].y += 0.1;
		drawline();
		glutPostRedisplay();
		break;
	case's':
		ctrlpoints[0][t % (n + 1)].y -= 0.1;
		drawline();
		glutPostRedisplay();
		break;
	case'a':
		ctrlpoints[0][t % (n + 1)].x -= 0.1;
		drawline();
		glutPostRedisplay();
		break;
	case'd':
		ctrlpoints[0][t % (n + 1)].x += 0.1;
		drawline();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("贝塞尔曲线的绘制");
	myInit();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();
	return 0;
}