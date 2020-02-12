//#include <cstdio>
//#include <iostream>
//using namespace std;
//double factor_value();
//double term_value();
//double expression_value();
//int main()
//{
//	cout << expression_value();
//}
//double factor_value()
//{
//	double result = 0;
//	if (cin.peek() == '(')
//	{
//		cin.get();//要先把左括号取走，不然就死循环了
//		return expression_value();
//			cin.get();
//	}
//	else
//	{
//		char c;
//		c = cin.peek();
//		while (isdigit(c))
//		{
//			
//			result = result * 10 + c-'0';//将字符串数字变成真正的数字
//			cin.get();
//			c = cin.peek();
//		}
//	}
//	return result;
//}
//double term_value()
//{
//	double result = 0;
//	result += factor_value();
//	
//	while (1)
//	{
//		if (cin.peek() != '*'&&cin.peek() != '/')
//		{
//			break;
//		}
//		else
//		{
//			if (cin.peek() == '*')
//			{
//				cin.get();
//				result *= factor_value();
//			}
//			else
//			{
//				if (factor_value() != 0)
//				{
//					cin.get();
//					result /= factor_value();
//				}
//			}
//		}
//	}
//	return result;
//}
//double expression_value()
//{
//	double result = 0;
//	result+=term_value();
//	while (1)
//	{
//		if (cin.peek() != '+'&&cin.peek() != '-')
//		{
//			break;
//		}
//		else
//		{
//			if (cin.peek() == '+')
//			{
//				cin.get();
//				result += term_value();
//			}
//			else
//			{
//				cin.get();
//				result -= term_value();
//			}
//		}
//		
//	}
//	return result;
//}
