//#include<cstdio>
//#include<iostream>
//#include<queue>
//using namespace std;
//int main()
//{
//	int n, m, k;//ʣ��m����k��ȥ��һ��
//	queue<int> q;
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++)
//	{
//		q.push(i);
//	}
//	int temp;
//	for (int i = 0; i < n - m; i++)
//	{
//		for (int j = 0; j < k-1; j++)//ǰk-1���������ȳ����У��ټ������
//		{
//			temp = q.front();
//			q.pop();
//			q.push(temp);
//		}
//		q.pop();
//	}
//	while (!q.empty())
//	{
//		cout << q.front() << ' ';
//		q.pop();
//	}
//}