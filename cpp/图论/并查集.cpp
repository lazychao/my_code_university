//#include<cstdio>
//#include<iostream>
//using namespace std;
//int pre[1000];//ÿ�����Ӧ���ϴ󣬲�һ���ǰ�������ϣ���Ż��ɰ���(·��ѹ����
//int findboss(int me)
//{
//	int boss;
//	int temp=me;//������, me���ܱ�
//	while (temp != pre[temp])//��������  ֱ��boss�����Լ�
//	{
//		temp = pre[temp];
//	}
//	boss = temp;//boss�����Ա�
//
//	//·��ѹ��
//	temp = me;
//	int temp2;//�ݴ�ԭ������һ��
//	while (temp != pre[temp])
//	{
//		temp2 = pre[temp];
//		pre[temp] = boss;
//		temp = temp2;
//	}
//	//·��ѹ�� ��ÿһ����pre����Ϊboss
//	return boss;
//}
//int main()
//{
//	int n,m;
//	cout << "��������:"; cin >> n;
//	int num=n;//��������  һ��ʼ��n��
//	for (int i = 1; i <= n; i++)
//	{
//		pre[i] = i;//�ʼÿ���˶��Լ����Լ��ϴ�
//	}
//	//��ʼ���   �൱�����������������ɱ�
//	cout << "�������ݴ�����"; cin >> m;
//	int x, y;//������Ҫ���  �����������ɺϲ�
//	int boss1, boss2;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> x >> y;
//		boss1=findboss(x);
//		boss2 = findboss(y);
//		if (boss1 != boss2)
//		{
//			pre[boss1] = boss2;//����һ��boss����һ��Ϊboss
//			num--;//��һ������
//		}
//		cout << "����" << num << "������" << endl;
//	}
//	
//}