#ifndef LIST
#define LIST
#include <cstdio>
#include <iostream>
using namespace std;
#define MAX_SIZE 100
typedef enum Status
{
	success, fail, fatal, rangeerror
	//不需要分号
}Status;
typedef struct Splist {
	int *element;
	int length;
	int MaxSize;
}Sqlist, *Listptr;
//初始化列表
class MyList
{
private:
	Sqlist list;
public:
	Status init(int n);//n指的是元素个数
	/*Status destroy(Listptr L);*/
	Status insert(int num);
	Status remove(int pos);//都是指的下标
	Status retrieve(int pos,int *num);
	Status Locate(int num,int *pos);
	Status clear();
	bool empty();
	int length();
	Status myprint();
	Status mybubblesort();
	~MyList();
};
Status MyList::init(int n)
{
	Status status = fatal;
	list.MaxSize = MAX_SIZE-1;//指的是下角标
	list.length = 0;
	list.element = new int[MAX_SIZE];
	if (list.element)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> list.element[i];
		}
		list.length = n;
		status = success;
	}
		return status;
}
MyList::~MyList()
{
	delete[] list.element;
}
Status MyList::insert(int num)
{
	Status status = rangeerror;
	if (list.length <= list.MaxSize)
	{
		list.element[list.length] = num;
		list.length++;
		status = success;
	}
	return status;
}
Status MyList::remove(int pos)
{
	Status status = rangeerror;
	if (pos < list.length&&pos >= 0)
	{
		for (int i = pos; i < list.length - 1; i++)
		{
			list.element[i] = list.element[i + 1];
		}
		--list.length;
		status = success;
	}
	return status;
}
Status MyList::retrieve(int pos,int *num)
{
	Status status = rangeerror;
	if (pos <list.length&&pos>=0)
	{
		*num = list.element[pos];
		status = success;
	}
	return status;
}

Status MyList::Locate(int num, int *pos)
{
	Status status = fail;
	int i = 0;
	while (i < list.length)
	{
		if (list.element[i] != num)
			i++;
		else
		{
			*pos = i;
			status = success;
			break;
		}
	}
	return status;
	
}
Status MyList::clear()
{
	list.length = 0;
  return success;
}

bool MyList::empty()
{
	if (list.length == 0)
	{
		return true;
	}
	return false;
}
int MyList::length()
{
	return list.length;
}
Status MyList::myprint()
{

	Status status = fail;
	if (list.length)
	{
		for (int i = 0; i < list.length; i++)
		{
			cout << list.element[i] << " "; 
		}
	}
	return status;
}
Status MyList::mybubblesort()
{
	Status status =success;
	if (list.length > 1)
	{
		int temp;
		for (int i = 0; i < list.length - 1; i++)
		{
			for (int j = 0; j < list.length -1- i; j++)
			{
				if (list.element[j] > list.element[j + 1])
				{
					temp = list.element[j];
					list.element[j] = list.element[j + 1];
					list.element[j + 1] = temp;
				}
			}
		}
	}
	return status;
}
#endif // !LIST