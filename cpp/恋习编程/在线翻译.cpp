//#include <cstdio>
//#include <algorithm>
//#include <iostream>
//#include <cstring>
//int i;
//using namespace std;
//struct entry
//{
//	char eng[10];
//	char fore[10];
//}entries[10];
//void search(char *words)
//{
//	int left = 0;
//	int right = i-1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		int a = strcmp(entries[mid].fore, words);
//		if (a > 0)
//		{
//			right = mid - 1;
//		}
//		else if (a < 0)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("%s\n", entries[mid].eng);
//			return;
//		}
//	}
//	printf("en\n");
//}
//bool cmp(entry a,entry b)
//{
//	return strcmp(a.fore, b.fore)<0;
//}
//int main()
//{
//	
//	char words[10];
//	while (true)
//	{
//		scanf("%s%s", entries[i].eng, entries[i].fore);
//		i++;
//		cin.get();
//		if (cin.peek() == '\n')
//		{
//			break;
//		}
//	}
//	sort(entries, entries + i, cmp);
//	while (scanf("%s", words) != EOF)
//	{
//		search(words);
//	}
//
//}