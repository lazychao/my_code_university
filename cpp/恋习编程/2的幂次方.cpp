//#include<cstdio>
//#include<iostream>
////求一个数的不超过该数的2的幂次方，，从二进制角度来看
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
//				flag = true;//为什么要设置一个flag 呢   使得第一次进入循环时不写加号
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