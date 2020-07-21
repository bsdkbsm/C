#include <stdio.h>
#define NUMBER 10
void add(void);
struct aryNewType//aryNewType结构体用于存放信息 
{
	char m_name[20];
	char m_age[4];
	char m_sex[4];
}information[NUMBER];
char space=' ';//用于文件存入信息分隔 
int main()
{
	int choose;
	while(1)
	{
		printf("==============\n");
		printf("1.信息存入\n");
		printf("2.退出\n");
		printf("==============\n");
		scanf("%d",&choose);
		if(choose<1||choose>1)
			break;
		switch(choose)
		{
			case 1:add();break;
		}
	}
	printf("Bye");
}
void add(void)
{
	char choose;
	FILE* f_text_1;//建立文件指针 
	//f_text_1=fopen("E:\\C语言\\C语言程序\\测试&&学习\\text.txt","a+");//指向文件，a+表示追加 
	f_text_1=fopen("F:\\C\\信息管理\\text.txt","a+");
	while(1)
	{
		printf("输入姓名：");
		scanf("%s",information[iNum].m_name);
		fputs(information[iNum].m_name,f_text_1);//将输入的信息存入文件 
		fputs(&space,f_text_1);
		printf("输入年龄：");
		scanf("%s",information[iNum].m_age);
		fputs(information[iNum].m_age,f_text_1);
		fputs(&space,f_text_1);
		printf("输入性别：");
		scanf("%s",information[iNum].m_sex,f_text_1);
		getchar();
		fputs(information[iNum].m_sex,f_text_1);
		fputs(&space,f_text_1);
		fclose(f_text_1);//关闭后缓冲区间信息存入文件 
		//fflush(information[iNum].m_sex);
	//	printf("=%d",strlen(information[iNum].m_name));
	 	printf("已存入,是否继续存入Y/N?\n");
		scanf("%c",&choose);
		if(choose!='Y'&&choose!='y')
		 	break;
		iNum++; 
	}
}
