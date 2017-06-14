/***************************************************
	�ļ����ƣ�ѧ������ϵͳ
	�ļ�����:��ѧ����Ϣ�Ĺ��� ����һ��ʹ�������ѧ�� 
	���뻷����devc
	����޸ģ�2017��2��12��
***************************************************/ 

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<windows.h>
using namespace std;
struct student{
	char name[20];
	char no[20];//��� 
	double math;
	double english;
	double c;
	double ave;
}stu[1000];
void menu();
void Continue();
void add();
void display();
void modify();
void Delete();
void sort();
void empty();
void search();
void read(int number);
void input(int number);

bool cmp(student a,student b)
{
	return a.ave>b.ave;
}

int main()
{
	system("color 9F");//�޸Ŀ���̨��ɫ
	menu();
	printf("�����һ��ʹ�ã�����ѡ����1���ѧ��\n");
	int n;
	printf("��������ţ�");
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
			case 0:exit(0);
			case 1:add();break;
			case 2:display();break;
			case 3:modify();break;
			case 4:Delete();break;
			case 5:sort();break;
			case 6:search();break;
			case 7:empty();break;
			default:
				printf("����������������룡\n");
				system("pause");
				system("cls");
				menu();
				printf("��������ţ�");
				break;
		}
	}
	return 0;
}

void menu()
{
	printf("\t\t\t*******************************************************************\n"); 
	printf("\t\t\t************************ѧ �� �� �� ϵ ͳ**************************\n");
	printf("\t\t\t*******************************************************************\n\n"); 
	printf("\t\t\t***************************��0�� �˳�����**************************\n");
	printf("\t\t\t***************************��1�� ���ѧ��**************************\n");
	printf("\t\t\t***************************��2�� ��ʾѧ��**************************\n");
	printf("\t\t\t***************************��3�� �޸�ѧ��**************************\n");
	printf("\t\t\t***************************��4�� ɾ��ѧ��**************************\n");
	printf("\t\t\t***************************��5�� �ɼ�����**************************\n");
	printf("\t\t\t***************************��6�� ����ѧ��**************************\n");
	printf("\t\t\t***************************��7�� �������**************************\n");
}

void Continue()
{
	system("pause"); 
	system("cls");
	menu();
	printf("���������:"); 
}

void read(int number)//���ļ��е�ѧ����Ϣ���������� 
{
	FILE *fp;
	fp=fopen("d:\\ѧ����Ϣ.txt","r+");
	for(int i=1;i<=number;i++)
	{
		fscanf(fp,"%s",stu[i].name);
		fscanf(fp,"%s",stu[i].no);
		fscanf(fp,"%lf",&stu[i].math);
		fscanf(fp,"%lf",&stu[i].english);
		fscanf(fp,"%lf",&stu[i].c);
	}
	fclose(fp);
} 

void input(int number)//�������ѧ����Ϣ��գ�����д�뵽�ļ� 
{
	FILE *fp;
	fp=fopen("d:\\ѧ����Ϣ.txt","w");
	for(int i=1;i<=number;i++)
	{
		fprintf(fp,"%20s",stu[i].name);
		fprintf(fp,"%20s",stu[i].no);
		fprintf(fp,"%15.0lf",stu[i].math);
		fprintf(fp,"%15.0lf",stu[i].english);
		fprintf(fp,"%15.0lf\n",stu[i].c);
	}
	fclose(fp);
}
void add()//���ѧ�� 
{
	system("cls");
	FILE *fp,*pa;
	int i=0,number,n=1;
	while(n==1)
	{
		printf("������ѧ��������\n");
		scanf("%s",stu[i].name);
		printf("������ѧ��ѧ��: \n");
		scanf("%s",stu[i].no);
		printf("������ѧ���ĸ����ɼ���\n");
		scanf("%lf",&stu[i].math);
		printf("������ѧ����Ӣ��ɼ���\n");
		scanf("%lf",&stu[i].english);
		printf("������ѧ����C���Գɼ���\n");
		scanf("%lf",&stu[i].c);
		
	if((pa=fopen("d:\\����.txt","r"))==NULL)	//��������ļ�������
	{
		pa=fopen("d:\\����.txt","w");				//����ѧ����Ϣ�ļ�
		number=0;									//������0
	}
	else   //���ļ�����                         
	{
		fscanf(pa,"%d",&number);					//���ȶ�������
	}
		fclose(pa);
		
		fp=fopen("d:\\ѧ����Ϣ.txt","a+");

		//����ӵ�ѧ��д���ļ� 
		fprintf(fp,"%20s",stu[i].name);
		fprintf(fp,"%20s",stu[i].no);
		fprintf(fp,"%15.0lf",stu[i].math);
		fprintf(fp,"%15.0lf",stu[i].english);
		fprintf(fp,"%15.0lf\n",stu[i].c);
		fclose(fp);
	
		i++;
		number++;
		pa=fopen("d:\\����.txt","w");//��ʱ��ԭ����������գ�����д�� 
		fprintf(pa,"%d",number);
		fclose(pa);
		
		printf("���Ҫ���������밴1�����������밴0��");
		scanf("%d",&n);
		if(n==0)   //�������� 
		{
			fclose(fp);
			system("cls"); 
			menu();
			printf("��������ţ�");
		}
	}
}

