//#include<iostream>
//#include<string>
//using namespace std;
//char a[7];
//int flag[7];
////不是这题的代码
//void dfs(string s, int len,int cur)
//{
//	if (cur == len)
//	{
//		for (int i = 0; i < len; i++)
//		{
//			cout << a[i];
//		}
//		cout << endl;
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < len; i++)
//		{
//			if (!flag[i])
//			{
//				a[cur] = s[i];
//				flag[i] = 1;
//				dfs(s, len, cur + 1);
//				flag[i] = 0;
//			}
//		}
//	}
//}
//int main()
//{
//	string s;
//	getline(cin, s);
//	dfs(s, s.size(),0);
//
//}