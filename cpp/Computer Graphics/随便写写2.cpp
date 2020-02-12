//#include<GL/glut.h>
//// 绘制立方体
//// 将立方体的八个顶点保存到一个数组里面
//
//GLfloat angle = 10.0f;
//GLfloat xDirection = 0.0f;
//GLfloat yDirection = 0.0f;
//GLfloat zDirection = 10.0f;
//
//static const float vertex_list1[][3] =
//{
//	-0.3f, -0.3f, -0.3f,
//	0.3f, -0.3f, -0.3f,
//	-0.3f, 0.3f, -0.3f,
//	0.3f, 0.3f, -0.3f,
//	-0.3f, -0.3f, 0.3f,
//	0.3f, -0.3f, 0.3f,
//	-0.3f, 0.3f, 0.3f,
//	0.3f, 0.3f, 0.3f,
//};
//static const float vertex_list2[][3] =
//{
//	-0.5f, -0.5f, -0.5f,
//	0.5f, -0.5f, -0.5f,
//	-0.5f, 0.5f, -0.5f,
//	0.5f, 0.5f, -0.5f,
//	-0.5f, -0.5f, 0.5f,
//	0.5f, -0.5f, 0.5f,
//	-0.5f, 0.5f, 0.5f,
//	0.5f, 0.5f, 0.5f,
//};
//// 将要使用的顶点的序号保存到一个数组里面 
//static const GLint index_list[][2] =
//{
//	{ 0, 1 },
//	{ 2, 3 },
//	{ 4, 5 },
//	{ 6, 7 },
//	{ 0, 2 },
//	{ 1, 3 },
//	{ 4, 6 },
//	{ 5, 7 },
//	{ 0, 4 },
//	{ 1, 5 },
//	{ 7, 3 },
//	{ 2, 6 }
//};
//// 绘制立方体
//void DrawCube(void)
//{
//	int i, j;
//	glBegin(GL_LINES);
//	for (i = 0; i < 12; ++i) // 12 条线段
//	{
//		
//		for (j = 0; j < 2; ++j) // 每条线段 2个顶点
//		{
//			glVertex3fv(vertex_list1[index_list[i][j]]);
//		}
//	}
//	for (i = 0; i < 12; ++i) // 12 条线段
//	{
//		for (j = 0; j < 2; ++j) // 每条线段 2个顶点
//		{
//			glVertex3fv(vertex_list2[index_list[i][j]]);
//		}
//	}
//	for (i = 0; i < 8; i++)
//	{
//		glVertex3f(vertex_list1[i][0], vertex_list1[i][1], vertex_list1[i][2]);
//		glVertex3f(vertex_list2[i][0], vertex_list2[i][1], vertex_list2[i][2]);
//	}
//	glEnd();
//}
//static float rotate = 0;
//static int times = 0;
//void KeyBoards(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'w':
//		glMatrixMode(GL_MODELVIEW);
//		glRotatef(angle, -1, 0, 0);
//		glutPostRedisplay();
//		break;
//	case 'a':
//		glMatrixMode(GL_MODELVIEW);
//		glRotatef(angle, 0, 0, -1);
//		glutPostRedisplay();
//		break;
//	case 's':
//		glMatrixMode(GL_MODELVIEW);
//		glRotatef(angle, 1, 0, 0);
//		glutPostRedisplay();
//		break;
//	case 'd':
//		glMatrixMode(GL_MODELVIEW);
//		glRotatef(angle, 0, 0, 1);
//		glutPostRedisplay();
//		break;
//	case '4':
//		xDirection += 0.5;
//
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluPerspective(65, 1, 1, 50);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
//		glutPostRedisplay();
//		break;
//	case '5':
//		yDirection += 0.5;
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluPerspective(65, 1, 1, 50);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
//		glutPostRedisplay();
//		break;
//
//	case '6':
//		zDirection += 0.5;
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluPerspective(65, 1, 1, 50);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
//		glutPostRedisplay();
//		break;
//
//	case '1':
//		xDirection -= 0.5;
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluPerspective(65, 1, 1, 50);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
//		glutPostRedisplay();
//		break;
//	case '2':
//		xDirection -= 0.5;
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluPerspective(65, 1, 1, 50);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
//		glutPostRedisplay();
//		break;
//	case '3':
//		xDirection -= 0.5;
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluPerspective(65, 1, 1, 50);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
//		glutPostRedisplay();
//		break;
//	case 27:
//		exit(0);
//		break;
//	}
//}
//
//void renderScene(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);//模型视图矩阵
//	glLoadIdentity();
//	glPushMatrix();
//	//glTranslatef(-0.2, 0, 0); // 平移
//	//glScalef(2, 1, 1);    // 缩放
//	times++;
//	if (times > 100)
//	{
//		times = 0;
//	}
//	if (times % 100 == 0)
//	{
//		rotate += 0.3;
//	}
//	glRotatef(rotate, 0, 1, 0);//沿着y轴旋转
//	glRotatef(rotate, 1, 0, 0);//沿着x轴旋转
//	glColor3f(0, 0, 1);
//	DrawCube();
//	glPopMatrix();
//	glutSwapBuffers();
//}
//void OnMouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		glutIdleFunc(renderScene);
//	}
//
//	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//	{
//		glutIdleFunc(NULL);
//	}
//}
//
//void main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("GLDemo");glutKeyboardFunc(&KeyBoards);
//	//InitEnvironment();   //初始化显示环境
//	glutMouseFunc(&OnMouse);
//	
//	glutDisplayFunc(renderScene);
//	/*glutIdleFunc(renderScene);*///回调函数  在窗口事件发生前不断调用
//	glutMainLoop();
//}