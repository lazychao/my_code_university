//#include<iostream>
//#include <cstdio>
//#include <cstring>
//#include<cmath>
//#include <ctype.h>
//using namespace std;
//int main()
//{
//	/*
//	�����ַ�  ��дСд*	
//	���ĸ���
//	����˳��
//˼�룺ÿ�ζ��������ж��Ƿ���-  ���Ǿ�ֱ�����   �Ǿ��ж�i-1��i-+1s
//�ǲ���ͬΪ��ĸ������  �Ǿͽ���ѭ��  ѭ��������p2���� ѭ����ʼ������p3���� �����
//��p1����*/
//	int p1, p2, p3;
//	cin >> p1 >> p2 >> p3;
//	char s[101];
//	cin >> s;
//	int len = strlen(s);
//	for (int i = 0; i < len; i++)
//	{
//		if (s[i] != '-'||(s[i]=='-'&&i==0))
//		{
//			cout << s[i];
//			continue;
//		}
//		if (isdigit(s[i - 1])*isdigit(s[i + 1]))
//		{
//			if (s[i + 1] <= s[i - 1])
//			{
//				cout << s[i] << s[i + 1];
//				i++;
//			}
//			else if (s[i + 1] - s[i - 1]==1)
//			{
//				cout << s[i + 1];
//				i++;
//			}
//			else
//			{
//				if (p1 != 3)
//				{
//					int begin, end;
//					begin = (p3 == 1) ? s[i - 1] + 1 : s[i + 1] - 1;
//					end = (p3 == 1) ? s[i + 1] : s[i - 1];
//					int flag = (p3 == 1) ? 1 : -1;
//					for (int j = begin; j != end; j += flag)
//					{
//
//						for (int k = 0; k < p2; k++)
//						{
//							cout << char(j);
//						}
//
//
//					}
//					cout << s[i + 1];
//				}
//				else
//				{
//					int len = s[i + 1] - s[i - 1] - 1;
//					len *= p2;
//					for (int i = 0; i < len; i++)
//					{
//						cout << '*';
//					}
//					cout << s[i + 1];
//				}
//				i++;
//			}
//		}
//		else if (isalpha(s[i - 1])*isalpha(s[i + 1]))
//		{
//
//			if (s[i + 1] <= s[i - 1]||(isupper(s[i-1])^isupper(s[i+1])!=0))
//			{
//				cout << s[i] << s[i + 1];
//				i++;
//			}
//			else if (s[i + 1] - s[i - 1] == 1)
//			{
//				cout << s[i + 1];
//				i++;
//			}
//			else
//			{
//				if (p1 != 3)
//				{
//					if (p1 == 1)
//					{
//						int begin, end;
//						begin = (p3 == 1) ? s[i - 1] + 1 : s[i + 1] - 1;
//						end = (p3 == 1) ? s[i + 1] : s[i - 1];
//						int flag = (p3 == 1) ? 1 : -1;
//						for (int j = begin; j != end; j += flag)
//						{
//
//							for (int k = 0; k < p2; k++)
//							{
//								cout << char(tolower(char(j)));
//							}
//
//
//						}
//						cout << s[i + 1];
//					}
//					else
//					{
//						if (p1 == 2)
//						{
//							int begin, end;
//							begin = (p3 == 1) ? s[i - 1] + 1 : s[i + 1] - 1;
//							end = (p3 == 1) ? s[i + 1] : s[i - 1];
//							int flag = (p3 == 1) ? 1 : -1;
//							for (int j = begin; j != end; j += flag)
//							{
//
//								for (int k = 0; k < p2; k++)
//								{
//									cout << char(toupper(char(j)));
//								}
//
//
//							}
//							cout << s[i + 1];
//						}
//					}
//				}
//				else
//				{
//					int len = s[i + 1] - s[i - 1] - 1;
//					len *= p2;
//					for (int i = 0; i < len; i++)
//					{
//						cout << '*';
//					}
//					cout << s[i + 1];
//				}
//				i++;
//			}
//		}
//		else
//		{
//			cout << s[i] << s[i + 1];
//			i++;
//		}
//	}
//
//}