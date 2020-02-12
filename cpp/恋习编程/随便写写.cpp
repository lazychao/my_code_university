//#include <iostream>
//#include <cstdio>
//using namespace std;
//void expand(const char *s, char *t)
//{ int j = 0;
//	for (int i = 0; s[i] != '\0'; i++)
//		switch (s[i]) {
//		case'\n': t[j++] = '\\';
//				t[j++] = 'n';
//				break;
//		case'\t': t[j++] = '\\';
//					t[j++] = 't';
//					break;
//				default: t[j++] = s[i];
//					break;
//		}
//	t[j] ='\0';
//}
//int main()
//{
//	const char *a = "asdjk\n";
//	char *b = new char[10];
//	expand(a, b);
//	while (*b != '\0')
//	{
//		cout << *b;
//		b++;
//	}
//}
