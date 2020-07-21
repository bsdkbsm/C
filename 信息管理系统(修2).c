#include <stdio.h>
#define NUMBER 10
void add(void);
void query(void);
int iNum=0;
struct aryNewType//aryNewType结构体用于存放信息 
{
	char m_name[20];
	char m_age[4];
	char m_sex[4];
}information[NUMBER];
char str[100];//用于信息查询从文件中读取信息 
char space=' ';//用于文件内存入信息分隔 
int main()
{
//	FILE* f_text;
//	f_text=fopen("F:\\text\\text.txt","a+");
	int choose;
	while(1)
	{
		printf("==============\n");
		printf("1.信息存入\n");
		printf("2.信息查询\n");
		printf("3.退出\n");
		printf("==============\n");
		scanf("%d",&choose);
		if(choose<1||choose>2)
			break;
		switch(choose)
		{
			case 1:add();break;
			case 2:query();break;
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
void query(void)
{
	int num=0;
	FILE* f_text_1;
	char ch;
	//f_text_1=fopen("E:\\C语言\\C语言程序\\测试&&学习\\text.txt","a+");
	f_text_1=fopen("F:\\C\\信息管理\\text.txt","a+");
//	if((ch=getc(f_text_1))!=EOF)
	//	printf("文件内未有信息，需存入 ！\n"); 
	while((ch=getc(f_text_1))!=EOF)
	{
		//rewind(f_text_1);
		fseek(f_text_1,-1,SEEK_CUR);
		printf("============\n");
	 	printf("编号:%d\n",num+1);
		fscanf(f_text_1,"%s",str);
		printf("姓名:%s\n",str);
		fscanf(f_text_1,"%s",str);
		printf("年龄:%s\n",str);
		fscanf(f_text_1,"%s",str);
		printf("性别:%s\n",str);
		printf("============\n"); 
	//	getc(f_text_1);
	//	fclose(f_text_1);
		num++;
	}
}
