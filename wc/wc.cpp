#include<fstream>
#include<cstdlib>
#include<iostream>
#include<stdio.h>

#define _CRT_SECURE_NO_WARNINGS


using namespace std;

void CharCount(char path[]);
void WordCount(char path[]);
void LineCount(char path[]);
//void Muiltiple(char path[]);

int main()
{
	ofstream printf_path("path.txt");
	if (printf_path.is_open())
	{
		printf_path << "This is first line" << endl;
		printf_path << "This is second line" << endl;
		printf_path << "This is third line";
		printf_path.close();
	}

	char buffer[50];
	cout << "������Ҫ��ѯ���ļ���";
	cin >> buffer;
	char chance[3];                    //���ֻ��chance[2]�����-c֮���û���ڴ��'/0'�����¶�ջ��������stack around the variable was corrupted
	char y_or_n = 'y';
	while (y_or_n == 'y')
	{
		cout << "��ѯ�ַ���-c����ѯ������-w����ѯ����-l��";
		cin >> chance;
		if (strcmp(chance, "-c") == 0)
		{
			CharCount(buffer);
		}
		else if (strcmp(chance, "-w") == 0)
		{
			WordCount(buffer);
		}
		else if (strcmp(chance, "-l") == 0)
		{
			LineCount(buffer);
		}
		else
		{
			cout << "input error" << endl;
		}
		cout << "������ѯ�밴y������n��";
		cin >> y_or_n;
		if (y_or_n == 'n')
		{
			exit(0);
		}
	}

	//fstream out;
	//char c;
	//int count = 0;
	//out.open("path.txt",ios::in);
	//cout << "path.txt���������£�" << endl;
	//while (!out.eof())
	//{
	//	out >> c;
	//	//cout << c;
	//	count++;
	//	/*out.getline(buffer, 256);
	//	cout << buffer << endl;*/
	//}
	//cout << endl;
	//count--;
	//cout << "char count is:" << count << endl;
	//out.close();
	
	system("pause");
	return 0;
}

void CharCount(char path[])
{
	FILE *fp = NULL;          //�ļ�ָ��
	int c = 0;                //����
	char ch;                  //��ȡ�ַ�
	char *path_1 = path;
	if ((fp = fopen(path_1, "r")) == NULL)      //��ֻ���ļ�path_1
	{
		cout << "file read failure!" << endl;
		exit(0);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == ' ' || ch == '\n')
		{
			ch = fgetc(fp);
		}
		else
		{
			c++;
			ch = fgetc(fp);          //fgetc�Ƕ�ȡ�ַ�������fgets�Ƕ�ȡ�ַ�������
		}
	}
	cout << "char count is:" << c << endl;
	c--;
	fclose(fp);
}

void WordCount(char path[])
{
	FILE *fp;
	int w = 0;
	char ch;
	char *path_2 = path;
	if ((fp = fopen(path_2, "r")) == NULL)
	{
		cout << "file read failure!" << endl;
		exit(0);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
			|| (ch >= '0' && ch <= '9'))
		{
			while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
				|| (ch >= '0' && ch <= '9') || ch == '_')
			{
				ch = fgetc(fp);
			}                                           //����ȡ�������ַ�ʱѭ��ֱ�����ַ���w��ʼ���������ԭ���ǿ��ַ�����������
			w++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	cout << "word count is:" << w << endl;
	fclose(fp);
}

void LineCount(char path[])
{
	FILE *fp;
	int l = 1;
	char ch;
	char *path_3 = path;
	if ((fp = fopen(path_3, "r")) == NULL)
	{
		cout << "file read failure!" << endl;
		exit(0);
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n')
		{
			l++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}
	cout << "line count is:" << l << endl;
	fclose(fp);
}