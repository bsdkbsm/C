#include <stdio.h>
#define NUMBER 10
void add(void);
struct aryNewType//aryNewType�ṹ�����ڴ����Ϣ 
{
	char m_name[20];
	char m_age[4];
	char m_sex[4];
}information[NUMBER];
char space=' ';//�����ļ�������Ϣ�ָ� 
int main()
{
	int choose;
	while(1)
	{
		printf("==============\n");
		printf("1.��Ϣ����\n");
		printf("2.�˳�\n");
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
	FILE* f_text_1;//�����ļ�ָ�� 
	//f_text_1=fopen("E:\\C����\\C���Գ���\\����&&ѧϰ\\text.txt","a+");//ָ���ļ���a+��ʾ׷�� 
	f_text_1=fopen("F:\\C\\��Ϣ����\\text.txt","a+");
	while(1)
	{
		printf("����������");
		scanf("%s",information[iNum].m_name);
		fputs(information[iNum].m_name,f_text_1);//���������Ϣ�����ļ� 
		fputs(&space,f_text_1);
		printf("�������䣺");
		scanf("%s",information[iNum].m_age);
		fputs(information[iNum].m_age,f_text_1);
		fputs(&space,f_text_1);
		printf("�����Ա�");
		scanf("%s",information[iNum].m_sex,f_text_1);
		getchar();
		fputs(information[iNum].m_sex,f_text_1);
		fputs(&space,f_text_1);
		fclose(f_text_1);//�رպ󻺳�������Ϣ�����ļ� 
		//fflush(information[iNum].m_sex);
	//	printf("=%d",strlen(information[iNum].m_name));
	 	printf("�Ѵ���,�Ƿ��������Y/N?\n");
		scanf("%c",&choose);
		if(choose!='Y'&&choose!='y')
		 	break;
		iNum++; 
	}
}
