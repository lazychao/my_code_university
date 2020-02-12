#include <cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define inf 0x7f7f7f7f
int dp[101][101];
int path[101][101];
//����������ȱ������·��
void recursion(int i, int j)
{
	if (i==j)
	{
		cout << i;
		return;
	}
	else
	{
		recursion(i, path[i][j]);
		cout <<"->"<< j;
	}
}
int main()
{
	int n,m;
	cout << "��������и���n:"; cin >> n;
	while (n > 100) {
		cout << "n���Ϊ100������������";
		cin >> n;
	}
	while (n <=0 ) {
		cout << "����������";
		cin >> n;
	}
	cout<< "��������·����m:"; cin >> m; 
	while (m <= 0) {
		cout << "����������";
		cin >> m;
	}
	int tempx, tempy, tempw;
	//��ʼ���� ���㵽�������̾���Ϊ0 �������ľ����ʼΪ����
	for (int i = 1; i <=n; i++)
	{
		for (int j =1; j <= n; j++)
		{
			if (i == j)
			{
				dp[i][j] = 0;
				path[i][j] = i;
			}
			else
				dp[i][j] = inf;
		}
	}
	//�洢��
	for (int i = 0; i < m; i++)
	{
		cin >> tempx >> tempy >> tempw;
		dp[tempx][tempy] = tempw;
		path[tempx][tempy] = tempx;
	}
	//����ΪFLoyd�㷨
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <=n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (dp[i][k] + dp[k][j] < dp[i][j])
				{
					dp[i][j] = dp[i][k] + dp[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	//���·��
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] != inf)
			{
				if (i != j)
				{
					cout << i << "���е�" << j << "���е���С����Ϊ" << dp[i][j] << endl;
					cout << "·��Ϊ��";
					recursion(i, j);
					cout << endl;
				}
			}
			else
			{
				cout << i << "�����޷�����" << j <<"����"<< endl;
			}
		}
	}
}