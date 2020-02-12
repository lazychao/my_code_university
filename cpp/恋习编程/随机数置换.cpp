//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//const double CLOCKS_PER_MILLISECOND = ((clock_t)1);
//void Swap(int *a, int *b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void RandomPermutation1(int n)
//{
//	clock_t t1 = clock();
//	if (n <= 0)
//	{
//		cout << "error";
//		return;
//	}
//	int *nums = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		nums[i] = rand()%n+1;
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[j] == nums[i])
//			{
//				i--;
//				break;
//			}
//		}
//	}
//	clock_t t2 = clock();
//	/*for (int i = 0; i < n; i++)
//	{
//		cout << nums[i] << ',';
//	}*/
//	/*cout << '0' << endl;*/
//	cout << double(t2 - t1) / CLOCKS_PER_MILLISECOND;
//}
//
//void RandomPermutation2(int n)
//{
//	clock_t t1 = clock();
//	
//	if (n <= 0)
//	{
//		cout << "error";
//		return;
//	}
//	int *nums = new int[n];
//	int *used = new int[n];
//	memset(used, 0, sizeof(used));
//	for (int i = 0; i < n; i++)
//	{
//		nums[i] = rand() % n + 1;
//		if (used[nums[i]] == 1)
//		{
//			i--;
//		}
//		else
//		{
//			used[nums[i]] = 1;
//		}
//
//	}
//	clock_t t2 = clock();
//	/*for (int i = 0; i < n; i++)
//	{
//		cout << nums[i] << ',';
//	}*/
//	/*cout << '0' << endl;*/
//	cout << double(t2 - t1) / CLOCKS_PER_MILLISECOND;
//}
//void RandomPermutation3(int n)
//{
//	clock_t t1 = clock();
//	if (n <= 0)
//	{
//		cout << "error";
//		return;
//	}
//	int *A=new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		A[i] = i + 1;
//	}
//	for (int i = 1; i < n; i++)
//		Swap(&A[i], &A[rand()%i+1]);
//	clock_t t2 = clock();
//	///*for (int i = 0; i < n; i++)
//	//{
//	//	cout << A[i] << ',';
//	//}*/
//	///*cout << '0' << endl;*/
//	cout << double(t2 - t1) / CLOCKS_PER_MILLISECOND;
//	
//
//	/*int *nums = new int[n];
//
//	for (int i = 0; i < n; i++) {
//
//		nums[i] = i+1;
//
//	}
//
//	int x = 0, tmp = 0;
//
//	for (int i = n-1; i > 0; i--) {
//
//		x = rand()%(i+2);
//
//		tmp = nums[i];
//
//		nums[i] = nums[x];
//
//		nums[x] = tmp;
//
//	}
//
//	
//	for (int i = 0; i < n; i++)
//	{
//		cout << nums[i] << ',';
//	}
//	
//*/
//
//
//}
//int main()
//{
//	int n;
//	cin >> n;
//	RandomPermutation1(n);
//	cout << endl;
//	RandomPermutation2(n);
//	cout << endl;
//	RandomPermutation3(n);
//	cout << endl;
//}