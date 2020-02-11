//#include<cstdio>
//#include<iostream>
//#include<queue>
//using namespace std;
//int main()
//{
//	int n, m, k;//剩余m个，k个去除一个
//	queue<int> q;
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++)
//	{
//		q.push(i);
//	}
//	int temp;
//	for (int i = 0; i < n - m; i++)
//	{
//		for (int j = 0; j < k-1; j++)//前k-1个数都是先出队列，再加入队列
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