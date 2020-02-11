//#include <cstdio>
//#include <iostream>
//using namespace std;
//char a[20];
//int next1[20];
//void get_and_print_next()
//{
//	int len = strlen(a); int k;
//	next1[0] = -1; next1[1] = 0;
//	for (int i = 2; i < len; i++)
//	{
//		k = next1[i - 1];
//		if (a[i - 1] == a[k])
//		{
//			next1[i] = k + 1;
//		}
//		else
//		{
//			int h = k;
//			while (h != 0)
//			{
//				if (a[i - 1] == a[next1[h]])
//				{
//					next1[i] = next1[h] + 1;
//					break;
//				}
//				else
//				{
//					h = next1[h];
//				}
//			}
//		}
//		
//	}
//for (int i = 0; i < len; i++)
//		{
//			cout << next1[i] << ' ';
//		}
//}
//int main()
//{
//	
//	while (1)
//	{
//		cin >> a;
//		get_and_print_next();
//		cout << endl;
//	}
//
//}