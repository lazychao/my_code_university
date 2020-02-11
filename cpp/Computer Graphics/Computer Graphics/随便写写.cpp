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
//bool redrawContinue = true;	// �Ƿ��ػ�
//
//
//// Global settings
//float mynear = 1;  	/* near clipping plane in eye coords */
//float myfar = 9.0;    	/* far clipping plane in eye coords */
//float viewxform_z = -5.0;
//
//int winWidth, winHeight;
//
//float angle = 0.0, axis[3];	// ���ڶ�x��y��z��ı任
//
//int operatorType = 0;		// �������ͣ���ת = 0��ƽ�� = 1������ = 2
//bool rotateMove = false;   //��ת
//bool translateMove = false; //ƽ��
//bool scaleMove = false;     //����
//
//
//// ����任����
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
//	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */ // ��������ڵ�����ֹ͸��
//	setMenuEntries();		// ��Ӳ˵�
//
//	glMatrixMode(GL_PROJECTION);//�л���ͶӰ����
//	glLoadIdentity();//����ͶӰ����Ϊ��λ����
//	glOrtho(-5.0, 5.0, -5.0, 5.0, mynear, myfar);//������ƽ��ͶӰ
//	viewxform_z = -5.0;
//	glMatrixMode(GL_MODELVIEW);//�л���ģ��-�۲����
//	glLoadIdentity();//����Ϊ��λ����
//}
//
///*----------------------------------------------------------------------*/
///*
//** Set state according to user interaction.
//*/
//
//// ����״̬ѡ��
//void userSettings(void)
//{
//	memset(axis, 0, sizeof(axis));	// axis����
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
//GLfloat vertices[][3] = {		// 8�����������
//	{-1.0,-1,-1.0}, {-1.0,-1,1.0}, {1.0,-1,1.0}, {1.0,-1,-1.0},
//	{-1.0,1,-1.0}, {-1.0,1,1.0}, {1.0,1,1.0}, {1.0,1,-1.0},
//	{0,pow(2,0.5) + 1,0},{0,-pow(2,0.5) - 1,0},
//{pow(2,0.5) + 1,0,0},
//{-pow(2,0.5) - 1,0,0},
//{0,0,pow(2,0.5) + 1},{0,0,-pow(2,0.5) - 1}
//};
//
//GLfloat colors[][3] = {			// 8���������ɫ -> ���� userSettings �����е� GL_SMOOTH / GL_FLAT ��������ɫ
//	{0.0,0.0,0.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
//	{0.0,0.0,1.0}, {1.0,0.0,1.0} ,{1.0,1.0,1.0}, {0.0,1.0,1.0},
//	{0.0,0.0,0.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
//	{0.0,0.0,1.0}, {1.0,0.0,1.0} ,{1.0,1.0,1.0}, {0.0,1.0,1.0},
//	{0.0,0.0,0.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
//	{0.0,0.0,1.0}, {1.0,0.0,1.0} ,{1.0,1.0,1.0}, {0.0,1.0,1.0}
//};
//
//// ����4���㻭1����
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
//// ����6����
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
//// ������ͶӰ��������ԭ��İ�����
//void trackball_ptov(int x, int y, int width, int height, float v[3])
//{
//	float d, a;
//
//	/* project x,y onto a hemi-sphere centered within width, height */
//	v[0] = (2.0F*x - width) / width;
//	v[1] = (height - 2.0F*y) / height;
//	d = (float)sqrt(v[0] * v[0] + v[1] * v[1]);
//	v[2] = (float)cos((M_PI / 2.0F) * ((d < 1.0F) ? d : 1.0F));
//	a = 1.0F / (float)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);	// ��һ��
//	v[0] *= a;
//	v[1] *= a;
//	v[2] *= a;
//}
//
//
//// ����ƶ�����
//void mouseMotion(int x, int y)
//{
//
//	if (!redrawContinue) return;
//	float curPos[3], dx, dy, dz; trackball_ptov(x, y, winWidth, winHeight, curPos);
//	if (rotateMove) {
//
//
//		//�������������λ��
//		dx = curPos[0] - lastPos[0];
//		dy = curPos[1] - lastPos[1];
//		dz = curPos[2] - lastPos[2];
//
//		if (dx || dy || dz) {
//			angle = 90.0F * sqrt(dx * dx + dy * dy + dz * dz);// ʹ��ת������dx��dy��dz���
//
//			axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];//YoZƽ����ת��������������ڸ���Ƶ�ʣ�ÿ�ζ���һ�����Σ�����Ϊ�뾶Ϊ1����ֵΪsin(alpha)
//			axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];	// �������ֶ���
//			axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];
//			// ��3�����ϵ���ת���� alpha : beta : gama = sin(alpha) : sin(beta) : sin(gama)
//			// ֻ�������ת�������ɣ�angle������ת����
//
//			lastPos[0] = curPos[0];
//			lastPos[1] = curPos[1];
//			lastPos[2] = curPos[2];
//		}
//	}
//	else if (translateMove) {
//		//����ƽ����
//
//		curx = x;
//		cury = y;
//		dx = x - lastx;
//		dy = y - lasty;
//
//		if (dx || dy) {
//			//axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];//YoZƽ����ת��������������ڸ���Ƶ�ʣ�ÿ�ζ���һ�����Σ�����Ϊ�뾶Ϊ1����ֵΪsin(alpha)
//			//axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];	// �������ֶ���
//			//axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];
//			axis[0] = 0.01*dx;
//			axis[1] = -0.01*dy;
//			axis[2] = 0;
//			lastx = curx;
//			lasty = cury;
//		}
//	}
//	else if (scaleMove) {
//		//��������
//		float k_scale = 2;		// ����ϵ�������ƿ���
//		curx = x;
//		cury = y;
//		dx = 2.0F*(curx - lastx) / winWidth * k_scale;
//		dy = 2.0F*(lasty - cury) / winHeight * k_scale;
//
//		if (dx || dy) {
//			axis[0] = 0.01*dx;//YoZƽ����ת��������������ڸ���Ƶ�ʣ�ÿ�ζ���һ�����Σ�����Ϊ�뾶Ϊ1����ֵΪsin(alpha)
//			axis[1] = 0.01*dy;	// �������ֶ���
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
//	switch (type)	// ����operatorType�л�������ʽ
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
//	// ��ӡ�任����
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
//// ��ʾ����
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
//		glPushMatrix();												// ����ǰ״̬ѹջ
//		glLoadIdentity();											// ��������
//		if (rotateMove) {
//			glRotatef(angle, axis[0], axis[1], axis[2]);//������תAPI 								
//			;// ��ת
//		}
//		else if (translateMove) {
//			glTranslatef(axis[0], axis[1], axis[2])//����ƽ��API glTranslate ()
//				;				// ƽ��
//		}
//		else if (scaleMove) {
//			glScalef(1 + axis[0], 1 + axis[1], 1 + axis[2])//��������API glScalef()
//				;		// ����
//		}
//		glMultMatrixf((GLfloat *)objectXform);//Ϊʲô				// �����ʼ״̬���ɲ�Ϊ��λ����
//		glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *)objectXform);	// ����������˻��洢������任���� objectXform
//		glPopMatrix();												// ��֮ǰ�����״̬��ջ
//	}
//	glPushMatrix();
//	glMultMatrixf((GLfloat *)objectXform);					// ���û�����ϵ����objectXform�任
//	colorcube();											
//	glPopMatrix();
//
//	glFlush();
//	glutSwapBuffers();										//
//
//}
//
///*----------------------------------------------------------------------*/
//// �����¼�
//
//void mouseButton(int button, int state, int x, int y)
//{
//	switch (button) {		// ���ԶԲ�ͬ��갴����ȡ��ͬ���ԣ��˴��������֣����Ҽ��Ѱ󶨲˵���
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
//	glViewport(0, 0, w, h);	// �����ӿڴ�С�ʹ���һ��
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
//		angle = 0;//����angleΪ0
//		axis[0] = 0; axis[1] = 0; axis[2] = 0;
//		memset(objectXform, 0, sizeof(objectXform));
//		for (int i = 0; i < 4; i++)
//		{
//			objectXform[i][i] = 1.0;
//		}
//		// axis����
//	// �任����objectXform����
//		break;
//	}
//	case 'r':
//	{		// ��ת
//	//	���ò�������Ϊ��ת
//		operatorType = 0;
//
//		break;
//	}
//	case 't':		// ƽ��
//	//	���ò�������Ϊƽ��
//
//		operatorType = 1;
//		break;
//	case 's':		// ����
//	//	���ò�������Ϊ����
//		operatorType = 2;
//		break;
//	case '1':				// wire frame/polygon   // �߿�ͼ/�����
//		drawLines = !drawLines;
//		break;
//	case '2':
//		smoothEnabled = !smoothEnabled;			// GL_SMOOTH / GL_FLAT
//		break;
//	case 27:		// ESC����ASCII: 27���˳�
//		exit(0);
//		break;
//	default:
//		break;
//	}
//	userSettings();	// ����û������Ƿ�ı�
//
//	glutPostRedisplay();	// �ػ�
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	userEventAction(key);			// ����ͨ�ö������ͺ���
//}
//
//// ��ͷ����
//void arrow(int key, int x, int y)
//{
//	startMotion(0, 1, x, y, operatorType); // ���ò����Ĳ���ֵ
//	angle = 10.0F;
//	switch (key)
//	{
//	case GLUT_KEY_LEFT:
//		if (rotateMove) {
//			axis[0] = 0;
//			axis[1] = 1;
//			axis[2] = 0;// ������Y������ת��axisֵ
//
//		}
//		else if (translateMove) {
//			axis[0] = -0.2;
//			axis[1] = 0;
//			axis[2] = 0;// ������Y������ת��axisֵ//����X����ƽ�Ƶ�axisֵ
//
//		}
//		else if (scaleMove) {
//			axis[0] = -0.2;
//			axis[1] = 0;
//			axis[2] = 0;//����x�������ŵ�axis��ֵ
//			;
//		}
//		break;
//	case GLUT_KEY_UP:
//		if (rotateMove) {	// ���� x ����ת
//			//  ������Y������ת��axisֵ
//			axis[0] = -1;
//			axis[1] = 0;
//			axis[2] = 0;;
//
//		}
//		else if (translateMove) {
//			//����Y����ƽ�Ƶ�axisֵ
//			axis[0] = 0;
//			axis[1] = 0.2;
//			axis[2] = 0;
//		}
//		else if (scaleMove) {
//			//����Y�������ŵ�axisֵ
//			axis[0] = 0;
//			axis[1] = 0.2;
//			axis[2] = 0;
//		}
//		break;
//	case GLUT_KEY_RIGHT:
//		if (rotateMove) {
//			axis[0] = 0;
//			axis[1] = -1;
//			axis[2] = 0;// ������Y������ת��axisֵ
//			;
//		}
//		else if (translateMove) {
//			//����X����ƽ�Ƶ�axisֵ
//			axis[0] = 0.2;
//			axis[1] = 0;
//			axis[2] = 0;
//		}
//		else if (scaleMove) {
//			//����x�������ŵ�axis��ֵ
//			axis[0] = 0.2;
//			axis[1] = 0;
//			axis[2] = 0;
//		}
//		break;
//	case GLUT_KEY_DOWN:
//		if (rotateMove) {
//			axis[0] = 1;
//			axis[1] = 0;
//			axis[2] = 0;// ������X������ת��axisֵ
//			;
//		}
//		else if (translateMove) {
//			//����Y����ƽ�Ƶ�axisֵ��
//			axis[0] = 0;
//			axis[1] = -0.2;
//			axis[2] = 0;
//		}
//		else if (scaleMove) {
//			//����Y�������ŵ�axisֵ
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
//// �˵���
//
//typedef struct menuEntryStruct {	// ��-ֵ�� ���ݽṹ
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
//	"quit", 			27,	//ESC����ASCII: 27��
//};
//int mainMenuEntries = sizeof(mainMenu) / sizeof(menuEntryStruct);
//
//void selectMain(int choice)			// ���->key ӳ��
//{
//	userEventAction(mainMenu[choice].key);		// ����ͨ�ö������ͺ���
//}
//
//void setMenuEntries()
//{
//	glutCreateMenu(selectMain);					// ʹ��selectMain��Ϊ�˵����ú���
//	for (int i = 0; i < mainMenuEntries; i++) {
//		glutAddMenuEntry(mainMenu[i].label, i);	// label��ʾ�ڲ˵����棬i����selectMain
//	}
//
//	glutAttachMenu(GLUT_RIGHT_BUTTON);			// �˵����Ҽ�
//}
//
///*----------------------------------------------------------------------*/
//// ������
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