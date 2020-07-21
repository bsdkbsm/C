#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
#define NUMBER 10
void add(void);
void query(void);
void clean(void);
int iNum = 0;
struct aryNewType//存放信息 
{
	char m_name[20];
	char m_age[4];
	char m_sex[4];
}information[NUMBER];
char str[100];//用于信息查询从文件中读取信息 
char space = ' ';//用于文件内存入信息分隔 
int main()
{
	int choose;
	while (1)
	{
		printf("==============\n");
		printf("1.信息存入\n");
		printf("2.信息查询\n");
		printf("3.清空内容\n");
		printf("4.退出\n");
		printf("==============\n");
		scanf("%d", &choose);
		if (choose < 1 || choose>3)
			break;
		switch (choose)
		{
		case 1:add(); break;
		case 2:query(); break;
		case 3:clean(); break;
		}
	}
	printf("Bye");
	//gets(str);
	//fputs(str,f_text);		//将str数组中的字符存入到文件指针所指向的文件 
	//rewind(f_text);			//指向文件头 
	//fgets(str_2,NUMBER,f_text);		//从文件指针中获取N-1个字符存入到数组中 
	//fclose(f_text);		//关闭正在使用的文件，防止缓冲区数据丢失 
	//printf("%s",str_2);
}
void add(void)
{
	char choose;
	FILE* f_text_1;//建立文件指针 
	//f_text_1=fopen("E:\\C语言\\C语言程序\\测试&&学习\\text.txt","a+");//指向文件，a+表示追加 
	f_text_1 = fopen("H:\\C\\信息管理\\text.txt", "a+");
	while (1)
	{
		printf("输入姓名：");
		scanf("%s", information[iNum].m_name);
		fputs(information[iNum].m_name, f_text_1);//将输入的信息存入文件 
		fputs(&space, f_text_1);//向文件中添加一个空白字符，用于数据分隔 
		printf("输入年龄：");
		scanf("%s", information[iNum].m_age);
		fputs(information[iNum].m_age, f_text_1);
		fputs(&space, f_text_1);
		printf("输入性别：");
		scanf("%s", information[iNum].m_sex);
		fputs(information[iNum].m_sex, f_text_1);
		fputs(&space, f_text_1);
		fclose(f_text_1);//关闭后缓冲区间信息存入文件 
		//fflush(information[iNum].m_sex);
	//	printf("=%d",strlen(information[iNum].m_name));
		getchar();
		printf("已存入,是否继续存入Y/N?\n");
		scanf("%c", &choose);
		if (choose != 'Y' && choose != 'y')
			break;
		iNum++;
	}
}
void query(void)
{
	int num = 0;
	FILE* f_text_1;
	char ch;
	//f_text_1=fopen("E:\\C语言\\C语言程序\\测试&&学习\\text.txt","a+");
	f_text_1 = fopen("H:\\C\\信息管理\\text.txt", "a+");
	if ((ch = getc(f_text_1)) == EOF)//检测当前是否为文件尾 
		printf("文件内未有信息，需存入 ！\n");
	fseek(f_text_1, -1L, SEEK_CUR);//从当前位置回退1个字节，检测已读取1个字节 
	while ((ch = getc(f_text_1)) != EOF)
	{
		fseek(f_text_1, -1L, SEEK_CUR);//从当前位置回退1个字节 ，SEEK_CUR代表当前位置 
		printf("============\n");
		printf("编号:%d\n", num + 1);
		fscanf(f_text_1, "%s", str);//从文件中读取一个字符串，遇到空白字符停止 
		printf("姓名:%s\n", str);
		fscanf(f_text_1, "%s", str);
		printf("年龄:%s\n", str);
		fscanf(f_text_1, "%s", str);
		printf("性别:%s\n", str);
		printf("============\n");
		num++;
		getc(f_text_1);//去除当前信息末尾的空格，便于后续判断
	}
}
void clean(void)
{
	FILE* f_text_1;
	f_text_1 = fopen("H:\\C\\信息管理\\text.txt", "w+");
	printf("已清除\n");
	//以W开头的形式会清空文件中所有内容 
}
