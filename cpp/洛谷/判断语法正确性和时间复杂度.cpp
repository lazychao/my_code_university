//#include <cstdio>
//#include <stack>
//#include<iostream>
//#include<vector>
//using namespace std;
//char a[101][4];
//stack<char> s;
//vector<char> vars;
//int isvalid(int m)
//{
//	s = stack<char>();//清空队列
//	s.push(a[0][0]); if (a[0][0]==int('F')) vars.push_back(a[0][1]);
//	for (int i = 1; i < m; i++)
//	{
//		if (s.empty()||a[i][0] == s.top())
//		{
//			s.push(a[i][0]);
//			if (a[i][0] == int('F'))
//			{
//				for (int j = 0; j < vars.size(); j++)
//				{
//					if (vars[j] == a[i][1])
//					{
//						return 0;
//					}
//				}
//				vars.push_back(a[i][1]);
//			}
//		}
//		else
//		{
//			s.pop();
//			vars.pop_back();
//		}
//	}
//	if (s.empty())
//	
//		return 1;
//	
//	else
//		return 0;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int m;
//	char s[10];
//	const char *s1 = "O(n^w)";
//	const char *s2 = "O(1)";
//	int a[101][4];//难点如何存储一个可能是字符可能是数字的数据
//	for (int i = 0; i < n; i++)
//	{
//		cin >> m;//行数
//		cin >> s;
//		char temp;
//		for (int j = 0; j < m; j++)
//		{
//			cin >> temp;
//			a[j][0] = int(temp);
//			if (a[j][0] == int('F'))
//			{
//				for (int k = 1; k < 4; k++)
//				{
//					cin >> temp;
//					if (isdigit(temp))
//					{
//						while (cin.peek() != ' '&&cin.peek() != '\n')
//						{
//							temp = int(temp);
//							temp = temp * 10 + int(cin.get());
//							a[j][k] = temp;
//						}
//					}
//					else
//					a[j][k]=int(temp);
//				}
//			}
//		}
//		if (isvalid(m))
//		{
//			cout << "YES";
//		}
//		else
//		{
//			cout << "ERR";
//		}
//
//	}
//}