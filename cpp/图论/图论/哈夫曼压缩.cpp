#include <cstdio>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
typedef struct node {
	int w;
	struct node *lt, *rt;
	char c;
}node,*nodeptr;
int type_nums;//统计字符种类数量  字符只有一种的情况编码方式会有所不同

int counts[28];
int char_nums;//目的是先将要存储的字符数量先统计起来
char char_only;
struct cmp{
	bool operator () (nodeptr  a, nodeptr b)//重载小于号
			//对象之间无法直接比较 想要 在对象之间加小于号就要重载小于号的功能  
	{
		return a->w > b->w;
	}
};


priority_queue <nodeptr,vector<nodeptr>,cmp> q;
char codes[28][30];
vector <char> a;


void Huffuman_codes(nodeptr p)//采用先序遍历哈夫曼树的方式获得哈夫曼编码
{
	if (!p)return;
	if (p->lt == NULL && p->rt == NULL)
	{
		int i = 0;
		int x;
		if (p->c == '\n')
			x = 26;
		else if (p->c == ' ')
			x = 27;
		else
			x = p->c - 'a';
		for (; i < a.size(); i++)
		{
			codes[x][i] = a[i];
		}
		codes[x][i] = '\0';
		
		cout <<p->c<<' '<< codes[x] << endl;
		return;
	}
	else
	{
		a.push_back('0');
		Huffuman_codes(p->lt);
		a.pop_back();
		a.push_back('1');
		Huffuman_codes(p->rt);
		a.pop_back();
	}
}
int get_bit(char value, int index)
{
	return (value >> index & 1);//取出index位上的数
}
void setbit(char n, int index, char& value)//把一个字节的‘1’变成变成了一位，，这里要引用不然会出问题
{
	if (n == '1')
	{
		value |= (1 << index);
	}
	else
	{
		value &= ~(1 << index);//很重要的去反
	}
}
int main()
{
	FILE *fp1,*fp2,*fp3;//分别是打开原文本文件 编码后的二进制文件 译码之后的文本文件
	fp1 = fopen("C://Users//Dell//Desktop//source.txt", "r+");
	while (!fp1)
	{
		fp1 = fopen("C://Users//Dell//Desktop//source.txt", "r+");
	}
	//统计
	//创建节点
	//构建哈夫曼树
	char c;
	while (!feof(fp1))
	{
		
		c = fgetc(fp1);
		/*cout << c;*/
		if (c == -1)break;
		char_nums++;
		if (c == '\n')
		{
			counts[26] += 1; 
		}
		else if (c == ' ')
		{
			counts[27] += 1; 
		}
		else {
			counts[c - 'a'] += 1; 
		}
		if (c != -1)char_only = c;
		
	}
	if (char_nums == 0){
		cout << "源文件为空！";
		return 0;
	}
	for (int i = 0; i < 28; i++)
	{
		if (counts[i] != 0)
		{
			type_nums++;
		}
	}
	
	/*cout << endl;*/
	for (int i = 0; i < 28; i++)
	{
		nodeptr p=new node;
		p->w = counts[i];
		/*cout << p.w << endl;*/
		p->lt = NULL;
		p->rt = NULL;
		if (i < 26)
			p->c = 'a' + i;
		else if (i == 26)
			p->c = '\n';
		else
			p->c = ' ';
		q.push(p);
	}
	/*cout << q.size();*/
	nodeptr temp1, temp2;
	//下面为建立哈夫曼树
	nodeptr root;
	if (type_nums == 1)//只you一种字符
	{
		root = new node;
		nodeptr p = new node;
		p->c = char_only;
		root->lt = p;
		root->rt = NULL;
		p->lt = NULL;
		p->rt = NULL;
	}
	else
	{
		for (int i = 1; i < 28; i++)
		{
			temp1 = q.top(); q.pop();
			/*cout << temp1->w << endl;
			*/
			temp2 = q.top(); q.pop();/*cout << temp2->w << endl;*/
			nodeptr p = new node;
			p->w = temp1->w + temp2->w;
			/*cout << p.w << endl;*/
			p->lt = temp1;
			p->rt = temp2;
			p->c = '*';
			q.push(p);
		}
		root = q.top();
	}
	
	Huffuman_codes(root);//建树完成后  进行编码
	
	rewind(fp1);//把文件指针放到开头、
	
	fp2 = fopen("C://Users//Dell//Desktop//encoding.bin", "wb+");
	int len, Char_index; char value; int Count = 0;
	while (!feof(fp1))
	{
		c = fgetc(fp1);
		//先求出对应的哈夫曼编码长度 然后一位一位的写进去
		if (c == '\n')
		{
			len = strlen(codes[26]);
			Char_index = 26;
		}
		else if (c == ' ')
		{
			len = strlen(codes[27]);
			Char_index = 27;
		}
		else
		{
			len = strlen(codes[c - 'a']);
			Char_index = c - 'a';
		}
		for (int i = 0; i < len; i++)
		{
			if(Count<8)
			setbit(codes[Char_index][i], Count++, value);
			else
			{
				//已经写好8位了 那就存入文件中
				fwrite(&value, sizeof(char), 1, fp2);

				Count = 0;//再赋为0
				setbit(codes[Char_index][i], Count++, value);//这里还要写 不然白循环一次
			}
		}
	}
	//最后几位没有满8位补全8位
	if (Count < 8)
	{
		while (Count < 8) setbit('0', Count++, value);//如何解决这最后几位的垃圾信息
		fwrite(&value, sizeof(char), 1, fp2);
	}

	//压缩完成后  解压缩
	fp3 = fopen("C://Users//Dell//Desktop//decoding.txt","w+");
	if (!fp3)return 0;
	rewind(fp2);

	int bit; Count = 0; nodeptr p=root;
    fread(&value, sizeof(char), 1, fp2);//每次读一个字节
	while (!feof(fp2))
	{
		if(Count<8)
		bit = get_bit(value, Count++);
		else
		{
			if (!feof(fp2))
			{
				fread(&value, sizeof(bool), 1, fp2);
				Count = 0;
				bit = get_bit(value, Count++);
			}
		}
		if (bit == 1)
		{
			p=p->rt;
			if (p->c != '*')
			{
				char_nums--;
				if (char_nums == -1)
				{
					break;//所有的字符都已解压缩，就不在读取，这样子就可以避免读取最后几位无效
					//的编码
				}
				/*cout << p->c << endl;*/
				fwrite(&(p->c), sizeof(char), 1, fp3);
				p = root;
			}
		}
		else if (bit == 0)
		{
			p = p->lt;
			if (p->c != '*')
			{
				char_nums--;
				if (char_nums == -1)
				{
					break;//所有的字符都已解压缩，就不在读取，这样子就可以避免读取最后几位无效
					//的编码
				}
				/*cout << p->c << endl;*/
				fwrite(&(p->c), sizeof(char), 1, fp3);
				p = root;
			}
		}

	}


	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
