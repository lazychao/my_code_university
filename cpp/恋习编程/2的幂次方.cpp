//#include<cstdio>
//#include<iostream>
////��һ�����Ĳ�����������2���ݴη������Ӷ����ƽǶ�����
//using namespace std;
//int getbit(int n,int i)
//{
//	return (n >> i) & 1;
//}
//void exp(int n)
//{
//	bool flag = false;
//	for (int i = 15; i >= 0; i--)
//	{
//		if (getbit(n, i))
//		{
//			if (flag)
//			{
//				cout << '+';
//			}
//			else
//			{
//				flag = true;//ΪʲôҪ����һ��flag ��   ʹ�õ�һ�ν���ѭ��ʱ��д�Ӻ�
//			}
//			if (i == 0)
//			{
//				cout << "2(0)";
//			}
//			else if (i == 1)
//			{
//				cout << 2;
//			}
//			else
//			{
//				cout << 2;
//				cout << '(';
//				exp(i);
//				cout << ')';
//			}
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	exp(n);
//}