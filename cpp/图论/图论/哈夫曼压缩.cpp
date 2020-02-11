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
int type_nums;//ͳ���ַ���������  �ַ�ֻ��һ�ֵ�������뷽ʽ��������ͬ

int counts[28];
int char_nums;//Ŀ�����Ƚ�Ҫ�洢���ַ�������ͳ������
char char_only;
struct cmp{
	bool operator () (nodeptr  a, nodeptr b)//����С�ں�
			//����֮���޷�ֱ�ӱȽ� ��Ҫ �ڶ���֮���С�ںž�Ҫ����С�ںŵĹ���  
	{
		return a->w > b->w;
	}
};


priority_queue <nodeptr,vector<nodeptr>,cmp> q;
char codes[28][30];
vector <char> a;


void Huffuman_codes(nodeptr p)//��������������������ķ�ʽ��ù���������
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
	return (value >> index & 1);//ȡ��indexλ�ϵ���
}
void setbit(char n, int index, char& value)//��һ���ֽڵġ�1����ɱ����һλ��������Ҫ���ò�Ȼ�������
{
	if (n == '1')
	{
		value |= (1 << index);
	}
	else
	{
		value &= ~(1 << index);//����Ҫ��ȥ��
	}
}
int main()
{
	FILE *fp1,*fp2,*fp3;//�ֱ��Ǵ�ԭ�ı��ļ� �����Ķ������ļ� ����֮����ı��ļ�
	fp1 = fopen("C://Users//Dell//Desktop//source.txt", "r+");
	while (!fp1)
	{
		fp1 = fopen("C://Users//Dell//Desktop//source.txt", "r+");
	}
	//ͳ��
	//�����ڵ�
	//������������
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
		cout << "Դ�ļ�Ϊ�գ�";
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
	//����Ϊ������������
	nodeptr root;
	if (type_nums == 1)//ֻyouһ���ַ�
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
	
	Huffuman_codes(root);//������ɺ�  ���б���
	
	rewind(fp1);//���ļ�ָ��ŵ���ͷ��
	
	fp2 = fopen("C://Users//Dell//Desktop//encoding.bin", "wb+");
	int len, Char_index; char value; int Count = 0;
	while (!feof(fp1))
	{
		c = fgetc(fp1);
		//�������Ӧ�Ĺ��������볤�� Ȼ��һλһλ��д��ȥ
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
				//�Ѿ�д��8λ�� �Ǿʹ����ļ���
				fwrite(&value, sizeof(char), 1, fp2);

				Count = 0;//�ٸ�Ϊ0
				setbit(codes[Char_index][i], Count++, value);//���ﻹҪд ��Ȼ��ѭ��һ��
			}
		}
	}
	//���λû����8λ��ȫ8λ
	if (Count < 8)
	{
		while (Count < 8) setbit('0', Count++, value);//��ν�������λ��������Ϣ
		fwrite(&value, sizeof(char), 1, fp2);
	}

	//ѹ����ɺ�  ��ѹ��
	fp3 = fopen("C://Users//Dell//Desktop//decoding.txt","w+");
	if (!fp3)return 0;
	rewind(fp2);

	int bit; Count = 0; nodeptr p=root;
    fread(&value, sizeof(char), 1, fp2);//ÿ�ζ�һ���ֽ�
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
					break;//���е��ַ����ѽ�ѹ�����Ͳ��ڶ�ȡ�������ӾͿ��Ա����ȡ���λ��Ч
					//�ı���
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
					break;//���е��ַ����ѽ�ѹ�����Ͳ��ڶ�ȡ�������ӾͿ��Ա����ȡ���λ��Ч
					//�ı���
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