void display()//��ʾѧ��
{
	system("cls");
	char ch;
	FILE *fp;
	if((fp=fopen("d:\\ѧ����Ϣ.txt","r+"))==NULL)
	{
		printf("�ļ��򿪴�����ѧ����Ϣ��\n�������ѧ����\n");
		Continue(); 
		return;
	}
	int number=0;
	printf("ѧ����Ϣ���£�\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("%20s%20s%15s%15s%15s\n","����","ѧ��","����","Ӣ��","C����");
	while((ch=fgetc(fp))!=EOF)
		putchar(ch); 
	fclose(fp);
	fp=fopen("d:\\����.txt","r");
	fscanf(fp,"%d",&number);
	printf("-----------------------------------------------------------------------------\n");
	printf("ѧ������Ϊ: %d\n",number);
	printf("-----------------------------------------------------------------------------\n");
	Continue(); 
	
} 

void modify()//�޸���Ϣ 
{
	system("cls");
	FILE *fp;
	int i,number,flag;
	char str[20],name[20],no[20];
	double math,english,c; 
	fp=fopen("d:\\����.txt","r+");
	fscanf(fp,"%d",&number);
	fclose(fp);
	
	read(number);//���ļ�����ѧ����Ϣ
	while(1)
	{
		flag=0;
		printf("������Ҫ�޸ĵ�ѧ��������ѧ�ţ���0������:\n");
		scanf("%s",str);
		if(strcmp(str,"0")==0)  break;//��0�˳� 
		for(i=1;i<=number;i++)
		{
			if((strcmp(str,stu[i].name)==0)||(strcmp(str,stu[i].no)==0))
		    {
		    	flag=1;
		    	printf("�ҵ�����ѧ����Ϣ��\n");
		    	printf("-----------------------------------------------------------------------------\n");
				printf("%20s%20s%15s%15s%15s\n","����","ѧ��","�����ɼ�","Ӣ��ɼ�","C���Գɼ�");
				printf("%20s%20s%15.0lf%15.0lf%15.0lf\n",stu[i].name,stu[i].no,stu[i].math,stu[i].english,stu[i].c);
				printf("-----------------------------------------------------------------------------\n");
				break;
			}	
		}
		if(!flag)//û���ҵ�Ҫ�޸�ѧ��
			{
				printf("����������������ļ���û�д�ѧ������Ϣ��\n");
				printf("-----------------------------------------------------------------------------\n");
				continue;
			} 
		else
		{
			printf("�������޸ĺ�ѧ����������\n");
			scanf("%s",name);
			printf("�������޸ĺ�ѧ������ţ�\n");
			scanf("%s",no);
			printf("�������޸ĺ�ѧ���ĸ����ɼ���\n");
			scanf("%lf",&math);
			printf("�������޸ĺ�ѧ����Ӣ��ɼ���\n");
			scanf("%lf",&english);
			printf("�������޸ĺ�ѧ����C���Գɼ���\n");
			scanf("%lf",&c);
			
			strcpy(stu[i].name,name);
			strcpy(stu[i].no,no);
			stu[i].math=math;
			stu[i].english=english;
			stu[i].c=c;
			
			input(number);
		}	
	}
	if(flag)//�޸ĳɹ�	
	{ 
		printf("-----------------------------------------------------------------------------\n");
		printf("\tѧ����Ϣ�޸ĳɹ�\n");
	} 
	printf("-----------------------------------------------------------------------------\n");
	Continue();
}  

void Delete()//ɾ��ѧ��
{
	system("cls");
	FILE *fp,*fa;
	int i,n=1,number,flag,del=0;
	char str[20];
	fa=fopen("d:\\����.txt","r");//��ȡ���� 
	fscanf(fa,"%d",&number);
	fclose(fa);
	
	read(number);
	while(n==1)
	{ 
		flag=-1;
		printf("������Ҫɾ����ѧ��������ѧ��:\n");
		scanf("%s",str);
		for(i=1;i<=number;i++)
		{
			if((strcmp(str,stu[i].name)==0)||(strcmp(str,stu[i].no)==0))//����ҵ� 
			{
				flag=i;break;//�ҵ����˳�ѭ�� 
			}
			
		}
		if(flag==-1)//û���ҵ� 
		{
			printf("����������������ļ���û�д�ѧ������Ϣ��\n");
			printf("-----------------------------------------------------------------------------\n");
			break;
		} 			
		else
		{
			printf("��Ҫɾ����ѧ����Ϣ���£�\n");
			printf("%20s%20s%15s%15s%15s\n","����","ѧ��","�����ɼ�","Ӣ��ɼ�","C���Գɼ�");
			printf("%20s%20s%15.0lf%15.0lf%15.0lf\n",stu[flag].name,stu[flag].no,stu[flag].math,stu[flag].english,stu[flag].c);
			del++;
			for(int j=flag;j<=number;j++)
			{
				strcpy(stu[j].name,stu[j+1].name);
				strcpy(stu[j].no,stu[j+1].no);
				stu[i].math=stu[i+1].math;
				stu[i].english=stu[i+1].english;
				stu[i].c=stu[i+1].c;
			} 
			FILE *pb;
			pb=fopen("d:\\����.txt","r");//�Ȱ�ѧ������д��number 
			fscanf(pb,"%d",&number);
			fclose(pb);
			number-=del;//ɾ�����ѧ������ 
			pb=fopen("d:\\����.txt","w");//�ٴδ�ѧ��������ԭ����������գ�����д�� 
			fprintf(pb,"%d",number);
			fclose(pb);
			
			input(number);//���޸ĺ����Ϣ����д���ļ� 
		}	
		printf("���Ҫ����ɾ������ѧ����Ϣ�밴1������0��");
		scanf("%d",&n);
	}
	if(flag!=-1)//���ɾ���ɹ�	
	{ 
		printf("-----------------------------------------------------------------------------\n");
		printf("\tѧ����Ϣɾ���ɹ�\n");
		printf("-----------------------------------------------------------------------------\n");
	} 
	system("pause"); 
	system("cls");
	menu();
	printf("���������:"); 
} 

void sort()//ѧ������ 
{
	system("cls");
	FILE *fp;
	int number,i,j,k,t[1000]={0};
	fp=fopen("d:\\����.txt","r+");
	fscanf(fp,"%d",&number);
	fclose(fp);
	
	read(number); 
	printf("����ǰ�ĳɼ�Ϊ��\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("%20s%20s%15s%15s%15s%20s\n","����","ѧ��","����","Ӣ��","C����","ƽ���ɼ�");
	for(i=1;i<=number;i++)
	{
		t[i]=i;
		stu[i].ave=(stu[i].math+stu[i].english+stu[i].c)/3.0; 
		printf("%20s%20s%15.0lf%15.0lf%15.0lf%20.1lf\n",stu[i].name,stu[i].no,stu[i].math,stu[i].english,stu[i].c,stu[i].ave);
	}
	printf("-----------------------------------------------------------------------------\n");
	
	sort(stu+1,stu+number+1,cmp);//���� 

	printf("�����ĳɼ�Ϊ��\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("%20s%20s%15s%15s%15s%20s\n","����","ѧ��","����","Ӣ��","C����","ƽ���ɼ�");
	for(i=1;i<=number;i++)
		printf("%20s%20s%15.0lf%15.0lf%15.0lf%20.1lf\n",stu[i].name,stu[i].no,stu[i].math,
											stu[i].english,stu[i].c,stu[i].ave);
	printf("-----------------------------------------------------------------------------\n");
	Continue(); 
}

void empty()//������� 
{
	char str[100];
	printf("-----------------------------------------------------------------------------\n");
	printf("�����������ѧ����Ϣ��\nȷ�������� y,�������������ַ��������β�����");
	scanf("%s",str);
	if(strcmp(str,"y")==0)
	{
		FILE *fp;
		if((fp=fopen("d:\\ѧ����Ϣ.txt","w"))==NULL)
			printf("�ļ��򿪴���\n");
		fclose(fp);
		
		if((fp=fopen("d:\\����.txt","w"))==NULL)
			printf("�ļ��򿪴���\n");
		fclose(fp);
		
		printf("-----------------------------------------------------------------------------\n");
		printf("ɾ����ɣ�\n");	
	}
	else
	{
		printf("-----------------------------------------------------------------------------\n");
		printf("�����ѽ�����δ���и�ʽ����\n");
	}
	Continue(); 
	
}

void search()
{
	FILE *fp;
	char str[20];
	int number,i,flag;
	fp=fopen("d:\\����.txt","r+");//�ȶ���ѧ������number 
	fscanf(fp,"%d",&number);
	fclose(fp);
	
	read(number);
	while(1)
	{
		flag=0;
		printf("������Ҫ���ҵ�ѧ��������ѧ�ţ���0������:\n");
		scanf("%s",str);
		if(strcmp(str,"0")==0)  break;//��0�˳� 
		for(i=1;i<=number;i++)
		{
			if((strcmp(str,stu[i].name)==0)||(strcmp(str,stu[i].no)==0))//����ҵ� 
		    {
		    	flag=1;
		    	printf("�ҵ�����ѧ����Ϣ��\n");
		    	printf("-----------------------------------------------------------------------------\n");
				printf("%20s%20s%15s%15s%15s\n","����","ѧ��","����","Ӣ��","C����");
				printf("%20s%20s%15.0lf%15.0lf%15.0lf\n",stu[i].name,stu[i].no,stu[i].math,stu[i].english,stu[i].c);
				printf("-----------------------------------------------------------------------------\n");
			}	
		}
		if(!flag)//û�ҵ�
		{	
			printf("δ�ҵ�ѧ����Ϣ��\n");
			printf("-----------------------------------------------------------------------------\n");
			continue;
		} 
	}
	printf("-----------------------------------------------------------------------------\n");
	Continue(); 
}


