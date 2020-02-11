//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <memory.h>
//#include <GL/glut.h>
//
//#define M_PI 3.1415926
//
///*
//** Global settings controlled by keyboard input.
//*/
//bool smoothEnabled = true;
//bool drawLines = false;
//bool redrawContinue = true;	// 是否重绘
//
//
//// Global settings
//float mynear = 1;  	/* near clipping plane in eye coords */
//float myfar = 9.0;    	/* far clipping plane in eye coords */
//float viewxform_z = -5.0;
//
//int winWidth, winHeight;
//
//float angle = 0.0, axis[3];	// 用于对x、y、z轴的变换
//
//int operatorType = 0;		// 操作类型，旋转 = 0、平移 = 1、缩放 = 2
//bool rotateMove = false;   //旋转
//bool translateMove = false; //平移
//bool scaleMove = false;     //缩放
//
//
//// 物体变换矩阵
//GLfloat objectXform[4][4] = {
//	{1.0, 0.0, 0.0, 0.0},
//	{0.0, 1.0, 0.0, 0.0},
//	{0.0, 0.0, 1.0, 0.0},
//	{0.0, 0.0, 0.0, 1.0}
//};
//
//void setMenuEntries();
//
//
///*
//** Set initial state.
//*/
//void initSettings(void)
//{
//	glLineWidth(3.0);
//	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */ // 设置深度遮挡，禁止透视
//	setMenuEntries();		// 添加菜单
//
//	glMatrixMode(GL_PROJECTION);//切换到投影矩阵
//	glLoadIdentity();//设置投影矩阵为单位矩阵
//	glOrtho(-5.0, 5.0, -5.0, 5.0, mynear, myfar);//采用正平行投影
//	viewxform_z = -5.0;
//	glMatrixMode(GL_MODELVIEW);//切换到模型-观察矩阵
//	glLoadIdentity();//设置为单位矩阵
//}
//
///*----------------------------------------------------------------------*/
///*
//** Set state according to user interaction.
//*/
//
//// 设置状态选项
//void userSettings(void)
//{
//	memset(axis, 0, sizeof(axis));	// axis清零
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//
//	if (smoothEnabled) {
//		glShadeModel(GL_SMOOTH);
//	}
//	else {
//		glShadeModel(GL_FLAT);
//	}
//
//
//}
//
///*----------------------------------------------------------------------*/
///*
//** Draw the cube.
//*/
//GLfloat vertices[][3] = {		// 8个顶点的坐标
//	{-1.0,-1,-1.0}, {-1.0,-1,1.0}, {1.0,-1,1.0}, {1.0,-1,-1.0},
//	{-1.0,1,-1.0}, {-1.0,1,1.0}, {1.0,1,1.0}, {1.0,1,-1.0},
//	{0,pow(2,0.5) + 1,0},{0,-pow(2,0.5) - 1,0},
//{pow(2,0.5) + 1,0,0},
//{-pow(2,0.5) - 1,0,0},
//{0,0,pow(2,0.5) + 1},{0,0,-pow(2,0.5) - 1}
//};
//
//GLfloat colors[][3] = {			// 8个顶点的颜色 -> 根据 userSettings 函数中的 GL_SMOOTH / GL_FLAT 填充面的颜色
//	{0.0,0.0,0.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
//	{0.0,0.0,1.0}, {1.0,0.0,1.0} ,{1.0,1.0,1.0}, {0.0,1.0,1.0},
//	{0.0,0.0,0.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
//	{0.0,0.0,1.0}, {1.0,0.0,1.0} ,{1.0,1.0,1.0}, {0.0,1.0,1.0},
//	{0.0,0.0,0.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
//	{0.0,0.0,1.0}, {1.0,0.0,1.0} ,{1.0,1.0,1.0}, {0.0,1.0,1.0}
//};
//
//// 根据4个点画1个面
//void polygon(int a, int b, int c)
//{
//
//	/* draw a polygon via list of vertices */
//
//	if (drawLines) {
//		glColor3f(1.0, 1.0, 1.0);
//		glBegin(GL_LINE_LOOP);
//		glVertex3fv(vertices[a]);
//		glVertex3fv(vertices[b]);
//		glVertex3fv(vertices[c]);
//		glEnd();
//	}
//	else {
//		glBegin(GL_TRIANGLES);
//		glColor3fv(colors[a]);
//		glVertex3fv(vertices[a]);
//		glColor3fv(colors[b]);
//		glVertex3fv(vertices[b]);
//		glColor3fv(colors[c]);
//		glVertex3fv(vertices[c]);
//		glEnd();
//	}
//}
//
//// 绘制6个面
//void colorcube(void)
//{
//
//	/* map vertices to faces */
//
//	polygon(4, 5, 8);
//	polygon(5, 6, 8);
//	polygon(6, 7, 8);
//	polygon(7, 4, 8);
//	polygon(0, 1, 9);
//	polygon(1, 2, 9);
//	polygon(2, 3, 9);
//	polygon(3, 0, 9);
//	polygon(2, 3, 10);
//	polygon(3, 7, 10);
//	polygon(7, 6, 10);
//	polygon(6, 2, 10);
//	polygon(0, 1, 11);
//	polygon(1, 5, 11);
//	polygon(5, 4, 11);
//	polygon(4, 0, 11);
//	polygon(1, 2, 12);
//	polygon(2, 6, 12);
//	polygon(6, 5, 12);
//	polygon(5, 1, 12);
//	polygon(0, 3, 13);
//	polygon(3, 7, 13);
//	polygon(7, 4, 13);
//	polygon(4, 0, 13);
//}
///*----------------------------------------------------------------------*/
///*
//** Control the cube.
//*/
//
//float lastPos[3] = { 0.0F, 0.0F, 0.0F };
//int curx, cury;
//int lastx, lasty;
//int startX, startY;
//
//// 将坐标投影到中心在原点的半球体
//void trackball_ptov(int x, int y, int width, int height, float v[3])
//{
//	float d, a;
//
//	/* project x,y onto a hemi-sphere centered within width, height */
//	v[0] = (2.0F*x - width) / width;
//	v[1] = (height - 2.0F*y) / height;
//	d = (float)sqrt(v[0] * v[0] + v[1] * v[1]);
//	v[2] = (float)cos((M_PI / 2.0F) * ((d < 1.0F) ? d : 1.0F));
//	a = 1.0F / (float)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);	// 归一化
//	v[0] *= a;
//	v[1] *= a;
//	v[2] *= a;
//}
//
//
//// 鼠标移动函数
//void mouseMotion(int x, int y)
//{
//
//	if (!redrawContinue) return;
//	float curPos[3], dx, dy, dz; trackball_ptov(x, y, winWidth, winHeight, curPos);
//	if (rotateMove) {
//
//
//		//计算三个方向的位移
//		dx = curPos[0] - lastPos[0];
//		dy = curPos[1] - lastPos[1];
//		dz = curPos[2] - lastPos[2];
//
//		if (dx || dy || dz) {
//			angle = 90.0F * sqrt(dx * dx + dy * dy + dz * dz);// 使旋转幅度与dx、dy、dz相关
//
//			axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];//YoZ平面旋转的有向面积（由于更新频率，每次都是一个菱形），因为半径为1，其值为sin(alpha)
//			axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];	// 根据右手定则
//			axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];
//			// 在3个轴上的旋转比例 alpha : beta : gama = sin(alpha) : sin(beta) : sin(gama)
//			// 只需控制旋转比例即可，angle控制旋转快慢
//
//			lastPos[0] = curPos[0];
//			lastPos[1] = curPos[1];
//			lastPos[2] = curPos[2];
//		}
//	}
//	else if (translateMove) {
//		//计算平移量
//
//		curx = x;
//		cury = y;
//		dx = x - lastx;
//		dy = y - lasty;
//
//		if (dx || dy) {
//			//axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];//YoZ平面旋转的有向面积（由于更新频率，每次都是一个菱形），因为半径为1，其值为sin(alpha)
//			//axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];	// 根据右手定则
//			//axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];
//			axis[0] = 0.01*dx;
//			axis[1] = -0.01*dy;
//			axis[2] = 0;
//			lastx = curx;
//			lasty = cury;
//		}
//	}
//	else if (scaleMove) {
//		//计算缩放
//		float k_scale = 2;		// 缩放系数，控制快慢
//		curx = x;
//		cury = y;
//		dx = 2.0F*(curx - lastx) / winWidth * k_scale;
//		dy = 2.0F*(lasty - cury) / winHeight * k_scale;
//
//		if (dx || dy) {
//			axis[0] = 0.01*dx;//YoZ平面旋转的有向面积（由于更新频率，每次都是一个菱形），因为半径为1，其值为sin(alpha)
//			axis[1] = 0.01*dy;	// 根据右手定则
//			axis[2] = 0;
//		}
//	}
//	else return;
//
//	glutPostRedisplay();
//}
//
//void startMotion(long time, int button, int x, int y, int type)
//{
//	rotateMove = false;
//	translateMove = false;
//	scaleMove = false;
//
//	startX = x; startY = y;
//	curx = x; cury = y;
//	lastx = startX, lasty = startY;
//
//	switch (type)	// 根据operatorType切换操作方式
//	{
//	case 0:
//		trackball_ptov(x, y, winWidth, winHeight, lastPos);
//		rotateMove = true;
//		break;
//	case 1:
//		trackball_ptov(x, y, winWidth, winHeight, lastPos);
//		translateMove = true;
//		break;
//	case 2:
//		trackball_ptov(x, y, winWidth, winHeight, lastPos);
//		scaleMove = true;
//		break;
//	default:
//		return;
//		break;
//	}
//
//}
//
//void stopMotion(long time, int button, int x, int y, int type)
//{
//	angle = 0.0F;
//	rotateMove = false;
//	translateMove = false;
//	scaleMove = false;
//	// 打印变换矩阵
//	printf("objectXform:\n");
//	for (int i = 0; i < 4; i++)
//	{
//		printf("\t");
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%.1f\t", objectXform[i][j]);
//		}
//		printf("\n");
//	}
//}
//
///*----------------------------------------------------------------------*/
//// 显示函数
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	/* view transform */
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(0.0, 0.0, viewxform_z);
//
//	if (redrawContinue) {
//		glPushMatrix();												// 将当前状态压栈
//		glLoadIdentity();											// 矩阵重置
//		if (rotateMove) {
//			glRotatef(angle, axis[0], axis[1], axis[2]);//调用旋转API 								
//			;// 旋转
//		}
//		else if (translateMove) {
//			glTranslatef(axis[0], axis[1], axis[2])//调用平移API glTranslate ()
//				;				// 平移
//		}
//		else if (scaleMove) {
//			glScalef(1 + axis[0], 1 + axis[1], 1 + axis[2])//调用缩放API glScalef()
//				;		// 缩放
//		}
//		glMultMatrixf((GLfloat *)objectXform);//为什么				// 物体初始状态（可不为单位矩阵）
//		glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)objectXform);	// 将上述矩阵乘积存储到物体变换矩阵 objectXform
//		glPopMatrix();												// 将之前保存的状态出栈
//	}
//	glPushMatrix();
//	glMultMatrixf((GLfloat *)objectXform);					// 将用户坐标系根据objectXform变换
//	colorcube();											
//	glPopMatrix();
//
//	glFlush();
//	glutSwapBuffers();										//
//
//}
//
///*----------------------------------------------------------------------*/
//// 按键事件
//
//void mouseButton(int button, int state, int x, int y)
//{
//	switch (button) {		// 可以对不同鼠标按键采取不同策略，此处不做区分（除右键已绑定菜单）
//	case GLUT_LEFT_BUTTON:
//
//		break;
//	case GLUT_MIDDLE_BUTTON:
//
//		break;
//
//	case GLUT_RIGHT_BUTTON:
//
//		break;
//	}
//	switch (state) {
//	case GLUT_DOWN:
//		startMotion(0, 1, x, y, operatorType);
//		break;
//	case GLUT_UP:
//		stopMotion(0, 1, x, y, operatorType);
//		break;
//	}
//}
//
//void myReshape(int w, int h)
//{
//	glViewport(0, 0, w, h);	// 设置视口大小和窗口一致
//	winWidth = w;
//	winHeight = h;
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	if (w <= h)
//		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w, 5.0*(GLfloat)h / (GLfloat)w, mynear, myfar);
//	else
//		glOrtho(-5.0*(GLfloat)w / (GLfloat)h, 5.0*(GLfloat)w / (GLfloat)h, -5.0, 5.0, mynear, myfar);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//
//
//void userEventAction(int key) {
//
//	rotateMove = false;
//	translateMove = false;
//	scaleMove = false;
//	switch (key) {
//	case '0'://reset
//	{
//		angle = 0;//设置angle为0
//		axis[0] = 0; axis[1] = 0; axis[2] = 0;
//		memset(objectXform, 0, sizeof(objectXform));
//		for (int i = 0; i < 4; i++)
//		{
//			objectXform[i][i] = 1.0;
//		}
//		// axis清零
//	// 变换矩阵objectXform重置
//		break;
//	}
//	case 'r':
//	{		// 旋转
//	//	设置操作类型为旋转
//		operatorType = 0;
//
//		break;
//	}
//	case 't':		// 平移
//	//	设置操作类型为平移
//
//		operatorType = 1;
//		break;
//	case 's':		// 缩放
//	//	设置操作类型为缩放
//		operatorType = 2;
//		break;
//	case '1':				// wire frame/polygon   // 线框图/多边形
//		drawLines = !drawLines;
//		break;
//	case '2':
//		smoothEnabled = !smoothEnabled;			// GL_SMOOTH / GL_FLAT
//		break;
//	case 27:		// ESC键（ASCII: 27）退出
//		exit(0);
//		break;
//	default:
//		break;
//	}
//	userSettings();	// 检查用户设置是否改变
//
//	glutPostRedisplay();	// 重绘
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	userEventAction(key);			// 调用通用动作解释函数
//}
//
//// 箭头按键
//void arrow(int key, int x, int y)
//{
//	startMotion(0, 1, x, y, operatorType); // 设置操作的布尔值
//	angle = 10.0F;
//	switch (key)
//	{
//	case GLUT_KEY_LEFT:
//		if (rotateMove) {
//			axis[0] = 0;
//			axis[1] = 1;
//			axis[2] = 0;// 设置绕Y方向旋转的axis值
//
//		}
//		else if (translateMove) {
//			axis[0] = -0.2;
//			axis[1] = 0;
//			axis[2] = 0;// 设置绕Y方向旋转的axis值//设置X方向平移的axis值
//
//		}
//		else if (scaleMove) {
//			axis[0] = -0.2;
//			axis[1] = 0;
//			axis[2] = 0;//设置x方向缩放的axis的值
//			;
//		}
//		break;
//	case GLUT_KEY_UP:
//		if (rotateMove) {	// 根据 x 轴旋转
//			//  设置绕Y方向旋转的axis值
//			axis[0] = -1;
//			axis[1] = 0;
//			axis[2] = 0;;
//
//		}
//		else if (translateMove) {
//			//设置Y方向平移的axis值
//			axis[0] = 0;
//			axis[1] = 0.2;
//			axis[2] = 0;
//		}
//		else if (scaleMove) {
//			//设置Y方向缩放的axis值
//			axis[0] = 0;
//			axis[1] = 0.2;
//			axis[2] = 0;
//		}
//		break;
//	case GLUT_KEY_RIGHT:
//		if (rotateMove) {
//			axis[0] = 0;
//			axis[1] = -1;
//			axis[2] = 0;// 设置绕Y方向旋转的axis值
//			;
//		}
//		else if (translateMove) {
//			//设置X方向平移的axis值
//			axis[0] = 0.2;
//			axis[1] = 0;
//			axis[2] = 0;
//		}
//		else if (scaleMove) {
//			//设置x方向缩放的axis的值
//			axis[0] = 0.2;
//			axis[1] = 0;
//			axis[2] = 0;
//		}
//		break;
//	case GLUT_KEY_DOWN:
//		if (rotateMove) {
//			axis[0] = 1;
//			axis[1] = 0;
//			axis[2] = 0;// 设置绕X方向旋转的axis值
//			;
//		}
//		else if (translateMove) {
//			//设置Y方向平移的axis值；
//			axis[0] = 0;
//			axis[1] = -0.2;
//			axis[2] = 0;
//		}
//		else if (scaleMove) {
//			//设置Y方向缩放的axis值
//			axis[0] = 0;
//			axis[1] = -0.2;
//			axis[2] = 0;
//		}
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
/////*
//void arrowKeyup(int key, int x, int y)
//{
//	angle = 0.0F;
//	rotateMove = false;
//	translateMove = false;
//	scaleMove = false;
//}
//
/////*----------------------------------------------------------------------*/
//// 菜单栏
//
//typedef struct menuEntryStruct {	// 键-值对 数据结构
//	const char *label;
//	char key;
//} menuEntryStruct;
//
//static menuEntryStruct mainMenu[] = {
//	"Reset",		'0',
//	"Rotate", 		'r',
//	"Translate",	't',
//	"Scale",		's',
//	"lines/polygons", 		'1',
//	"flat/smooth", 		'2',
//	"quit", 			27,	//ESC键（ASCII: 27）
//};
//int mainMenuEntries = sizeof(mainMenu) / sizeof(menuEntryStruct);
//
//void selectMain(int choice)			// 序号->key 映射
//{
//	userEventAction(mainMenu[choice].key);		// 调用通用动作解释函数
//}
//
//void setMenuEntries()
//{
//	glutCreateMenu(selectMain);					// 使用selectMain作为菜单调用函数
//	for (int i = 0; i < mainMenuEntries; i++) {
//		glutAddMenuEntry(mainMenu[i].label, i);	// label显示在菜单界面，i传入selectMain
//	}
//
//	glutAttachMenu(GLUT_RIGHT_BUTTON);			// 菜单绑定右键
//}
//
///*----------------------------------------------------------------------*/
//// 主函数
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowPosition(0, 0);
//	glutInitWindowSize(1000, 1000);
//	glutCreateWindow("MY_Geometry Transformation");
//	glutReshapeFunc(myReshape);
//	glutDisplayFunc(display);
//	glutMouseFunc(mouseButton);
//	glutMotionFunc(mouseMotion);
//	glutKeyboardFunc(keyboard);
//	glutSpecialFunc(arrow);
//	//glutSpecialUpFunc(arrowKeyup);
//	initSettings();
//	userSettings();
//	glutMainLoop();
//	return 0;
//}