#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 
#define NUMBER 10
void add(void);
void query(void);
void clean(void);
int iNum = 0;
struct aryNewType//�����Ϣ 
{
	char m_name[20];
	char m_age[4];
	char m_sex[4];
}information[NUMBER];
char str[100];//������Ϣ��ѯ���ļ��ж�ȡ��Ϣ 
char space = ' ';//�����ļ��ڴ�����Ϣ�ָ� 
int main()
{
	int choose;
	while (1)
	{
		printf("==============\n");
		printf("1.��Ϣ����\n");
		printf("2.��Ϣ��ѯ\n");
		printf("3.�������\n");
		printf("4.�˳�\n");
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
	//fputs(str,f_text);		//��str�����е��ַ����뵽�ļ�ָ����ָ����ļ� 
	//rewind(f_text);			//ָ���ļ�ͷ 
	//fgets(str_2,NUMBER,f_text);		//���ļ�ָ���л�ȡN-1���ַ����뵽������ 
	//fclose(f_text);		//�ر�����ʹ�õ��ļ�����ֹ���������ݶ�ʧ 
	//printf("%s",str_2);
}
void add(void)
{
	char choose;
	FILE* f_text_1;//�����ļ�ָ�� 
	//f_text_1=fopen("E:\\C����\\C���Գ���\\����&&ѧϰ\\text.txt","a+");//ָ���ļ���a+��ʾ׷�� 
	f_text_1 = fopen("H:\\C\\��Ϣ����\\text.txt", "a+");
	while (1)
	{
		printf("����������");
		scanf("%s", information[iNum].m_name);
		fputs(information[iNum].m_name, f_text_1);//���������Ϣ�����ļ� 
		fputs(&space, f_text_1);//���ļ������һ���հ��ַ����������ݷָ� 
		printf("�������䣺");
		scanf("%s", information[iNum].m_age);
		fputs(information[iNum].m_age, f_text_1);
		fputs(&space, f_text_1);
		printf("�����Ա�");
		scanf("%s", information[iNum].m_sex);
		fputs(information[iNum].m_sex, f_text_1);
		fputs(&space, f_text_1);
		fclose(f_text_1);//�رպ󻺳�������Ϣ�����ļ� 
		//fflush(information[iNum].m_sex);
	//	printf("=%d",strlen(information[iNum].m_name));
		getchar();
		printf("�Ѵ���,�Ƿ��������Y/N?\n");
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
	//f_text_1=fopen("E:\\C����\\C���Գ���\\����&&ѧϰ\\text.txt","a+");
	f_text_1 = fopen("H:\\C\\��Ϣ����\\text.txt", "a+");
	if ((ch = getc(f_text_1)) == EOF)//��⵱ǰ�Ƿ�Ϊ�ļ�β 
		printf("�ļ���δ����Ϣ������� ��\n");
	fseek(f_text_1, -1L, SEEK_CUR);//�ӵ�ǰλ�û���1���ֽڣ�����Ѷ�ȡ1���ֽ� 
	while ((ch = getc(f_text_1)) != EOF)
	{
		fseek(f_text_1, -1L, SEEK_CUR);//�ӵ�ǰλ�û���1���ֽ� ��SEEK_CUR����ǰλ�� 
		printf("============\n");
		printf("���:%d\n", num + 1);
		fscanf(f_text_1, "%s", str);//���ļ��ж�ȡһ���ַ����������հ��ַ�ֹͣ 
		printf("����:%s\n", str);
		fscanf(f_text_1, "%s", str);
		printf("����:%s\n", str);
		fscanf(f_text_1, "%s", str);
		printf("�Ա�:%s\n", str);
		printf("============\n");
		num++;
		getc(f_text_1);//ȥ����ǰ��Ϣĩβ�Ŀո񣬱��ں����ж�
	}
}
void clean(void)
{
	FILE* f_text_1;
	f_text_1 = fopen("H:\\C\\��Ϣ����\\text.txt", "w+");
	printf("�����\n");
	//��W��ͷ����ʽ������ļ����������� 
}
